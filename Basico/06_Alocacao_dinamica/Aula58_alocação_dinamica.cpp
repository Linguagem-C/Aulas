#include <stdio.h>
#include <malloc.h>

int main() {

       unsigned short int tamanho;
       char *string;

       printf("\nDigite o tamanho da string: ");
       scanf("%d",&tamanho);
(
       string = (char*)malloc(tamanho * sizeof(char)));
      
       printf("\nDigite a string: ");
       scanf("%s", string);
       printf("%s\n", string);

       free(string); 

       return 0;
} 

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Variavel é uma posição de memória que armazena um dado que pode ser usado pelo programa

    - A variável deve ser declarada durante a execução do programa.

    - A linguagem C permite alocar (reservar) dinamicamente (em tempo de execução) blocos de memória utilizando ponteiros.

    - A esse processo da-se o nome de Alocação Dinamica de memória

    - Vamos ter um ponteiro que irá apontar para uma quantidade de memória que iremos usar, logo iremos transformar um array
    em um ponteiro

  FUNÇÕES:
  	
    - Temos 5 funções para fazer isso: 

      malloc

      calloc

      realloc

      free

      sizeof

----------------------------------------------------------------------------------------*/