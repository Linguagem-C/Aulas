#include <stdlib.h>
#include <stdio.h> 

int main(){

  void *pg;
  int *p1, p2=10;

  p1 = &p2;

  pg = &p2; //Endereço pro tipo int
  printf("Endereço em pg: %p\n", pg);

  pg = &p1; //Endereço pro tipo *int
  printf("Endereço em pg: %p\n", pg);

  pg = p1; //Endereço pro tipo int
  printf("Endereço em pg: %p\n", pg);

  printf("Conteudo em pg: %d\n", *(int*)pg);

 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO: 

  - Ponteiro generico pode apontar para todos os tipos de dados existentes ou que ainda serão criados
    void *NomeDoPonteiro;

  - Sempre aponta para um endereço, não importa  o tipo

  - Antes de acessar o conteúdo do endereço é preciso converter o ponteiro generico para o tipo de
  ponteiro que se deseja trabalhar.

  - As operações aritmeticas são sempre realizadas com base em uma unidade de memória como no char
  (1 byte)

	
----------------------------------------------------------------------------------------*/