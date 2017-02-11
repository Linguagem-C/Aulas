#include <stdio.h>
#include <stdlib.h>

int main() {

	int numero;
	float real;

	printf("Digite dois número: ");
	scanf("%d%f", &numero, &real);
	printf("Número digitado foi %d e %.1f\n", numero, real);

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

SCANF():
	- Faz leitura de dados do teclado e guarda elas nas variáveis
	- scanf("Tipos de entradas", &Variaveis);

-----------------------------------------------------------------------------*/