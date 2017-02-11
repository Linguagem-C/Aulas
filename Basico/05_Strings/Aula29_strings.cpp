#include <stdio.h>
#include <stdlib.h>

int main() {

	char frase[20], string3[20];
	char string1[20] = {'O','i','t','e','n','t','a','\0'};
	char string2[20] = "Teste";
	sprintf(string3, "Teste de novo");
	string1[2] = '\0';
	string2[0] = 'L';

	printf("Digite a frase: ");
	fgets(frase, 20, stdin);

	printf("Palavra lida: %s\n", frase);
	printf("A string1 é %s\n", string1);
	printf("A string2 é %s\n", string2);
	printf("A string3 é %s\n", string3);


	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

STRING:

	Definição:

		- String é um array de caracteres.

		- Permite armazenar uma sequência de caracteres adjacentes na memória.	

		- Podemos dizer que são palavras, frases ou textos.

	Exemplo:

		char nome[tamanho];
		char string[20];

	Observações:

		- String usa-se o %s

		- \0 indica fim de string, desconsidera oq vier depois dele

		- A inicialização de string sempre use aspas duplas ""

		- Não precisa do & no scanf

		- scaf("%s", variavel); a palavra é lida até o teclar do ENTER ou ESPAÇO

		- fgets(variavel, tamanho, stdin); a palavra é lida até o teclar do ENTER


----------------------------------------------------------------------------- */