#include <stdio.h>
#include <stdlib.h>

int main() {

	int a, b;

	printf("Digite o valor de a menor que 5: ");
	scanf("%d", &a);
	printf("Digite o valor de b: ");
	scanf("%d", &b);

	while(a <= b){
		a++;
		if(a == 5)
			break;
		printf("%d\n", a);
	}

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

COMANDO BREAK:
	- Interrompe a repetição de qualquer comando de laço 
	(for, while, do-while ou switch) e continua o programa

	repetição(condição){
		if(condição)
			break;
	}

	- No momento que satisfazer a condição do if via quebrar o laço de repetição
	
-----------------------------------------------------------------------------*/