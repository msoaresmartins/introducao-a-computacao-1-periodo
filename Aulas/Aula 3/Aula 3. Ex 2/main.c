/*2. Implemente um programa que receba dois números e mostre qual deles é o maior*/

#include <stdio.h>

int main() {
	int num1, num2;

	printf("Digite o primeiro numero: ");
	scanf("%d", &num1);

	printf("Digite o segundo numero: ");
	scanf("%d", &num2);


	if (num1 > num2) {
		printf("O maior numero e o primeiro: %d\n", num1);
	} else {
			printf("O maior numero e o segundo: %d\n", num2);
		}

	return 0;
}