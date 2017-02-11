#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Função sqrt();
int quadrado(int a){
	return a*a;
}

int main() {

	int x = 10, q;

	q = quadrado(x);

	printf("%d\n", q);


	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

	- Conjunto de comandos que recebe um nome e pode ser chamado em parte do programa,
	quantas vezes forem necessaria.

	- Restruturação do programa e reutilização de códigos.

DECLARAÇÃO:

		tipoDeRetorno NomeDaFunção (Parametros){
			Conjunto de comandos e declarações
		}

	- Se a função for declarada em baixo da main seu prototipo tipo nome(parametros); deve ser
	declarado a cima da main

----------------------------------------------------------------------------------------- */