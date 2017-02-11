#include <stdio.h>

/* Essa variável já existe em outro arquivo, e é pra usar ela. */
extern int soma;

void escreve() {
  printf("Soma = %d\n", soma);
}

static void estatico() {
  printf("Não será imprimido por outro arquivo\n");
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  - EXTERN

    > Permite definir variaveis globais que serão visíveis em mais de um arquivo do programa.

    > Ao colocar a palavra extern antes da declaração de uma variável, não estamos declarando uma
    nova variável, mas apenas informando ao compilador que ela existe em outro local de armazenamento
    previamente definido, ela não pode ser inicializada.

-------------------------------------------------------------------------------------- */