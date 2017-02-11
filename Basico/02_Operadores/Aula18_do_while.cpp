#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b=10, i;

	printf("Digite um valor inteiro: ");
	scanf("%d", &a);

	do {
		printf("%d\n", a);
		a++;
	}while(a<b);

	//MENU
	do {
		printf("Escolha uma opção:\n");
		printf("(1) Opção 1\n");
		printf("(2) Opção 2\n");
		printf("(3) Opção 3\n");
		scanf("%d", &i);
		if(i<1 || i>3){
			printf("Opção invalida!, Escolha uma das opções abaixo!\n");
		}
	}while((i<1) || (i>3));

	printf("Você escolheu a opção %d\n", i);

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

L11-14 -> Se inserimos um valor acima de 10 vamos executar o comando uma
única vez, caso contrario, executaremos até o a == 10 com o a++

L23: Enquanto a opção do usuario for menor que 1 ou maior que 3, ou seja,
estiver fora do intervalo que precisamos pro menu, vamos continuar no loop

DO-WHILE:
	- Permite executar, repetidamente e ao menos uma vez, um conjunto de comandos de acordo
	com uma condição

	do {
		//Conjunto de comandos;
	}while(condição);

	- Se a condição for falsa vai executar o comando uma vez caso contrario
	executa n vezes

-----------------------------------------------------------------------------*/