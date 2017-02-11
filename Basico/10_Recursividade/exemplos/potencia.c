#include <stdio.h>
#include <stdlib.h>

int potencia(int base, int expoente) {
	if(expoente == 0)
		return 1;
	else
		return (base*potencia(base, expoente-1));
}

int main() {
	int base, expoente;

	printf("Insira a base do expoente: ");
	scanf("%d", &base);

	printf("Insira o expoente: ");
	scanf("%d", &expoente);

	printf("%d^%d = %d\n", base, expoente, potencia(base, expoente));

	return 0;
}