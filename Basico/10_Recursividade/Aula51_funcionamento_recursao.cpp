#include <stdlib.h>
#include <stdio.h> 

int fatorial(int n) {
  if(n == 0) //Criterio de parada
    return 1;
  else //Parâmetro da chamada recursiva 
    return n*fatorial(n-1);
  
}

//Evite fazer esse tipo de recursividade
int fibonati(int n){
  if ((n==0) || (n==1))
    return n;
  else
    return fibonati(n-1)+fibonati(n-2); 
}

int main(){

  int x = fatorial(5);

  printf("%d\n", x);
  
	 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

FUNCIONAMENTO:

  - A ideia basica da recursão é dividir e conquistar:

    Dividir os problemas maiores em problemas menores 
    Solucionar os problemas menores
    Combinar soluções dos problemas menores para solucionar o problema maior

  - Durante a implementação de uma função recursiva temos que ter em mente 2 coisas:

    Críterio de parada.
    Parâmetro da chamada recursiva.

  - Criterio de parada: determina quando a função deve parar de chamar a si mesma.

  - Parâmetro de chamada recursiva: Devemos sempre mudar o valor do parâmetro passado, de uma forma
  que a recursão chegue ao criterio de parada.

  - Algoritmos recursos precisa de mais tempo ou/e espaço do que algoritmos iterativos, um bom
  exemplo é a fibonatti que utilizando recursividade para fazer vai ser extremamente lenta e 
  ocupará ume espaço enorme de memória, pois terá um excesso de calculo repetido.


  
	
----------------------------------------------------------------------------------------*/