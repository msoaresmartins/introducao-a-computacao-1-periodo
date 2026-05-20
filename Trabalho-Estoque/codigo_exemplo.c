#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MAX_PRODUTOS 100
#define TAM_NOME 60
#define TAM_CATEGORIA 40
#define TAM_MARCA 40
#define TAM_LOCAL 20
#define TAM_LOTE 30
#define TAM_FORNECEDOR 60
#define DIAS_ALERTA_VALIDADE 7

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int codigo;
    char nome[TAM_NOME];
    char categoria[TAM_CATEGORIA];
    char marca[TAM_MARCA];
    float preco;
    int quantidade;
    int estoqueMinimo;
    Data validade;

    char corredor[TAM_LOCAL];
    char prateleira[TAM_LOCAL];
    char lote[TAM_LOTE];
    char fornecedor[TAM_FORNECEDOR];

    int totalVendido;
    int totalPerdido;
    float valorPerdido;
} Produto;

Produto produtos[MAX_PRODUTOS];
int totalProdutos = 0;

void removerQuebraLinha(char texto[]) {
    texto[strcspn(texto, "\n")] = '\0';
}

void lerLinha(const char mensagem[], char destino[], int tamanho) {
    printf("%s", mensagem);

    if (fgets(destino, tamanho, stdin) == NULL) {
        printf("Erro de leitura. Encerrando.\n");
        exit(1);
    }

    removerQuebraLinha(destino);
}

int lerInteiro(const char mensagem[], int minimo, int maximo) {
    char linha[100];
    char *fim;
    long valor;

    while (1) {
        printf("%s", mensagem);

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            printf("Erro de leitura. Encerrando.\n");
            exit(1);
        }

        removerQuebraLinha(linha);

        valor = strtol(linha, &fim, 10);

        if (fim == linha || *fim != '\0') {
            printf("Entrada invalida. Digite um numero inteiro.\n");
            continue;
        }

        if (valor < minimo || valor > maximo) {
            printf("Valor fora do intervalo permitido (%d a %d).\n", minimo, maximo);
            continue;
        }

        return (int) valor;
    }
}

float lerFloat(const char mensagem[], float minimo) {
    char linha[100];
    char *fim;
    float valor;
    int i;

    while (1) {
        printf("%s", mensagem);

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            printf("Erro de leitura. Encerrando.\n");
            exit(1);
        }

        removerQuebraLinha(linha);

        for (i = 0; linha[i] != '\0'; i++) {
            if (linha[i] == ',') {
                linha[i] = '.';
            }
        }

        valor = strtof(linha, &fim);

        if (fim == linha || *fim != '\0') {
            printf("Entrada invalida. Digite um numero real. Exemplo: 12.50\n");
            continue;
        }

        if (valor < minimo) {
            printf("Valor invalido. Digite um valor maior ou igual a %.2f.\n", minimo);
            continue;
        }

        return valor;
    }
}

int ehBissexto(int ano) {
    return (ano % 400 == 0) || (ano % 4 == 0 && ano % 100 != 0);
}

int diasDoMes(int mes, int ano) {
    switch (mes) {
        case 1: return 31;
        case 2: return ehBissexto(ano) ? 29 : 28;
        case 3: return 31;
        case 4: return 30;
        case 5: return 31;
        case 6: return 30;
        case 7: return 31;
        case 8: return 31;
        case 9: return 30;
        case 10: return 31;
        case 11: return 30;
        case 12: return 31;
        default: return 0;
    }
}

int dataValida(Data data) {
    if (data.ano < 1900 || data.ano > 2100) return 0;
    if (data.mes < 1 || data.mes > 12) return 0;
    if (data.dia < 1 || data.dia > diasDoMes(data.mes, data.ano)) return 0;

    return 1;
}

Data lerData(const char mensagem[]) {
    char linha[100];
    char extra;
    Data data;

    while (1) {
        printf("%s", mensagem);

        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            printf("Erro de leitura. Encerrando.\n");
            exit(1);
        }

        removerQuebraLinha(linha);

        if (sscanf(linha, "%d/%d/%d%c", &data.dia, &data.mes, &data.ano, &extra) != 3) {
            printf("Data invalida. Use o formato DD/MM/AAAA.\n");
            continue;
        }

        if (!dataValida(data)) {
            printf("Data inexistente. Tente novamente.\n");
            continue;
        }

        return data;
    }
}

