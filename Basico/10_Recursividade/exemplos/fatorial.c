#include <stdlib.h>
#include <stdio.h> 

int fatorial(int n) {
  if(n == 0)
    return 1;
  else
    return n*fatorial(n-1);
}

int main(){
  int n;

  printf("Insira o número do fatorial: ");
  scanf("%d", &n);

  printf("%d\n", fatorial(n));
 
  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO

    - Recursividade é o ato de uma função chamar a si própria.

    - De maneira simples, uma função recursiva é uma função que chama ela mesma, 
    tendo como objetivo diminuir o problema a cada chamada.

    Criterio de parada
      if(n == 0) return 1;

    Parâmetro da chamada recursiva 
      else return n*fatorial(n-1);

  EXEMPLO:

      5! = 5 * 4!
      4! = 4 * 3!
      3! = 3 * 2!
      2! = 2 * 1!
      1! = 1 * 0!
      0! = 1

      N! = N * (N-1)!

      fim da função
	
---------------------------------------------------------------------------------------*/