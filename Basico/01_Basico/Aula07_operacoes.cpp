#include <stdio.h>
#include <stdlib.h>

int main() {

	int x1 = 10, x2 = 20, x3 = 30;
	int soma1, sub1, mult1, resto;

	float x4 = 10.25, x5 = 15.22;
	float soma2, sub2, div2;

	soma1 = x1 + x2 + x3;
	soma2 = x4 + x5;
	sub1 = x2-x1;
	sub2 = -x4;
	mult1 = 3*x1*x2;
	div2 = x4/2.0;
	resto = x1%x3;


	printf("Soma1 = %d\n", soma1);
	printf("Soma2 = %.2f\n", soma2);
	printf("Sub1 = %d\n", sub1);
	printf("Sub2 = %.2f\n", sub2);
	printf("Mult1 = %d\n", mult1);
	printf("Div2 = %.2f\n", div2);
	printf("Resto = %d\n", resto);


	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

OPERAÇÕES:
	+ Soma -> int, float e char
	- Subtração -> int, float e char
	/ Divisão -> Para o resultado ser um número real um dos dois valores 
	tem que ser real, ou fazer um cast na operação
	* Multiplicação -> int, float, char
	% Resto -> int

-----------------------------------------------------------------------------*/