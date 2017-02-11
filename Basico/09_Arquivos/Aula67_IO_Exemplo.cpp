#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 

int main(){

  FILE *f1, *f2;
  int fechou1, fechou2;
  char caracter;

  f1 = fopen("doc/arquivo.txt", "r");
  f2 = fopen("doc/arquivo1.txt", "w");

  if(f1 == NULL || f2 == NULL){
    printf("Erro na abertura dos arquivos!");
    exit(1);
  }

  caracter = fgetc(f1);
  while(caracter != EOF){
    fputc(toupper(caracter), f2);
    caracter = fgetc(f1);
  }

  fechou1 = fclose(f1);
  fechou2 = fclose(f2);

  if(fechou1 != 0 || fechou2 != 0) {
    printf("Erro no fechamento dos arquivos!");
  }

	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  EXEMPLO:

    - Vamos ler um arquivo contendo o texto em minusculo e criar outro arquivo com o 
    mesmo texto em maiusculo


---------------------------------------------------------------------------------------- */
