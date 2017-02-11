#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

  FILE *f;
  int fechou;
  char caracter;

  f = fopen("doc/arquivo.doc", "r");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  caracter = fgetc(f);
  while(caracter != EOF){
    printf("%c", caracter);
    caracter = fgetc(f);
  }
  printf("\n");

  fechou = fclose(f);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!");
  }

	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Para ler um caracter por vez dentro de um arquivo usamos a função fgetc()

  DECLARAÇÃO:

      int fgetc(FILE *f);

  RETORNO:

    - Retorna em caso de erro a constante EOF e em caso de sucesso o caractere lido do
    arquivo

  OBSERVAÇÃO:

    - Para ler todos os caracteres do arquivo sem saber o tamanho dele usa-se o EOF =
    End of File

    - Quando atingimos o final de um arquivo a função sempre retorna o EOF


----------------------------------------------------------------------------------------- */
