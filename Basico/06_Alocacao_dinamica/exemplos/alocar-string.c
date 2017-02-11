#include "lib/alocar-string.h"
#define TAM 100

int main() {

  int tamanho;
  char *texto1;
  char texto2[TAM];

  printf("Insira o número de caracteres do texto: ");
  scanf("%d", &tamanho);
  flush_in();

  texto1 = alocar_string(tamanho);

  escrever(texto1, tamanho);
  escrever(texto2, TAM);

  imprimir(texto1);
  imprimir(texto2);

  return 0;
}
