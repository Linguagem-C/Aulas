#include <stdlib.h>
#include <stdio.h> 

struct ponto {
  int x, y, z;
};

int main(){

  printf("char = %d bytes\n", sizeof(char));
  printf("short = %d bytes\n", sizeof(short));
  printf("int = %d bytes\n", sizeof(int));
  printf("long = %d bytes\n", sizeof(long));
  printf("float = %d bytes\n", sizeof(float));
  printf("double = %d bytes\n", sizeof(double));
  printf("struct ponto = %d bytes\n", sizeof(struct ponto));

	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO: 

    - Alocar memória do tipo int é diferente de alocar memória do tipo char

  TIPOS:

    - char = 1 byte
    - int = 4 bytes
    - float = 4 bytes
    - double = 8 bytes

  OBSERVAÇÕES:

    - O comando sizeof() retorna o número de bytes necessarios para alocar um único elemento de um determinado tipo de dado.

    int tamanho_do_inteiro = sizeof(int)

-------------------------------------------------------------------------------------------*/