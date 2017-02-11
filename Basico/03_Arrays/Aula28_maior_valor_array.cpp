#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j, lista[5] = {3, 18, 2, 51, 45};
	int matriz[3][3] = {{1, 32, 3}, {24, 5, 26}, {47, -78, 9}};
	int maior1 = lista[0];
	int maior2 = matriz[0][0];

	//Maior elemento de um vetor
	for(i=1; i<5; i++){
		if(maior1 < lista[i]){
			maior1 = lista[i];
		}
	}

	printf("Maior valor do vetor = %d\n", maior1);

	//Maior elemento de uma matriz
	for(i=0; i<3; i++){
		for(j=0; j<3; j++){
			if(maior2 < matriz[i][j]){
			maior2 = matriz[i][j];
			}
		}
	}

	printf("Maior valor da matriz = %d\n", maior2);


	return 0;
}