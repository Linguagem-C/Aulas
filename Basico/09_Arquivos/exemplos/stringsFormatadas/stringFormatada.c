#include "lib/crud.h"

int main() {

  PESSOA *p;
  int qtd_pessoas;

  /* Por enquanto, mas a quantidade de pessoas vai ser tirada da quantidade de registro */
  printf("Insira a quantidade de pessoas: ");
  scanf("%d", &qtd_pessoas);
  flush_in();

  p = alocar_pessoa(qtd_pessoas);

  criar_arquivo(p, qtd_pessoas);

  /*add_registro(p, qtd_pessoas);*/

  vizualizar_registros();

  return 0;
}