Data obterDataAtual() {
    time_t agora = time(NULL);
    struct tm *info = localtime(&agora);
    Data hoje;

    hoje.dia = info->tm_mday;
    hoje.mes = info->tm_mon + 1;
    hoje.ano = info->tm_year + 1900;

    return hoje;
}

time_t dataParaTimeT(Data data) {
    struct tm tempo;

    memset(&tempo, 0, sizeof(tempo));

    tempo.tm_mday = data.dia;
    tempo.tm_mon = data.mes - 1;
    tempo.tm_year = data.ano - 1900;
    tempo.tm_hour = 0;
    tempo.tm_min = 0;
    tempo.tm_sec = 0;
    tempo.tm_isdst = -1;

    return mktime(&tempo);
}

int compararDatas(Data a, Data b) {
    if (a.ano != b.ano) return a.ano - b.ano;
    if (a.mes != b.mes) return a.mes - b.mes;

    return a.dia - b.dia;
}

int diferencaDias(Data inicio, Data fim) {
    time_t tInicio = dataParaTimeT(inicio);
    time_t tFim = dataParaTimeT(fim);
    double diferenca = difftime(tFim, tInicio) / 86400.0;

    if (diferenca >= 0) {
        return (int)(diferenca + 0.5);
    }

    return (int)(diferenca - 0.5);
}

int produtoVencido(Produto produto) {
    Data hoje = obterDataAtual();

    return compararDatas(produto.validade, hoje) < 0;
}

int produtoProximoDoVencimento(Produto produto, int diasAlerta) {
    Data hoje = obterDataAtual();
    int dias = diferencaDias(hoje, produto.validade);

    return dias >= 0 && dias <= diasAlerta;
}

void pausar() {
    char linha[10];

    printf("\nPressione ENTER para continuar...");
    fgets(linha, sizeof(linha), stdin);
}

void imprimirData(Data data) {
    printf("%02d/%02d/%04d", data.dia, data.mes, data.ano);
}

int contemIgnoreCase(const char texto[], const char busca[]) {
    int i, j;
    int tamTexto = (int) strlen(texto);
    int tamBusca = (int) strlen(busca);

    if (tamBusca == 0) return 1;
    if (tamBusca > tamTexto) return 0;

    for (i = 0; i <= tamTexto - tamBusca; i++) {
        for (j = 0; j < tamBusca; j++) {
            char c1 = (char) tolower((unsigned char) texto[i + j]);
            char c2 = (char) tolower((unsigned char) busca[j]);

            if (c1 != c2) break;
        }

        if (j == tamBusca) return 1;
    }

    return 0;
}

int buscarIndicePorCodigo(int codigo) {
    int i;

    for (i = 0; i < totalProdutos; i++) {
        if (produtos[i].codigo == codigo) {
            return i;
        }
    }

    return -1;
}

void imprimirCabecalhoTabela() {
    printf("%-8s %-22s %-15s %-12s %-8s %-6s %-8s %-12s %-10s\n",
           "Codigo", "Nome", "Categoria", "Marca", "Preco", "Qtd", "Minimo", "Validade", "Status");

    printf("-------------------------------------------------------------------------------------------------------------\n");
}

void imprimirLinhaProduto(Produto produto) {
    char status[20];

    if (produtoVencido(produto)) {
        strcpy(status, "Vencido");
    } else if (produto.quantidade <= produto.estoqueMinimo) {
        strcpy(status, "Baixo");
    } else if (produtoProximoDoVencimento(produto, DIAS_ALERTA_VALIDADE)) {
        strcpy(status, "Vence logo");
    } else {
        strcpy(status, "OK");
    }

    printf("%-8d %-22.22s %-15.15s %-12.12s R$%-6.2f %-6d %-8d ",
           produto.codigo,
           produto.nome,
           produto.categoria,
           produto.marca,
           produto.preco,
           produto.quantidade,
           produto.estoqueMinimo);

    imprimirData(produto.validade);

    printf(" %-10s\n", status);
}

