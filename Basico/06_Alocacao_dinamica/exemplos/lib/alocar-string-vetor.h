#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 100

/* Limpa o buffer do teclado */
void flush_in(){
    int ch;
    do{
        ch = fgetc(stdin);
    }while (ch != EOF && ch != '\n');
}

/* remove '\n' e atualiza o tamanho */
void remover_quebra_de_linha(char *string) {
  size_t size;
  size = strlen(string);
  if (string[size - 1] == '\n'){
    string[--size] = 0;
  }
}

/*char *alocar_string(int tamanho) {
  char *texto = (char*) malloc(tamanho + 1);
  return texto;
}*/

char **alocar_vetor_strings(int qtd) {
  char **string;
  string = (char**) malloc(qtd * TAM);
  return string;
}

void escrever_strings(char **str, int qtd) {
  int i;
  char string[TAM];
  for(i=0; i<qtd; i++) {
    printf("Insira a %d° string: ", i+1);
    fgets(string, TAM, stdin);
    remover_quebra_de_linha(string);
    strcpy(str[i], string);
  }
}
