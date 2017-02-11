#include <stdlib.h>
#include <stdio.h>


int main(){

  FILE *f;
  int fechou;

  f = fopen("doc/arquivo.txt", "w");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  char texto1[30] = "Meu programa em C\n";
  char texto2[20] = "Bom Dia!\n";
  char texto3[20] = "Outro texto!";

  int retorno1 = fputs(texto1, f);
  int retorno2 = fputs(texto2, f);
  fputs("\n", f);
  int retorno3 = fputs(texto3, f);

  if(retorno1 == EOF || retorno2 == EOF || retorno3 == EOF){
    printf("Erro na gravação do arquivo!");
  }

  fechou = fclose(f);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!");
  }

}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - A função fputs() escreve uma string em um arquivo.

  DECLARAÇÃO:

      int fputs(char *string, FILE *f);

  RETORNO:

    - Em caso de erro retorna a constante EOF

    - Em caso de sucesso retorna um valor diferente de zero.

--------------------------------------------------------------------------------------- */
