#include "lib/alocar-string-vetor.h"

void escrever(char *texto, int tamanho) {
  printf("Escreva uma frase: ");
  fgets(texto, tamanho, stdin);
  remover_quebra_de_linha(texto);
}

int main() {

  /* char *array_de_strings[5] = {"string1", "string2", "string3", "string4", "string5"}; */

  char *texto1[5][100];
  char *string;
  /*char **texto2;
  int qtd;*/

  fgets(string, 100, stdin);
  strcpy(*texto1[0], string);


  /*
  printf("Insira a quantidade de strings: ");
  scanf("%d", &qtd);
  flush_in();

  texto = alocar_vetor_strings(qtd);

  escrever_strings(texto, qtd);*/

  return 0;
}
