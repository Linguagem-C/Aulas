#include "lib/alocar-matriz.h"

int main() {

  /*int v[5] = {2, 4, 4, 3, 6};
	int m[2][3] = {{1, 5, 3},{3, 5, 8}};*/

  int qtd_linhas, qtd_colunas;
  int **matriz;

  printf("Insira o número de linhas do vetor: ");
  scanf("%d", &qtd_linhas);
  printf("Insira o número de colunas do vetor: ");
  scanf("%d", &qtd_colunas);

  matriz = alocar_matriz(qtd_linhas, qtd_colunas);

  escrever_matriz(matriz, qtd_linhas, qtd_colunas);

  imprimir_matriz(matriz, qtd_linhas, qtd_colunas);

  desalocar_memoria(matriz, qtd_linhas);

  return 0;

}
