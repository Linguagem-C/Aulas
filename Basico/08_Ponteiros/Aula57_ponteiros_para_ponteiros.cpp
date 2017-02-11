#include <stdlib.h>
#include <stdio.h> 

int main(){

   
  int x = 10;
  int *p1 = &x;
  int **p2 = &p1;

  //Endereço em p2
  printf("p2: %d\n", p2); //&p

  //Conteúdo do endereço p2
  printf("*p2: %d\n", *p2); //&x

  //Conteúdo do endereço do endereço
  printf("**p2: %d\n", **p2); //x
  

 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - A linguagem C permite criar ponteiros com diferentes niveis de apontamento: ponteiros que apontam
  para outros ponteiros.

  - p2 é um ponteiro para ponteiro que aponta para inteiro

  - É a quantidade de asteriscos na declaração do ponteiro que indica o número de níveis do ponteiro

	
----------------------------------------------------------------------------------------*/