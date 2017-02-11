#include <stdlib.h>
#include <stdio.h> 

struct ponto {
  int x, y;
};

void imprimir_valor(int n){
  printf("Valor = %d\n", n);
}

void soma_imprime_valor(int *n){
  *n = *n +1;
  printf("Valor = %d\n", *n);
}

void atribui(struct ponto *p){
  (*p).x = 10;
    p->y = 20;
}

int main(){

  struct ponto p1 = {10, 20};
  
  /* Passando um campo por valor */
  imprimir_valor(p1.x);
  imprimir_valor(p1.y);

  /* Passando um campo por referencia */
  soma_imprime_valor(&p1.x);
  soma_imprime_valor(&p1.y);

  /* Passando uma struct por referencia */
  atribui(&p1);
  printf("x = %d\n", p1.x);
  printf("x = %d\n", p1.y);
  
	 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - Quando trabalhamos com struturas podemos passar somente um campo ou toda a estrutura,
  tanto como valor como por referencia

  - Passagem de valor e por referencia por campo, o tipo do parametro da função tem que ser o 
  mesmo do tipo do campo da estrutura que irá ser passado.

  - Na passagem por referencia de uma struct os valores tem que ser entre parenteses, pois tem
  que ser passado por referencia é a struct p não o x ou y

  - Ao inves de usar o parenteses podemos usa a seta -> para referir a passagem por referencia
  de structs, elas são equivalentes

  
	
----------------------------------------------------------------------------------------*/