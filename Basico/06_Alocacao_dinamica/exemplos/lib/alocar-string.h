#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
 
char *alocar_string(int tamanho) {
  char *texto = (char*) malloc(tamanho + 1);
  return texto;
}

void escrever(char *texto, int tamanho) {
  printf("Escreva uma frase: ");
  fgets(texto, tamanho, stdin);
  remover_quebra_de_linha(texto);
}

void imprimir(char *texto) {
  printf("%s\n", texto);
}
