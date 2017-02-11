#include "lib/alocar-struct.h"

int main() {

  PESSOA *p1;

  p1 = alocar_struct();

  /* ------------------------------------------------------------------------ */

    contrutor(p1, "Victor Arnaud", 22, "Cruzeiro Novo", "011.928.384-55");

    imprimir_struct(p1);

    printf("\n");

  /* ------------------------------------------------------------------------ */

  /* ------------------------------------------------------------------------ */

    setNome(p1, "João Pereira");
    setIdade(p1, 66);
    setEndereco(p1, "Rua 26 Norte");
    setCpf(p1, "011.123.456-77");
    printf("Nome: %s\n", getNome(p1));
    printf("Idade: %d anos\n", getIdade(p1));
    printf("Endereço: %s\n", getEndereco(p1));
    printf("Cpf: %s\n", getCpf(p1));

    printf("\n");

  /* ------------------------------------------------------------------------ */

  /* ------------------------------------------------------------------------ */

    escrever_struct(p1);
    imprimir_struct(p1);

  /* ------------------------------------------------------------------------ */

  liberar_memoria(p1);

  return 0;
}
