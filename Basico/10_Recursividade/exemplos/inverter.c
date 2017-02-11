#include <stdio.h>

void inverte(char *string){
	if(*string) {
		inverte(string+1);
		putchar(*string);
  }
}

int main() {
   char palavra[255];
   printf("Informe a palavra: ");
   scanf("%s", palavra);

   inverte(palavra);

   printf("\n");

   return 0;
}