#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j;

	//MATRIZ IDENTIDADE 5x5
	for(i=1; i<5; i++){
		for(j=1; j<5; j++){
			if(i == j){
				printf("1 ");
			}else{
				printf("0 ");
			}
		}
		printf("\n");
	}

	printf("\n\n");

	i=1;
	while(i<5) {
		j=1;
		while(j<5){
			if(i == j)
				printf("1 ");
			else
				printf("0 ");
			j++;
		}
		printf("\n");
		i++;
	}

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

ANINHAMENTO DE REPETIÇÕES:

	- Trata-se do uso de um comando de repetição (while, for ou do-while)
	dentro de outro

	repetição(condição1){
		//Conjunto de comandos;
		repetição(condição2){
			//Conjunto de comandos;
			repetiç...
		}
	}

-----------------------------------------------------------------------------*/