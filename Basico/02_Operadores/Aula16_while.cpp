#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b;

	printf("Digite dois valores inteiros: ");
	scanf("%d %d", &a, &b);

	if (a>b) {
		while(b<a){
			b++;
			printf("%d\n", b);
		}
	}else{
		while(a<b){
			a++;
			printf("%d\n", a);
		}
	}

	printf("Fim do programa!\n");

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

WHILE:
	- Permite executar, repetidamente, um conjunto de comandos de acordo
	com uma condição

	while(condição) {
		//Conjunto de comandos;
	}

	- Faça esse conjunto de comandos enquanto(while) essa condição for satisfeita
	- Cuidado para não cair em um loop infinito, se a condição for sempre verdadeira

-----------------------------------------------------------------------------*/