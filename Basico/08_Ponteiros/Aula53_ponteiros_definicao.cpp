#include <stdlib.h>
#include <stdio.h> 

int main(){

  int x = 10;
  int *p;

  p = &x;

  printf("x = %d\n", x);
  printf("&x = %d\n", &x);
  printf("p = %d\n", p);
  printf("*p = %d\n", *p);
	 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - Variaveis: armazena dados. (int, float, double, char e etc...)

  - Ponteiros: Tipo especial de variavel que armazena endereço de memória.

  - Declaração: tipo *NomeDoPonteiro;

  - Ponteiros não inicializados apontam para um lugar indefinido: int *p;

  - Um ponteiro pode ter um valor especial NULL, que é o endereço de lugar nenhum: int *p = NULL;

  - Podemos apontar o ponteiro para uma variável que já existe na nossa memória:
    int x = 10; //variavel x
    int *p; //ponteiro p
    p = &x; //ponteiro p aponta para o endereço de memória da variavel x

  - Para acessar o valor da variável apontada por um ponteiro, basta usar o operador asterisco (*)

	
-----------------------------------------------------------------------------------------*/