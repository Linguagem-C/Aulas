#include <stdio.h>
#include <stdlib.h>

int *alocar_vetor(int qtd) {
  int *vetor;

  vetor = (int*) malloc(qtd * sizeof(int));

  if(vetor == NULL) {
    printf("Sem memória!\n");
    exit(0);
  }

  return vetor;
}

void desalocar_memoria(int *vetor) {
  free(vetor);
}

void escrever_vetor(int *vetor, int qtd) {
  int i;
  if(qtd == 0) {
    return;
  }
  for(i=0; i<qtd; i++) {
    printf("Insira o %d° valor: ", i+1);
    scanf("%d", &vetor[i]);
  }
}

void imprimir_vetor(int *vetor, int qtd) {
  int i;
  if(qtd == 0) {
    return;
  }
  printf("Vetor = [%d", vetor[0]);
  for(i=1; i<qtd; i++){
    printf(", %d", vetor[i]);
  }
  printf("]\n");
}
