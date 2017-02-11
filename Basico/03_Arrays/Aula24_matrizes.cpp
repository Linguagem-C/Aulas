#include <stdio.h>
#include <stdlib.h>
#define LINHA 2
#define COLUNA 3

int main() {

	int matriz[LINHA][COLUNA];
	int i,j;

//ESCRITA NA MATRIZ
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			printf("Digite matriz[%d][%d]: ", i, j);
			scanf("%d", &matriz[i][j]);
		}
	}

//IMPRESSÃO DA MATRIZ
	for(i=0; i<LINHA; i++){
		for(j=0; j<COLUNA; j++){
			printf("%d ", matriz[i][j]);
		}
		printf("\n");
	}

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

MATRIZ:
	- É um array bidimensional

	tipo nomeDoArray[NumeroDeLinhas][NumeroDeColunas];

	- Exemplo:
		int matriz[3][4];

TAMANHO DE MATRIZES:
	#define N 100
	int v = 10;
	float F[N+1][N]; //CORRETO
	char frases[30][50] //CORRETO
	int mat[n][n]; //ERRADO
	int M[4.5][3]; //ERRADO

ACESSANDO ELEMENTOS DA MATRIZ PELOS SEUS INDICES:
	int mat[3][2];
	mat[0][0] = 5; -> Incluir o valor 5 na linha 0 e coluna 0 da matriz
	mat[0][1] = 23; -> Incluir o valor 23 na linha 0 e coluna 1 da matriz
	mat[2][1] = -1; -> Incluir o valor -1 na linha 2 e coluna 1 da matriz

OPERAÇÕES COM MATRIZES:
	int mat[3][2], M[3][2];
	scanf("%d", &mat[2][0]); //Comando de escrita
	printf("%d\n", M[2][1]); //Comando de leitura
	mat[0][0] = 10; //Comando de atribuição
	mat[1][1] = mat[0][0] + mat[2][0]; //Expressões
	mat = M //ERRADO
	
-----------------------------------------------------------------------------*/