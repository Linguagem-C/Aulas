#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j, k;
	for(i=0; i<5; i++){
		for(j=0; j<5; j++){
			for(k=0; k<5; k++){
				if(i==2 && j==3 && k==1)
					goto fim;
				else
					printf("Pos[%d,%d,%d]\n", i, j, k);
			}
		}
	}

	fim:
	printf("Fim do programa!\n");

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

L11: O comando <goto fim;> faz o laço se romper e ir direto a linha 18 do código
onde está escrito <fim:>

COMANDO GOTO:
	- Não muito utilizado, pois faz a mesma coisa dos outros laços de repetição
	- Só é bom no caso acima
	
-----------------------------------------------------------------------------*/