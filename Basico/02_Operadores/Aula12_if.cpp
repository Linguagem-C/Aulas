#include <stdio.h>
#include <stdlib.h>

int main() {

	int x, y;
	
	printf("Digite um valor inteiro: ");
	scanf("%d", &x);

	if ((x%2 == 0) || (x < 0))
		printf("O valor é par ou negativo!\n");

	if (x > 0) {
		y = x%3;
		printf("O resto de %d/3 eh: %d\n", x, y);
	}
	

	printf("Fim do programa!\n");
	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

if(CONDIÇÃO) {
	//conjunto de comandos
}

- Se eu tiver apenas um comando a ser executado o if não precisa do par de chaves

-----------------------------------------------------------------------------*/