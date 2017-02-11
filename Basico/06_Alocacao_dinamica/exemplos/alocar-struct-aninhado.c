#include "lib/alocar-struct-aninhado.h"

int main() {

  PESSOA *p1;
  int qtd_pessoas, qtd_tels;

  printf("Insira a quantidade de pessoas: ");
  scanf("%d", &qtd_pessoas);
  printf("Insira a quantidade de telefone por pessoa: ");
  scanf("%d", &qtd_tels);
  flush_in();

  p1 = alocar_pessoa(qtd_pessoas, qtd_tels);

  escrever_struct(p1, qtd_pessoas, qtd_tels);
  imprimir_struct(p1, qtd_pessoas, qtd_tels);

  return 0;
}
