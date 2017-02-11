#include <stdlib.h>
#include <stdio.h> 

int Somatorio(int n){
  if (n==0)
    return 0;
  else
    return n + Somatorio(n-1);
}

int main(){

  int soma = Somatorio(155);

  printf("%d\n", soma);
  
	 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

SOMATORIO DE 1 ATÉ N

  soma(4) = 4+3+2+1+0 = 4+soma(3)
  soma(3) = 3+2+1+0 = 3+soma(2)
  soma(2) = 2+1+0 = 2+soma(1)
  soma(1) = 1+0 = 1+soma(0)

  CASO BASE
  soma(0) = 0

  GENERALIZAÇÃO
  soma(N) = N+soma(N-1)

	
----------------------------------------------------------------------------------------*/