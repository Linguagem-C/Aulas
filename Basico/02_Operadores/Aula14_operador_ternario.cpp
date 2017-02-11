#include <stdio.h>
#include <stdlib.h>

int main() {

	int x, y, z;

	printf("Insira o valor de x: ");
	scanf("%d", &x);
	printf("Insira o valor de y: ");
	scanf("%d", &y);

	z = x > y ? x : y;

	(x>y) ? printf("O maior valor é o x\n") 
				: printf("O maior valor é o y\n");

	printf("O maior valor vale: %d\n", z);
	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

L13: Se x for maior que y vamos armazenar o valor de x em z 
	   caso contrario armazena o valor de y em z

OPERADOR TERNARIO ?
	- Usado para fazer atribuições condicionais
		variavel = condição ? expressão1 : expressão2;

	- expressão1 -> equivale ao codigo depois do if (codição verdadeira)
	- expressão2 -> equivale ao codigo depois do else (codição falsa)
	- Operador ternarios só serve para condicional de uma única linha

-----------------------------------------------------------------------------*/