# Introdução à Computação

Exercícios e estudos em C desenvolvidos na disciplina de Introdução à Computação.

## Organização

- **Aulas/** — códigos separados por aula e exercício, dos primeiros algoritmos até vetores, matrizes, funções e `struct`.
- **Listas de Exercícios/** — soluções agrupadas por lista: introdução, estruturas sequenciais e condicionais, repetição e vetores.
- **Trabalho-Estoque/** — programa de exemplo para controle de estoque. O menu permite cadastrar e consultar produtos, registrar movimentações, acompanhar validade e gerar relatórios. Os dados ficam em memória durante a execução.

Os exercícios são independentes. Várias pastas contêm um arquivo chamado `main.c`; compile e execute **um exercício por vez**, dentro da pasta correspondente.

## Como executar um exercício

Com um compilador C instalado, abra o terminal na pasta do exercício. Para um arquivo `main.c`, por exemplo:

```powershell
gcc main.c -o programa.exe
.\programa.exe
```

Para testar o trabalho de estoque no Windows, a partir da raiz do repositório:

```powershell
gcc Trabalho-Estoque/codigo_exemplo.c -o estoque.exe
.\estoque.exe
```

Se o exercício tiver outro nome de arquivo, substitua `main.c` pelo nome correspondente.