void imprimirProdutoCompleto(Produto produto) {
    int diasParaVencer = diferencaDias(obterDataAtual(), produto.validade);

    printf("\n================ PRODUTO ================\n");
    printf("Codigo: %d\n", produto.codigo);
    printf("Nome: %s\n", produto.nome);
    printf("Categoria: %s\n", produto.categoria);
    printf("Marca: %s\n", produto.marca);
    printf("Preco unitario: R$ %.2f\n", produto.preco);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
    printf("Estoque minimo: %d\n", produto.estoqueMinimo);

    printf("Validade: ");
    imprimirData(produto.validade);
    printf("\n");

    if (produtoVencido(produto)) {
        printf("Situacao de validade: VENCIDO - bloqueado para venda.\n");
    } else if (produtoProximoDoVencimento(produto, DIAS_ALERTA_VALIDADE)) {
        printf("Situacao de validade: proximo do vencimento (%d dia(s)).\n", diasParaVencer);
    } else {
        printf("Situacao de validade: dentro do prazo.\n");
    }

    printf("Corredor: %s\n", produto.corredor);
    printf("Prateleira: %s\n", produto.prateleira);
    printf("Lote: %s\n", produto.lote);
    printf("Fornecedor: %s\n", produto.fornecedor);
    printf("Total vendido: %d\n", produto.totalVendido);
    printf("Total perdido/desperdicado: %d\n", produto.totalPerdido);
    printf("Valor perdido/desperdicado: R$ %.2f\n", produto.valorPerdido);
    printf("Valor atual em estoque deste produto: R$ %.2f\n", produto.preco * produto.quantidade);
    printf("=========================================\n");
}

void cadastrarProduto() {
    Produto novo;
    int codigo;

    if (totalProdutos >= MAX_PRODUTOS) {
        printf("Limite maximo de produtos atingido.\n");
        return;
    }

    printf("\n=== CADASTRO DE PRODUTO ===\n");

    while (1) {
        codigo = lerInteiro("Codigo do produto: ", 1, 999999999);

        if (buscarIndicePorCodigo(codigo) == -1) {
            novo.codigo = codigo;
            break;
        }

        printf("Ja existe um produto com esse codigo. Use outro codigo.\n");
    }

    lerLinha("Nome: ", novo.nome, TAM_NOME);
    lerLinha("Categoria: ", novo.categoria, TAM_CATEGORIA);
    lerLinha("Marca: ", novo.marca, TAM_MARCA);

    novo.preco = lerFloat("Preco unitario: R$ ", 0.0f);
    novo.quantidade = lerInteiro("Quantidade inicial: ", 0, 1000000);
    novo.estoqueMinimo = lerInteiro("Estoque minimo: ", 0, 1000000);
    novo.validade = lerData("Data de validade (DD/MM/AAAA): ");

    lerLinha("Corredor: ", novo.corredor, TAM_LOCAL);
    lerLinha("Prateleira: ", novo.prateleira, TAM_LOCAL);
    lerLinha("Lote: ", novo.lote, TAM_LOTE);
    lerLinha("Fornecedor: ", novo.fornecedor, TAM_FORNECEDOR);

    novo.totalVendido = 0;
    novo.totalPerdido = 0;
    novo.valorPerdido = 0.0f;

    produtos[totalProdutos] = novo;
    totalProdutos++;

    printf("\nProduto cadastrado com sucesso.\n");
}

void listarProdutos() {
    int i;

    printf("\n=== LISTA DE PRODUTOS ===\n");

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    imprimirCabecalhoTabela();

    for (i = 0; i < totalProdutos; i++) {
        imprimirLinhaProduto(produtos[i]);
    }
}

