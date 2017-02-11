#include <stdio.h>
#include <stdlib.h>

int main() {

	char letra = 'a';
	char ascii = 77;
	int numero = 75;
	float pi = 13.1415;
	double mol = 6.0e23;

	printf("-------------------------------------------\n\n");

	printf("Imprimindo Variáveis:\n");
	printf("ASCII de %c é %d\n", letra, letra);
	printf("ASCII de %d é %c\n", numero+2, ascii);
	printf("numero: %d\n", 52);
	printf("PI: %.4f\n", pi);
	printf("Mol: %.1f\n", mol);

	printf("\n-------------------------------------------\n");

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

PRINTF():
	- Basicamente vai escrever no console toda a mensagem que estiver entre as
	aspas duplas
	- printf("Texto e tipos de entradas", variaveis);

TIPOS DE DADOS DE ENTRADA:
	%d -> Usado para número inteiros
	%c -> Usado para caracteres
	%f -> Usado para valores Reais
	%.1f -> Valores reais com uma única casa decimal
	%.4f -> Valores reais com 4 casas decimais


-----------------------------------------------------------------------------*/
