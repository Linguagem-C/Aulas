#include <stdlib.h>
#include <stdio.h>
#include <string.h> 

int main(){

  FILE *f;
  int i, fechou;

  f = fopen("doc/arquivo.txt", "w");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  char texto[70] = "Aula64 - Função FPUTC() retorna apenas um caracte por vez!";

  for(i=0; i<strlen(texto); i++){
    fputc(texto[i], f);
  }

  fechou = fclose(f);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!");
  }

	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Escreve um único caractere em um arquivo.

  DECLARAÇÃO:

      int fputc(char c, FILE *arquivo)

  RETORNO:

    - Em caso de erro a retorna a constante EOF

    - Em caso de sucesso retorna o arquivo o codigo ASCII do caractere adicionado


--------------------------------------------------------------------------------------- */
