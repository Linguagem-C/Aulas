#include <stdlib.h>
#include <stdio.h>
 
int main(){

  char *array_de_strings[5] = {"string1", "string2", "string3", "string4", "string5"};

  int *parray[2];
  int x=10, y[2] = {30, 40};

  parray[0] = &x;
  parray[1] = y;

  printf("parray[0] = %p\n", parray[0]); //&x
  printf("parray[1] = %p\n", parray[1]); //&y[0]

  printf("*parray[0] = %d\n", *parray[0]); //x
  printf("parray[1][1] = %d\n", parray[1][1]); //y[1]



	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Array: Conjunto de dados armazenados de forma sequencial na memória.

    - O vetor sempre aponta pra primeira posição dele.

    - O nome do array é como se fosse um ponteiro que aponta para o primeiro elemento do Array.

    - Mesma coisa que a gente fazia na passagem por referencia.

  DECLARAÇÕES:

    - A anotação de colchetes é apenas uma simplificação da aritmetica de ponteiros com acesso ao conteúdo
      p[1] = *(p+1)

    - Podemos também acessar o endereço de cada posição
      &p[1] = (p+1)

    - Também podemos declarar um array de ponteiros
      tipo *NomeDoArray[tamanho];

      int *vet[5]; = Criei um vetor de 5 posições, só que cada uma dessas posições é um ponteiro para inteiros
      logo criei um vetor de endereços

  OBSERVAÇÕES:

    - Com um vetor de ponteiros eu consigo criar uma matriz


----------------------------------------------------------------------------------------*/
