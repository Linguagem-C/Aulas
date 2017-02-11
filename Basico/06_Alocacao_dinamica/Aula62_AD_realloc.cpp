#include <stdlib.h>
#include <stdio.h> 

int main(){

  int *v, *v1;

  v = (int*) malloc(50 * sizeof(int));

  v1 = (int*) realloc(v, 100 * sizeof(int));

  if(v1 != NULL)
    v = v1;

  free(v);

	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - A função realloc() serve para alocar ou realocar memoria em tempo de execução

  - Recebe como parametro um ponteiro que tinha previamento alocado memoria e o tamanho da nova memoria utilizando o sizeof()*tamanho, e
  retorna um ponteiro para a primeira posição do array

  - Se o ponteiro para o bloco de memoria previamento alocado for NULL então a função realloc() irá alocar memoria do mesmo modo como
  a função malloc()

-----------------------------------------------------------------------------------------*/