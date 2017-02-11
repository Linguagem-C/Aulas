#include <stdio.h>
#include <stdlib.h>

int main(){

  int *array_ponteiros[2];
  int x=10, y[2] = {30, 40};

  array_ponteiros[0] = &x; /* armazena o endereço de memória de x */
  array_ponteiros[1] = y; /* armazena o endereço de memória do primeiro elemento do vetor y */

  /* Imprime o endereço de memória de ambos */
  printf("array_ponteiros[0] = %p\n", array_ponteiros[0]); //&x
  printf("array_ponteiros[1] = %p\n", array_ponteiros[1]); //&y[0]

  /* Imprime o valor que está dentro de ambos */
  printf("*array_ponteiros[0] = %d\n", *array_ponteiros[0]);      //x
  printf("array_ponteiros[1][1] = %d\n", array_ponteiros[1][1]);  //y[1]

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
