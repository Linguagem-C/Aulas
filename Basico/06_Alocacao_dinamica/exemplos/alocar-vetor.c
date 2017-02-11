#include "lib/alocar-vetor.h"

int main() {

  int qtd;
  int *vetor;

  printf("Insira o tamanho do vetor: ");
  scanf("%d", &qtd);

  vetor = alocar_vetor(qtd);

  escrever_vetor(vetor, qtd);

  imprimir_vetor(vetor, qtd);

  desalocar_memoria(vetor);

  return 0;

}
