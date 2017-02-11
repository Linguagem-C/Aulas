#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(){

  FILE *f;
  int i, fechou;
  char texto[100] = "\nExistem cinco tipo de gestões: pessoal, produto, processo, projeto e material.\n";

  f = fopen("doc/arquivo.doc", "a+");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

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
