#include <stdlib.h>
#include <stdio.h> 

int main(){

  int **p;
  int i, j;
  int linha;
  int coluna;

  printf("insira a linha da matriz: ");
  scanf("%d", &linha);
  printf("insira a coluna da matriz: ");
  scanf("%d", &coluna);

  //Alocar matriz
  p = (int**) malloc(linha * sizeof(int *));
  for(i=0; i<linha; i++){ 
    p[i] = (int *) malloc(coluna * sizeof(int));
    
    for(j=0; j<coluna; j++){
      printf("Matriz[%d][%d]: ", i, j);
      scanf("%d", &p[i][j]);
    }

  }

  printf("\n\n");

  //Imprimir matriz
  for(i=0; i<linha; i++){
    for(j=0; j<coluna; j++){
      printf("%d ", p[i][j]);
    }
    printf("\n");
  }

  printf("\n\n");

  //Liberar memória
  for(j=0; j<linha; j++){
     free(p[i]);
    }
  free(p);

	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Para alocar array de mais de uma dimensão, devemos utilizar o conceito de ponteiros 
    para ponteiros

    - Para criar uma matriz precisamos de um ponteiro de nivel 2: int **v

    - L9: Criamos um array do tipo int** de int*

  EXEMPLO:

           1° malloc    2° malloc
    int** -> int* -> int int int int
          -> int* -> int int int int
          -> int* -> int int int int
          -> int* -> int int int int

    1° malloc cria as linhas da matriz
    2° malloc cria as colunas da matriz

----------------------------------------------------------------------------------------*/