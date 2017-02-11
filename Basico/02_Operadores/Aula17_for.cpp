#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b=20, i, j;

	printf("Digite um valor interio: ");
	scanf("%d", &a);

	if(a < b){
		for(i=a; i<=b; i++){
			printf("%d\n", i);
		}
	}else{
		for(i=a; i>=b && i>0; i--){
			printf("%d\n", i);
		}
	}

	for(int i=0, j=10; i<j; i++, j-=2){
		printf("i = %d e j = %d\n", i, j);
	}

	printf("Fim do programa!\n");

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

L12: inicialização -> i=a
		 condição -> rode o loop enquanto i<=b
		 incremento -> i++ ou i=i+1

L16: inicialização -> i=a
		 condição -> rode o loope enquanto i>=b
		 Decremento -> i-- ou i=i-1

L21: inicialização -> i=0 e j=10
		 condição -> rode o loop enquanto i<j
		 incremento -> i++ e j-=2

FOR:
	- Permite executar, repetidamente, um conjunto de comandos de acordo
	com uma condição

	for(inicialização; condição; incremento){
		//Conjunto de comandos
	}

	- Como o while também está sujeito a loops infinitos

-----------------------------------------------------------------------------*/