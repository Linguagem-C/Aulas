#include "lib/alocar-struct-vetor.h"

int main() {

  int qtd;
  PESSOA *p1;

  printf("Insira a quantidade de pessoas: ");
  scanf("%d", &qtd);
  flush_in();

  p1 = alocar_vetor_struct(qtd);

  escrever_struct(p1, qtd);
  imprimir_struct(p1, qtd);

  setNome(p1, "Fulado doido", 0);
  setIdade(p1, 99, 0);
  setEndereco(p1, "Rua do cachorro loco", 0);
  setCpf(p1, "666", 0);
  printf("Nome: %s\n", getNome(p1, 0));
  printf("Idade: %d\n", getIdade(p1, 0));
  printf("Endereço: %s\n", getEndereco(p1, 0));
  printf("Cpf: %s\n", getCpf(p1, 0));

  liberar_memoria(p1);

  return 0;
}
