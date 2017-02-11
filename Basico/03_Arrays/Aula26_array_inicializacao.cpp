#include <stdio.h>
#include <stdlib.h>

int main() {

	int i, j;
	int vetor[5] = {2, 4, 4, 3, 6};
	int matriz[2][3] = {{1, 5, 3},{3, 5, 8}};

	printf("----------------------------------------\n");

	for(i=0; i<5; i++)
		printf("%d ", vetor[i]);

	printf("\n\n");

	for(i=0; i<2; i++){
		for(j=0; j<3; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}
	printf("----------------------------------------\n");



	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

INICIALIZAÇÃO DE ARRAYS:
	- Podemos definir uma lista de valores para colocar no array
	- Para separar os valores usa-se virgula
	- Para separar as dimensões usa-se colchetes {{dim1},{dim2},{dim3}, ..., {dimN}}
	- Não precisa especificar o tamanho de um vetor na inicialização, o proprio
	compilador irá verificar e definir o tamanho
	- Em matrizes sou obrigado a definir todas as dimensões exceto a primeira
	- Mas é sempre bom colocar o tamanho dos arrays

	- VETORES:
		tipo nome[tamanho] = {valor1, valor2, valor3, ..., valorN};

	- MATRIZES:
		tipo nome[NumeroDeLinhas][NumeroDeColunas] = {{valor1, valor2, ..., valorN},
													 {valor1, valor2, ..., valorN}};

	- Exemplos:
		int vetor[] = {1, 4, 7, 3, 2};

				   			 00    01  02   10    11    12
		float matriz[][3] = {1.2, 4.3, 5.8, 4.4, 23.3, 102.3};

							 linha1		linha2
		int matriz[2][3] = {{1, 5, 3},{3, 5, 8}};

-----------------------------------------------------------------------------*/