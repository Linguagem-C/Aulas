#include <stdio.h>
#include <stdlib.h>
#define LINHAS 10

int main() {

	const float PI = 13.1415;

	float numero = PI*2;

	printf("O Número é: %.4f\n", numero);
	printf("O Constante PI é: %.4f\n", PI);
	printf("O Contante Linhas é: %d\n", LINHAS);

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

CONSTANTES:

	- São variaveis globais que nunca serão modificadas

	- Obrigatoriamente a constante tem que ser inicializada

	- Duas formas de definir uma constante

		1 #define PI 13.1415 -> substitui o valor onde estiver escrito PI no codigo

		2 const int PI = 13.1415; -> Armazena o valor na memoria para ser usado pelo
		pelo codigo, não pode ser modificado

-----------------------------------------------------------------------------*/