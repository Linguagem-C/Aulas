#include <string.h>
#include <stdio.h>

int verifica(char *str1, char *str2, int len1, int len2) {
	if(len1 == 0 && len2 == 0) return 1;
	if(*str1 != *str2) return 0;
	return verifica(str1 + 1, str2 + 1, len1 - 1, len2 - 1);
}

int eh_igual(char *str1, char *str2) {
	return verifica(str1, str2, strlen(str1), strlen(str2));
}

int main() {

	char palavra1[255], palavra2[255];
  printf("Informe a palavra1: ");
  scanf("%s", palavra1);
  printf("Informe a palavra2: ");
  scanf("%s", palavra2);

	if(eh_igual(palavra1, palavra2))
	  printf("Sào iguais\n");
	else
	  printf("São diferentes\n");

	return 0;
}