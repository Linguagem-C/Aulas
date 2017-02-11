#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 
#include <string.h>

/* remove a quebra de linha da função fgets() e atualiza o tamanho */
void remover_quebra_de_linha(char *string) {
  
  size_t tamanho;

  tamanho = strlen(string);

  if (string[tamanho - 1] == '\n'){
    string[--tamanho] = 0;
  }
}

int main(){

  FILE *f;
  char string[30];
  char *resultado;
  int fechou;

  f = fopen("doc/arquivo.txt", "r");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  while(1){
    resultado = fgets(string, 30, f);
    remover_quebra_de_linha(string);

    if(resultado == NULL) {
      printf("Erro na leitura!\n");
    }else{
      printf("%s\n", string);
    }

    if(feof(f)){
      break;
    }
  }

  fechou = fclose(f);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!");
  }
 
  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Usado para se ler uma string de um arquivo

  DECLARAÇÃO:

      char* fgets(char *string, int tamanho, FILE *f);

  RETORNO:

    - Em caso de erro retorna NULL

    - Em caso de sucesso retorna um ponteiro para o primeiro caractere da string

  OBSERVAÇÕES:

    - A função fgets() lê uma string até encontrar a quebra de linha \n ou tamanho-1 caracteres que seria a string - '\0'

----------------------------------------------------------------------------------------- */
