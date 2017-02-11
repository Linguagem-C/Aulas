#include <stdio.h>
#include <stdlib.h>

int main() {

	int x=5, y=3;

	printf("Resultado = %d\n", x > 4);
	printf("Resultado = %d\n", x < 2);
	printf("Resultado = %d\n", x >= y+2);
	printf("Resultado = %d\n", x <= y+2);
	printf("Resultado = %d\n", x == y);
	printf("Resultado = %d\n", x != y);

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

OPERADORES RELACIONAIS:
	
	- Permitem fazer comparações entre valores dentro do programa
		valor1 "Operador Relacional" valor2

	- Resultados:
		0: A comparação é falsa
		1: A comparação é verdadeira

	- Operadores:
		> "Maior que"
		< "Menor que"
		>= "Maior ou igual que"
		<= "Menor ou igual que"
		== "Igual a"
		!= "Diferente de"

-----------------------------------------------------------------------------*/