void buscarProduto() {
    int opcao, codigo, indice, i, encontrou = 0;
    char termo[80];

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("\n=== BUSCAR PRODUTO ===\n");
    printf("1 - Buscar por codigo\n");
    printf("2 - Buscar por nome\n");
    printf("3 - Buscar por categoria\n");

    opcao = lerInteiro("Escolha: ", 1, 3);

    if (opcao == 1) {
        codigo = lerInteiro("Codigo: ", 1, 999999999);
        indice = buscarIndicePorCodigo(codigo);

        if (indice == -1) {
            printf("Produto nao encontrado.\n");
        } else {
            imprimirProdutoCompleto(produtos[indice]);
        }

        return;
    }

    if (opcao == 2) {
        lerLinha("Nome ou parte do nome: ", termo, sizeof(termo));
    } else {
        lerLinha("Categoria ou parte da categoria: ", termo, sizeof(termo));
    }

    imprimirCabecalhoTabela();

    for (i = 0; i < totalProdutos; i++) {
        if ((opcao == 2 && contemIgnoreCase(produtos[i].nome, termo)) ||
            (opcao == 3 && contemIgnoreCase(produtos[i].categoria, termo))) {
            imprimirLinhaProduto(produtos[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum produto encontrado.\n");
    }
}

void adicionarEstoque() {
    int codigo, indice, quantidade;

    printf("\n=== ADICIONAR ESTOQUE ===\n");

    codigo = lerInteiro("Codigo do produto: ", 1, 999999999);
    indice = buscarIndicePorCodigo(codigo);

    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    quantidade = lerInteiro("Quantidade a adicionar: ", 1, 1000000);
    produtos[indice].quantidade += quantidade;

    printf("Estoque atualizado. Nova quantidade: %d\n", produtos[indice].quantidade);
}

void venderProduto() {
    int codigo, indice, quantidade;

    printf("\n=== VENDER / REMOVER POR VENDA ===\n");

    codigo = lerInteiro("Codigo do produto: ", 1, 999999999);
    indice = buscarIndicePorCodigo(codigo);

    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    if (produtoVencido(produtos[indice])) {
        printf("Venda bloqueada: o produto esta vencido.\n");
        printf("Use a opcao de perdas/desperdicios caso ele precise ser descartado.\n");
        return;
    }

    quantidade = lerInteiro("Quantidade vendida/removida: ", 1, 1000000);

    if (quantidade > produtos[indice].quantidade) {
        printf("Operacao negada: nao ha estoque suficiente.\n");
        printf("Quantidade atual: %d\n", produtos[indice].quantidade);
        return;
    }

    produtos[indice].quantidade -= quantidade;
    produtos[indice].totalVendido += quantidade;

    printf("Venda registrada com sucesso. Nova quantidade: %d\n", produtos[indice].quantidade);

    if (produtos[indice].quantidade <= produtos[indice].estoqueMinimo) {
        printf("Alerta: produto abaixo ou igual ao estoque minimo.\n");
    }
}

void removerEstoqueSemVenda() {
    int codigo, indice, quantidade;

    printf("\n=== REMOVER ESTOQUE SEM VENDA ===\n");
    printf("Use esta opcao para ajustes manuais, erros de contagem ou retirada interna.\n");

    codigo = lerInteiro("Codigo do produto: ", 1, 999999999);
    indice = buscarIndicePorCodigo(codigo);

    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    quantidade = lerInteiro("Quantidade a remover: ", 1, 1000000);

    if (quantidade > produtos[indice].quantidade) {
        printf("Operacao negada: nao ha estoque suficiente.\n");
        printf("Quantidade atual: %d\n", produtos[indice].quantidade);
        return;
    }

    produtos[indice].quantidade -= quantidade;

    printf("Estoque removido. Nova quantidade: %d\n", produtos[indice].quantidade);
}

void atualizarQuantidade() {
    int codigo, indice, novaQuantidade;

    printf("\n=== ATUALIZAR QUANTIDADE ===\n");

    codigo = lerInteiro("Codigo do produto: ", 1, 999999999);
    indice = buscarIndicePorCodigo(codigo);

    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    novaQuantidade = lerInteiro("Nova quantidade: ", 0, 1000000);
    produtos[indice].quantidade = novaQuantidade;

    printf("Quantidade atualizada com sucesso.\n");
}

void verificarDisponibilidade() {
    int codigo, indice;

    printf("\n=== VERIFICAR DISPONIBILIDADE ===\n");

    codigo = lerInteiro("Codigo do produto: ", 1, 999999999);
    indice = buscarIndicePorCodigo(codigo);

    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    imprimirProdutoCompleto(produtos[indice]);

    if (produtoVencido(produtos[indice])) {
        printf("Resultado: produto existe, mas esta vencido e bloqueado para venda.\n");
    } else if (produtos[indice].quantidade > 0) {
        printf("Resultado: produto disponivel para venda.\n");
    } else {
        printf("Resultado: produto esgotado.\n");
    }
}

void alterarEstoqueMinimo() {
    int codigo, indice, novoMinimo;

    printf("\n=== ALTERAR ESTOQUE MINIMO ===\n");

    codigo = lerInteiro("Codigo do produto: ", 1, 999999999);
    indice = buscarIndicePorCodigo(codigo);

    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    novoMinimo = lerInteiro("Novo estoque minimo: ", 0, 1000000);
    produtos[indice].estoqueMinimo = novoMinimo;

    printf("Estoque minimo atualizado.\n");
}

void calcularEstoqueTotal() {
    int i;
    int totalItens = 0;

    printf("\n=== ESTOQUE TOTAL ===\n");

    for (i = 0; i < totalProdutos; i++) {
        totalItens += produtos[i].quantidade;
    }

    printf("Quantidade total de itens no estoque: %d\n", totalItens);
    printf("Quantidade de tipos de produtos cadastrados: %d\n", totalProdutos);
}

void listarBaixoEstoque() {
    int i, encontrou = 0;

    printf("\n=== PRODUTOS COM BAIXO ESTOQUE ===\n");

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    imprimirCabecalhoTabela();

    for (i = 0; i < totalProdutos; i++) {
        if (produtos[i].quantidade <= produtos[i].estoqueMinimo) {
            imprimirLinhaProduto(produtos[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum produto com baixo estoque.\n");
    }
}

void listarProdutosVencidos() {
    int i, encontrou = 0;

    printf("\n=== PRODUTOS VENCIDOS ===\n");

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    imprimirCabecalhoTabela();

    for (i = 0; i < totalProdutos; i++) {
        if (produtoVencido(produtos[i])) {
            imprimirLinhaProduto(produtos[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum produto vencido encontrado.\n");
    }
}

void listarProdutosProximosDoVencimento() {
    int i, encontrou = 0;
    int diasAlerta;

    printf("\n=== PRODUTOS PROXIMOS DO VENCIMENTO ===\n");

    diasAlerta = lerInteiro("Considerar produtos que vencem em ate quantos dias? ", 1, 365);

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    imprimirCabecalhoTabela();

    for (i = 0; i < totalProdutos; i++) {
        if (produtoProximoDoVencimento(produtos[i], diasAlerta)) {
            imprimirLinhaProduto(produtos[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhum produto proximo do vencimento nesse periodo.\n");
    }
}

void ordenarProdutosPorValidade() {
    Produto copia[MAX_PRODUTOS];
    Produto temp;
    int i, j;

    printf("\n=== PRODUTOS ORGANIZADOS POR VALIDADE ===\n");

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (i = 0; i < totalProdutos; i++) {
        copia[i] = produtos[i];
    }

    for (i = 0; i < totalProdutos - 1; i++) {
        for (j = 0; j < totalProdutos - 1 - i; j++) {
            if (compararDatas(copia[j].validade, copia[j + 1].validade) > 0) {
                temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    imprimirCabecalhoTabela();

    for (i = 0; i < totalProdutos; i++) {
        imprimirLinhaProduto(copia[i]);
    }
}

void calcularValorTotalEstoque() {
    int i;
    float valorTotal = 0.0f;

    printf("\n=== VALOR TOTAL DO ESTOQUE ===\n");

    for (i = 0; i < totalProdutos; i++) {
        valorTotal += produtos[i].preco * produtos[i].quantidade;
    }

    printf("Valor total do estoque: R$ %.2f\n", valorTotal);
}

void relatorioProdutosMaisVendidos() {
    Produto copia[MAX_PRODUTOS];
    Produto temp;
    int i, j, encontrou = 0;

    printf("\n=== PRODUTOS MAIS VENDIDOS ===\n");

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    for (i = 0; i < totalProdutos; i++) {
        copia[i] = produtos[i];
    }

    for (i = 0; i < totalProdutos - 1; i++) {
        for (j = 0; j < totalProdutos - 1 - i; j++) {
            if (copia[j].totalVendido < copia[j + 1].totalVendido) {
                temp = copia[j];
                copia[j] = copia[j + 1];
                copia[j + 1] = temp;
            }
        }
    }

    printf("%-8s %-25s %-15s %-12s\n", "Codigo", "Nome", "Categoria", "Vendido");
    printf("---------------------------------------------------------------\n");

    for (i = 0; i < totalProdutos; i++) {
        if (copia[i].totalVendido > 0) {
            printf("%-8d %-25.25s %-15.15s %-12d\n",
                   copia[i].codigo,
                   copia[i].nome,
                   copia[i].categoria,
                   copia[i].totalVendido);

            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma venda registrada ainda.\n");
    }
}

void registrarPerdaDesperdicio() {
    int codigo, indice, quantidade;

    printf("\n=== REGISTRAR PERDA / DESPERDICIO ===\n");

    codigo = lerInteiro("Codigo do produto: ", 1, 999999999);
    indice = buscarIndicePorCodigo(codigo);

    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    quantidade = lerInteiro("Quantidade perdida/desperdicada: ", 1, 1000000);

    if (quantidade > produtos[indice].quantidade) {
        printf("Operacao negada: a perda nao pode ser maior que o estoque atual.\n");
        printf("Quantidade atual: %d\n", produtos[indice].quantidade);
        return;
    }

    produtos[indice].quantidade -= quantidade;
    produtos[indice].totalPerdido += quantidade;
    produtos[indice].valorPerdido += quantidade * produtos[indice].preco;

    printf("Perda registrada com sucesso.\n");
    printf("Nova quantidade em estoque: %d\n", produtos[indice].quantidade);
    printf("Valor perdido nesta operacao: R$ %.2f\n", quantidade * produtos[indice].preco);
}

void relatorioPerdasDesperdicios() {
    int i, encontrou = 0;
    int totalPerdido = 0;
    float valorTotalPerdido = 0.0f;

    printf("\n=== RELATORIO DE PERDAS E DESPERDICIOS ===\n");

    if (totalProdutos == 0) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    printf("%-8s %-25s %-15s %-12s %-12s\n", "Codigo", "Nome", "Categoria", "Qtd perdida", "Valor");
    printf("------------------------------------------------------------------------\n");

    for (i = 0; i < totalProdutos; i++) {
        if (produtos[i].totalPerdido > 0) {
            printf("%-8d %-25.25s %-15.15s %-12d R$ %.2f\n",
                   produtos[i].codigo,
                   produtos[i].nome,
                   produtos[i].categoria,
                   produtos[i].totalPerdido,
                   produtos[i].valorPerdido);

            totalPerdido += produtos[i].totalPerdido;
            valorTotalPerdido += produtos[i].valorPerdido;
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("Nenhuma perda ou desperdicio registrado.\n");
    } else {
        printf("------------------------------------------------------------------------\n");
        printf("Total de itens perdidos/desperdicados: %d\n", totalPerdido);
        printf("Valor total perdido/desperdicado: R$ %.2f\n", valorTotalPerdido);
    }
}

void relatorioGeral() {
    int i;
    int totalItens = 0;
    int qtdBaixoEstoque = 0;
    int qtdVencidos = 0;
    int qtdProximosVencimento = 0;
    int totalVendido = 0;
    int totalPerdido = 0;
    float valorEstoque = 0.0f;
    float valorPerdido = 0.0f;

    printf("\n=== RELATORIO GERAL DO SUPERMERCADO ===\n");

    for (i = 0; i < totalProdutos; i++) {
        totalItens += produtos[i].quantidade;
        valorEstoque += produtos[i].preco * produtos[i].quantidade;
        totalVendido += produtos[i].totalVendido;
        totalPerdido += produtos[i].totalPerdido;
        valorPerdido += produtos[i].valorPerdido;

        if (produtos[i].quantidade <= produtos[i].estoqueMinimo) {
            qtdBaixoEstoque++;
        }

        if (produtoVencido(produtos[i])) {
            qtdVencidos++;
        }

        if (produtoProximoDoVencimento(produtos[i], DIAS_ALERTA_VALIDADE)) {
            qtdProximosVencimento++;
        }
    }

    printf("Produtos cadastrados: %d\n", totalProdutos);
    printf("Quantidade total de itens: %d\n", totalItens);
    printf("Valor total em estoque: R$ %.2f\n", valorEstoque);
    printf("Produtos com baixo estoque: %d\n", qtdBaixoEstoque);
    printf("Produtos vencidos: %d\n", qtdVencidos);
    printf("Produtos que vencem em ate %d dias: %d\n", DIAS_ALERTA_VALIDADE, qtdProximosVencimento);
    printf("Total de itens vendidos: %d\n", totalVendido);
    printf("Total de itens perdidos/desperdicados: %d\n", totalPerdido);
    printf("Valor total perdido/desperdicado: R$ %.2f\n", valorPerdido);
}

void editarLocalizacaoFornecedor() {
    int codigo, indice;

    printf("\n=== EDITAR LOCALIZACAO, LOTE E FORNECEDOR ===\n");

    codigo = lerInteiro("Codigo do produto: ", 1, 999999999);
    indice = buscarIndicePorCodigo(codigo);

    if (indice == -1) {
        printf("Produto nao encontrado.\n");
        return;
    }

    lerLinha("Novo corredor: ", produtos[indice].corredor, TAM_LOCAL);
    lerLinha("Nova prateleira: ", produtos[indice].prateleira, TAM_LOCAL);
    lerLinha("Novo lote: ", produtos[indice].lote, TAM_LOTE);
    lerLinha("Novo fornecedor: ", produtos[indice].fornecedor, TAM_FORNECEDOR);

    printf("Dados atualizados com sucesso.\n");
}

void carregarProdutosExemplo() {
    Produto p;

    if (totalProdutos > 0) {
        printf("Os produtos de exemplo so podem ser carregados quando o estoque esta vazio.\n");
        return;
    }

    p.codigo = 101;
    strcpy(p.nome, "Arroz tipo 1 5kg");
    strcpy(p.categoria, "Alimentos");
    strcpy(p.marca, "Tio Joao");
    p.preco = 29.90f;
    p.quantidade = 30;
    p.estoqueMinimo = 10;
    p.validade = (Data){15, 12, 2026};
    strcpy(p.corredor, "A1");
    strcpy(p.prateleira, "P2");
    strcpy(p.lote, "L-ARZ-001");
    strcpy(p.fornecedor, "Distribuidora Central");
    p.totalVendido = 0;
    p.totalPerdido = 0;
    p.valorPerdido = 0.0f;
    produtos[totalProdutos++] = p;

    p.codigo = 102;
    strcpy(p.nome, "Leite integral 1L");
    strcpy(p.categoria, "Laticinios");
    strcpy(p.marca, "Italac");
    p.preco = 5.49f;
    p.quantidade = 8;
    p.estoqueMinimo = 12;
    p.validade = (Data){10, 5, 2026};
    strcpy(p.corredor, "B2");
    strcpy(p.prateleira, "P1");
    strcpy(p.lote, "L-LTE-020");
    strcpy(p.fornecedor, "Laticinios Goias");
    p.totalVendido = 0;
    p.totalPerdido = 0;
    p.valorPerdido = 0.0f;
    produtos[totalProdutos++] = p;

    p.codigo = 103;
    strcpy(p.nome, "Detergente neutro");
    strcpy(p.categoria, "Limpeza");
    strcpy(p.marca, "Ype");
    p.preco = 2.79f;
    p.quantidade = 50;
    p.estoqueMinimo = 15;
    p.validade = (Data){30, 1, 2027};
    strcpy(p.corredor, "C3");
    strcpy(p.prateleira, "P4");
    strcpy(p.lote, "L-DTG-330");
    strcpy(p.fornecedor, "Atacado Limpeza Brasil");
    p.totalVendido = 0;
    p.totalPerdido = 0;
    p.valorPerdido = 0.0f;
    produtos[totalProdutos++] = p;

    p.codigo = 104;
    strcpy(p.nome, "Iogurte morango");
    strcpy(p.categoria, "Laticinios");
    strcpy(p.marca, "Nestle");
    p.preco = 3.99f;
    p.quantidade = 20;
    p.estoqueMinimo = 10;
    p.validade = (Data){1, 5, 2026};
    strcpy(p.corredor, "B2");
    strcpy(p.prateleira, "P3");
    strcpy(p.lote, "L-IOG-515");
    strcpy(p.fornecedor, "Laticinios Goias");
    p.totalVendido = 0;
    p.totalPerdido = 0;
    p.valorPerdido = 0.0f;
    produtos[totalProdutos++] = p;

    printf("Produtos de exemplo carregados com sucesso.\n");
}

void exibirMenu() {
    printf("\n============================================================\n");
    printf("      SISTEMA DE CONTROLE DE ESTOQUE - SUPERMERCADO\n");
    printf("============================================================\n");
    printf("1  - Cadastrar produto\n");
    printf("2  - Listar produtos\n");
    printf("3  - Buscar produto\n");
    printf("4  - Adicionar estoque\n");
    printf("5  - Vender produto / remover por venda\n");
    printf("6  - Remover estoque sem venda\n");
    printf("7  - Atualizar quantidade\n");
    printf("8  - Verificar disponibilidade\n");
    printf("9  - Alterar estoque minimo\n");
    printf("10 - Calcular estoque total\n");
    printf("11 - Produtos com baixo estoque\n");
    printf("12 - Produtos vencidos\n");
    printf("13 - Produtos proximos do vencimento\n");
    printf("14 - Organizar produtos por validade\n");
    printf("15 - Valor total do estoque\n");
    printf("16 - Produtos mais vendidos\n");
    printf("17 - Registrar perda/desperdicio\n");
    printf("18 - Relatorio de perdas/desperdicios\n");
    printf("19 - Relatorio geral\n");
    printf("20 - Editar corredor, prateleira, lote e fornecedor\n");
    printf("21 - Carregar produtos de exemplo\n");
    printf("0  - Sair\n");
    printf("============================================================\n");
}

int main() {
    int opcao;

    do {
        exibirMenu();

        opcao = lerInteiro("Escolha uma opcao: ", 0, 21);

        switch (opcao) {
            case 1:
                cadastrarProduto();
                pausar();
                break;

            case 2:
                listarProdutos();
                pausar();
                break;

            case 3:
                buscarProduto();
                pausar();
                break;

            case 4:
                adicionarEstoque();
                pausar();
                break;

            case 5:
                venderProduto();
                pausar();
                break;

            case 6:
                removerEstoqueSemVenda();
                pausar();
                break;

            case 7:
                atualizarQuantidade();
                pausar();
                break;

            case 8:
                verificarDisponibilidade();
                pausar();
                break;

            case 9:
                alterarEstoqueMinimo();
                pausar();
                break;

            case 10:
                calcularEstoqueTotal();
                pausar();
                break;

            case 11:
                listarBaixoEstoque();
                pausar();
                break;

            case 12:
                listarProdutosVencidos();
                pausar();
                break;

            case 13:
                listarProdutosProximosDoVencimento();
                pausar();
                break;

            case 14:
                ordenarProdutosPorValidade();
                pausar();
                break;

            case 15:
                calcularValorTotalEstoque();
                pausar();
                break;

            case 16:
                relatorioProdutosMaisVendidos();
                pausar();
                break;

            case 17:
                registrarPerdaDesperdicio();
                pausar();
                break;

            case 18:
                relatorioPerdasDesperdicios();
                pausar();
                break;

            case 19:
                relatorioGeral();
                pausar();
                break;

            case 20:
                editarLocalizacaoFornecedor();
                pausar();
                break;

            case 21:
                carregarProdutosExemplo();
                pausar();
                break;

            case 0:
                printf("Encerrando o sistema...\n");
                break;

            default:
                printf("Opcao invalida.\n");
                pausar();
        }

    } while (opcao != 0);

    return 0;
}