#include <stdio.h>
#include <stdlib.h>

int main() {

	int x = 9, y = 9, z;

	x++;

	++y;

	printf("x = %d\n", x);
	printf("y = %d\n", y);

	y = x++;

	z = ++x;

	printf("y = %d\n", y);
	printf("x = %d\n", x);
	printf("z = %d\n", z);


	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

x++ -> x=x+1

x-- -> x=x-1

y = x++ -> Pós incremento, faz a atribuição primeiro depois incrementa o x
	y = x;
	x++;

z = ++x -> Pré incremento, faz o incremento de x primeiro e depois joga em z
	x++;
	z = x;

-----------------------------------------------------------------------------*/