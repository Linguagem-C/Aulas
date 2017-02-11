#include <stdlib.h>
#include <stdio.h> 

int main(){

  int i, *p_calloc, *p_malloc;

  p_calloc = (int *) calloc(5, sizeof(int));
  p_malloc = (int *) malloc(5 * sizeof(int));

  printf("calloc \t\t malloc\n");
  for(i=0; i<5; i++){
    printf("Calloc p[%d] = %d\n", i, p_calloc[i]);
    printf("Malloc p[%d] = %d\n", i, p_malloc[i]);
  }

  free(p_calloc);
  free(p_malloc);

	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - A função calloc() recebe como parâmetro o número de elementos do array a ser alocado, o tamanho de cada elemento (sizeof) e
  retorna um ponteiro para a primeira posição do array

  - O calloc() inicializa todos os bits da memória alocado com zeros, resumindo ele limpa a memória alocada antes de usar, enquanto
  o malloc() pego o lixo que já estava na memória.


-----------------------------------------------------------------------------------------*/