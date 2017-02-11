#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char str1[20] = "Hello ";
	char str2[30];
	char str3[20] = "Word!";
	
	int tamanho = strlen(str1);
	strcpy(str2, str1);

	if (strcmp(str1, str2) == 0) {
		printf("São iguais!\n");
	}else{
		printf("São diferentes!\n");
	}

	printf("O str1 tem %d caracteres\n", tamanho);
	printf("Copia de str1: %s\n", str2);
	
	strcat(str1, str3);

	printf("concatenação: %s\n", str1);


	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

STRING:

	DEFINIÇÃO:

		- A linguagem C possui algumas funções para a manipulação de strings

		- A biblioteca <string.sh>

		- A concatenação copia e etc vai sempre da direita para a esquerda

	ALGUMAS FUNÇÕES DA BIBLIOTECA:

		strlen(string) = Tamanho da string
		strcpy(novastring, string) = Copiar uma string
		strcat(string1, string2) = Concatenar 2 strings
		strcmp(string1, string2) = Comparar duas strings, se der 0 são iguais

	OBSERVAÇÕES:

		- A linguagem C é case sensitive então maiusculo é diferente de minusculo

		- Copiar uma string = strcpy
				for(i=0; str1[i]!='\0'; i++){
					str2[i] = str1[i];
				}
				str2[i] = '\0';


---------------------------------------------------------------------------- */