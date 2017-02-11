#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 

int main(){

  FILE *f;
  int fechou;
  char nome[20] = "Gustavo";
  int idade = 32;
  float altura = 1.66;

  f = fopen("doc/arquivo.txt", "w");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  printf("Nome: %s\nIdade: %d\nAltura: %.2f\n", nome, idade, altura);
  fprintf(f, "Nome: %s\nIdade: %d\nAltura: %.2f\n", nome, idade, altura);

  fechou = fclose(f);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!");
  }

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - A linguagem C também permite escrever uma lista formatada de variáveis do arquivo do mesmo modo que como faziamos na tela
  do computador com a função printf()

DECLARAÇÃO:

    printf("tipo de saida", variaveis);
    fprintf(FILE *f, "tipo de saida", variaveis);

--------------------------------------------------------------------------------------- */
