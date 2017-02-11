#include <stdlib.h>
#include <stdio.h>

int fatorial(int n){
    int i, fat=1;

    for(i=1; i<=n; i++)
        fat *= i;

    return fat;

}
 
int main(){

    int n, fat;

    printf("Digite n: ");
    scanf("%d", &n);

    fat = fatorial(n);

    printf("%d! = %d\n", n, fat);
    printf("10! = %d\n", fatorial(10));

    return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

	- O corpo da função é onde vamos processar as entradas (parametros), e gerar as saídas
	(return), é formada por declarações e comandos

	- No exemplo acima criamos uma função que calcula o fatorial de n inserido pelo usuário.

	
--------------------------------------------------------------------------------------- */