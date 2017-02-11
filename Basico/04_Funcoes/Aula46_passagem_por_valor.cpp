#include <stdlib.h>
#include <stdio.h> 

void soma_mais_um(int n){
  n++;
  printf("Dentro da função: x = %d\n", n);
}

int main(){
  
  int x = 5;

  printf("Antes da função: x = %d\n", x);

  soma_mais_um(x);

  printf("Depois da função: x = %d\n", x);

	 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - A linguagem C permite dois tipos de passagem de parâmetros para uma função, 
  por valor e por referencia.

  - Por valor = Copia do dado (padrão)

  - Uma copia do dado é feita e passada para a função

  - É o modo padrão para os tipos básicos pré-definidos: int, float, double, char
  e tipos definidos pelo programados: structs 

  - A variavel x fora da função não é influenciada por codigos dentro da função, já que foi
  passada só uma copia da variavel para a função
	
------------------------------------------------------------------------------------------ */