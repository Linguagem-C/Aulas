#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void salvar() {
  int V[5] = {10, 20, 30, 40 ,50};
  int i;
  FILE *f = fopen("ArquivosIO/arquivo.txt", "w");
  if(f == NULL){
    printf("Erro na abertura\n");
    exit(1);
  }
  for(i=0; i<5; i++){
    fprintf(f, "%d\n", V[i]);
  }
  fclose(f);
}

void carregar() {
  int n;
  FILE *f = fopen("ArquivosIO/arquivo.txt", "r");
  if(f == NULL){
    printf("Erro na abertura\n");
    exit(1);
  }
  /*while(!feof(f))*/
  while(1){
    fscanf(f, "%d", &n);
    if(feof(f)){
      break;
    }
    printf("%d\n", n);
  }
  fclose(f);
}

int main(){

  salvar();
  carregar();

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Um mal uso muito comum da função feof() é usar a função para terminar um loop.

  DECLARAÇÃO:

    int feof(FILE *stream);

  RETORNO:

    - A função feof() testa o indicador de fim de arquivo para o fluxo apontado por stream

    - A função feof() retorna diferente de zero se e somente se  o indicador de fim de 
    arquivo está marcado para o stream

  OBSERVAÇÕES:

    - Ela testa o indicador de fim de arquivo e não o arquivo, isto indica que outra função é
    responsavel por alterar o indicador para indicar que o EOF foi alcançado.

    - A maioria das funções de leitura irá alterar o indicador após ler todos os dados, e então
    realizar uma nova leitura resultando em nunhum dado, apenas o EOF.

    - Por isso é bom evitar o uso da função feof() para testar loops.

    - Devemos verificar o valor retornado pelas funções de leitura e encerrar o loop se uma delas
    falhar.

    - Se há erro de leitura a função ferror() irá retornar verdadeiro.

    - Porem podemos ao inves de usa em um loop, usa-lo como um criterio de parada caso a função de
    leitura não achar mais dados.

------------------------------------------------------------------------------------------ */