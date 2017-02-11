#include <stdlib.h>
#include <stdio.h> 

//NÃO FUNCIONA NO TERMINAL

int main(){

  int *p = 0x5DC; //1500
  char *c = 0x5DC; //1500

  p++; //1504
  c++; //1501
 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  ATRIBUIÇÃO: 
      Ponteiro só podem receber o endereço de uma variável do mesmo tipo do ponteiro.
      Ponteiro pode apontar para outro ponteiro, desde que sejam do mesmo tipo.

    - Sobre o valor de endereço armazenado por um ponteiro, podemos somente somar e subtrair valores
    INTEIROS a esse ponteiros.

  ENDEREÇO NA MEMÓRIA OCUPADO PELO PONTEIRO P:

      int *p = 0x5DC; //1500 a 1503
      p++;            //1504 a 1508
      p = p+15;       //1504 + 15*4 = 1564 a 1568
      p -= 2;         //1564 - 2*4 = 1556 a 1560

  TIPO DE PONTEIRO:

      Ponteiros para inteiro cada posição soma-se 4 ou diminui 4
      Ponteiro para int = 4
      Ponteiro para long = 8
      Ponteiro para short = 2
      Ponteiros para double = 8
      Ponteiros para char  = 1

  OBSERVAÇÕES:

    - Não podemos multiplicar, dividir e nem somar ou subtrair ponteiros

    - Ponteiro podem ser comparados:
      ==, !=, >, <, <=, >=

      == e != compara se os ponteiros apontam para o mesmo lugar ou lugares diferentes
      > < compara se um ponteiro está na frente(>) ou atrás(<) de outro ponteiro na memória

	
----------------------------------------------------------------------------------------*/