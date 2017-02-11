#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 

int main(){

  FILE *f;
  int fechou;
  char caracter;

  f = fopen("doc/arquivo.txt", "r");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  caracter = fgetc(f);
  while(!feof(f)){
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

    - Quando manipulamos dados binarios, um valor inteiro igual ao valor da constante EOF 
    pode ser lido.

    - Para evitar esse tipo de situação a linguagem C inclui a função feof()

  DECLARAÇÃO:

      int feof(FILE *f);

  RETORNO:

    - Essa função retorna um valor inteiro igual a zero se ainda não tiver atingido o 
    final do arquivo.

  OBSERVAÇÃO:

    - L19: !0 = Verdadeiro -> feof() ainda não achou o fim do arquivo, logo continua o 
    laço
    - L19: !1 = Falso -> o feof() retornou 1 logo achou o fim do arquivo então vamos 
    quebrar o laço

--------------------------------------------------------------------------------------- */
