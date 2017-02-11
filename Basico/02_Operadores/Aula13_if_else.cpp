#include <stdio.h>
#include <stdlib.h>

int main() {

	int x;

	printf("Digite um valor inteiro: ");
	scanf("%d", &x);

	if(x%2 == 0)
		printf("O valor é PAR!\n");
	else
		printf("O valor é IMPAR!\n");

	if(x > 0)
		printf("O valor é positivo!\n");
	else if (x == 0)
		printf("O valor é igual a zero!\n");
	else
		printf("O valor é negativo!\n");

	printf("Fim do programa!\n");
	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

	if(CONDIÇÃO) {
		//Conjunto de comandos (condição verdadeira)
	}else{
		//Conjunto de comandos (condição falsa)
	}

	if(CONDIÇÃO1) {
		//Conjunto de comandos (condição verdadeira)
	}else if(CONDIÇÃO2) {
		//Conjunto de comandos (condição verdadeira)
	}else{
		//Conjunto de comandos (condição falsa)
	}

- Se eu tiver apenas um comando a ser executado o if não precisa do par de chaves
- Podemos aninhar varios else if dentro desse bloco de codigos

-----------------------------------------------------------------------------*/
