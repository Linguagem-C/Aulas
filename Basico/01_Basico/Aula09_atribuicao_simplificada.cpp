#include <stdio.h>
#include <stdlib.h>

int main() {

	float x;
	int y=10;

	x += y; // x = x+y;
	printf("x = %.1f\n", x);

	x -= 5; // x = x-5;
	printf("x = %.1f\n", x);

	x /= 2; // x = x/2;
	printf("x = %.1f\n", x);

	x *= 3; // x = x*3;
	printf("x = %.1f\n", x);

	y %= 2; // x = x%2;
	printf("y = %d\n", y);

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

	Variavel "Operação=" Expressão

-----------------------------------------------------------------------------*/