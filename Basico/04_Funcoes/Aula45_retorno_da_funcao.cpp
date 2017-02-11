#include <stdlib.h>
#include <stdio.h>
#include <math.h>
 
void imprimir (int n){
    int i;
    for(i=1; i<=n; i++){
        printf("Linha %d\n", i);
    }
}

int soma(int x, int y){
    return x+y;
}

int maior(int x, int y) {
    if (x > y)
        return x;
    else
        return y;
}

int main(){
  
    imprimir(5);
    
    int x = soma(4,5);
    printf("Soma = %d\n", x);

    printf("O maior é %d\n", maior(4,5));
	 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

  	- É como uma função devolve seu resultado (se ele existir) para quem a chamou

  DECLARAÇÃO:

      tipo nomeDaFunção (Parametros){
        conjunto de codigos
        return expressão;
      }

  OBSERVAÇÕES:

    - return tem que ser do mesmo tipo declarado no escopo da função

    - Podemos retornar os tipos: int, char, float, double, void, struct, ponteiros.

    - Função do tipo void não tem retorno.

    - Assim que o return é executado a função quebra

    - Sempre que a função retorna um valor tem que ter alguém do mesmo tipo para receber o valor
    na main

    - Um array só pode ser retornando se ele estiver dentro de uma struct
	
---------------------------------------------------------------------------------------- */