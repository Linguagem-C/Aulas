#include <stdio.h>

/*Evite fazer esse tipo de recursividade*/
int fibonacci(int num) {
   if(num==1 || num==2)
       return 1;
   else
       return fibonacci(num-1) + fibonacci(num-2);
} 

int main() {
   int n,i;

	printf("Digite a quantidade de termos da sequência de Fibonacci: ");
	scanf("%d", &n);
	printf("\nA sequência de Fibonacci e: \n");
	for(i=0; i<n; i++)
	   printf("%d ", fibonacci(i+1));

  printf("\n");

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


	
---------------------------------------------------------------------------------------*/