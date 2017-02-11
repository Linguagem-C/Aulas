#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j, lista[5] = {1, 2, 3, 4, 5};
	int matriz[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
	int soma = 0;

	//Soma os elementos de um array
	for(i=0; i<5; i++){
		soma += lista[i];
	}

	printf("Soma do vetor = %d\n", soma);

	soma = 0;
	//Soma os elementos de uma matriz
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			soma += matriz[i][j];
		}
	}

	printf("Soma da matriz = %d\n", soma);


	return 0;
}