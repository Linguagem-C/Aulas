#include <stdio.h>
#include <stdlib.h>

int main() {

	int cub[3][3][3]; //125 variáveis do tipo inteiro
	int x, y, z;

	//Preencher o array tridimensional com zeros
	for(x=0; x<3; x++){
		for(y=0; y<3; y++){
			for(z=0; z<3; z++){
				cub[x][y][z] = 0;
			}
		}
	}

	printf("Não tem como imprimir uma variável tridimensional!\n");

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

ARRAY MULTIDIMENSIONAL:
	- São arrays com várias dimensões
	- Quanto mais dimensões tiver o array mais memória será consumida

	tipo nome[dim1][dim2][dim3][dim4]...[dimN];

	- Exemplo:
		int vetor[10];
		int matriz[3][3];
		int matriz_tridimensional[2][2][3];
		int matriz_de_4_dimensoes[1][2][3][4];

Percorrendo um array multidimensional[3][3][3]:

	X -> Y ->  Z
	0		 0		0-2
	0		 1		0-2
	0		 2		0-2
	1		 0 		0-2
	1		 1		0-2
	1		 2		0-2
	2		 0		0-2
	...

-----------------------------------------------------------------------------*/