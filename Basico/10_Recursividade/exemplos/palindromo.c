#include <string.h>
#include <stdio.h>

int Verifica(char str[], int len) {
   if (len <= 1) return 1;
   if (str[0] != str[len-1]) return 0;
   return Verifica(str + 1, len - 2);
}

int EhPalindromo(char str[]) {
   return Verifica(str, strlen(str));
}

int main() {

	char palavra[255];
  printf("Informe a palavra: ");
  scanf("%s", palavra);

	if(EhPalindromo(palavra))
	  printf("É palíndromo\n");
	else
	  printf("Não é palíndromo\n");

	return 0;
}