#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

	char str1[20] = "Linguagem C";
	char str2[20];
	int i, j=0;

	for(i=strlen(str1)-1; i>=0; i--){
		str2[j] = str1[i];
		j++;
	}
	str2[j] = '\0';

	printf("String normal: %s\n", str1);
	printf("String invertida: %s\n", str2);

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

STRING:

	- Vamos inverter o conteúdo de uma string

	- strlen(str)-1 = ultimo caractere da string, o -1 é pra eliminar o '\0'

	- Como inverter a string dentro da variável original:

			i<tam/2 = Lingua

			victor tem 6 caracteres

			0 1 2 3 4 5
			V i c t o r

			c = str[i]
			str[0] = V logo c = V

			str[i] = str[tam-1-i]
			str[tam-1-i] = [6-1-0] = str[5] = r logo str[0] = r

			str[tam-1-i] = c
			str[tam-1-i] = str[5] = V

*//* ----------------------- RESUMO DO CÓDIGO -----------------------------------

	char str[20] = "Linguagem C";
	char c;

	int i, tam = strlen(str);
	for(i=0; i<tam/2; i++){
		c = str[i];
		str[i] = str[tam-1-i];
		str[tam-1-i] = c;
	}

	printf("str = %s\n", str);

}

------------------------------------------------------------------------------- */