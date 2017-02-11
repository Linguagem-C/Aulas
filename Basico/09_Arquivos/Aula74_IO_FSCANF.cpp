#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 

int main(){

  FILE *f;
  int fechou;
  char nome[20], texto[30];
  int idade;
  float altura;

  f = fopen("doc/arquivo.txt", "r");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  fscanf(f, "%s %s", texto, nome);
  printf("%s %s\n", texto, nome);
  fscanf(f, "%s %d", texto, &idade);
  printf("%s %d\n", texto, idade);
  fscanf(f, "%s %f", texto, &altura);
  printf("%s %.2f\n", texto, altura);

  fechou = fclose(f);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!");
  }

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - A linguagem C também permite ler uma lista formatada de variáveis do arquivo do mesmo modo que como faziamos do teclado
  do computador com a função scanf()

DECLARAÇÃO:

    scanf("tipo de saida", &variaveis);
    fscanf(FILE *f, "tipo de saida", &variaveis);

---------------------------------------------------------------------------------------- */
