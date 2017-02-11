#include <stdio.h>
#include <stdlib.h>

int **alocar_matriz(int qtd_linhas, int qtd_colunas) {
  int **matriz;
  int i;

  matriz = (int**) malloc(qtd_linhas * sizeof(int*));
  for(i=0; i<qtd_linhas; i++){
    matriz[i] = (int*) malloc(qtd_colunas * sizeof(int));
  }

  return matriz;
}

void desalocar_memoria(int **matriz, int qtd_linhas) {
  int i;
  for(i=0; i<qtd_linhas; i++){
     free(matriz[i]);
    }
  free(matriz);
}

void escrever_matriz(int **matriz, int qtd_linhas, int qtd_colunas) {
  int i, j;

  for(i=0; i<qtd_linhas; i++){
    for(j=0; j<qtd_colunas; j++){
      printf("Matriz[%d][%d]: ", i, j);
      scanf("%d", &matriz[i][j]);
    }
  }
}

void imprimir_matriz(int **matriz, int qtd_linhas, int qtd_colunas) {
  int i, j;

  for(i=0; i<qtd_linhas; i++){
    for(j=0; j<qtd_colunas; j++){
      printf("%d ", matriz[i][j]);
    }
    printf("\n");
  }

}
