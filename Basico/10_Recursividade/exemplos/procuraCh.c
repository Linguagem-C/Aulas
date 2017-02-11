#include <string.h>
#include <stdio.h>

void remove_line_break(char *string) {
  
  size_t size;

  size = strlen(string);

  /* remove '\n' e atualiza o tamanho */
  if (string[size - 1] == '\n'){
    string[--size] = 0;
  }
}

int procura(char *str, int len, char ch) {
	if(len == 0) return 0;
	if(*str == ch) return 1;
	return procura(str+1, len-1, ch);
}

int procura_caracter(char *str, char ch) {
	return procura(str, strlen(str), ch);
}

int main() {

	char caracter;
	char string[255];

	printf("Insira a string: ");
	fgets(string, 255, stdin);
	remove_line_break(string);

	printf("Insira o caracter que deseja procurar na string: ");
	scanf("%c", &caracter);

	if(procura_caracter(string, caracter))
	  printf("Achei o caracter %c\n", caracter);
	else
	  printf("Não achei o caracter\n");

	return 0;

}