#include <stdio.h>
#include <stdlib.h>

int main() {

	int x=5, y=3, z=7;
	int e, ou, Not;

	e = ((x>6) && (y==3)) || (x<=2); //Falso
	ou = (z!=7) || (z>3) || (x>=5); //Verdadeiro
	Not = !((x < 7) && (y==3)); //Verdadeiro -> Falso

	printf("Resultado e = %d\n", e);
	printf("Resultado ou = %d\n", ou);
	printf("Resultado Not = %d\n", Not);

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

OPERADOS LÓGICOS:
	&& = E
	|| = OU
	! = Not

	Forma Geral:
		expressão1 <Operador Logico> expressão2
		!(expressão)

	Resultado da Expressão:
		0: A operação é falsa
		1: A operação é verdadeira

	Tabela Verdade:
		A B		!A	!B	A&&B	A||B
		0 0		 1	 1		0		  0
		0 1		 1	 0		0			1
		1 0		 0	 1		0			1
		1 1		 0	 0		1			1
-----------------------------------------------------------------------------*/