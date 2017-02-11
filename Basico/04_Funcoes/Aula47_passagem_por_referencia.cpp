#include <stdlib.h>
#include <stdio.h> 

void soma_mais_um(int *n){
  *n = *n + 1;
  printf("Dentro da função: x = %d\n", *n);
}

int main(){
  
  int x = 5;

  printf("Antes da função: x = %d\n", x);

  soma_mais_um(&x);

  printf("Depois da função: x = %d\n", x);

	 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - A linguagem C permite dois tipos de passagem de parâmetros para uma função, 
  por valor e por referencia.

  - Por referencia = dado original (endereço) é passado

  - O endereço de onde o dado foi armazenado na memória é passado para a função

  - Assim a função pode modifica o valor do parâmetro

  - A variavel x fora da função é influenciada por codigos dentro da função, já que foi
  passada o endereço de memória da variavel para a função

  - A função scanf usa passagem por referencia

  - A função por referencia precisa passar um ponteiro como parametro (*) e quando chamar a função
  usar um & e comercial como parametro

  - * = referencia ao endereço, aponta para o endereço

  - & = Endereço na memória
	
----------------------------------------------------------------------------------------*/