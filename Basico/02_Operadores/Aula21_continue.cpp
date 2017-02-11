#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b, i;

	printf("Digite o valor de a: ");
	scanf("%d", &a);
	printf("Digite o valor de b: ");
	scanf("%d", &b);

	for(i=a; i<=b; i++){
		if(i%2 == 0){
			continue;
		}
		printf("%d\n", i);
	}

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

COMANDO CONTINUE:
	- O Comando Continue, é um comando para controle de laço, semelhante ao Break. 
	A diferença entre ambos, é que o comando Continue faz um salto para a próxima 
	rotação do laço, enquanto o comando Break faz o salto para fora do laço.

	repetição(condição){
		if(condição)
			continue;
	}

	- No momento que satisfazer a condição do if o comando continue 
	vai pular uma iteração do laço de repetição
	
-----------------------------------------------------------------------------*/