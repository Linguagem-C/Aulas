#include <stdlib.h>
#include <stdio.h>
#include <ctype.h> 

struct cadastro {
  char nome[20], endereco[20];
  int idade;
};

int main(){

  FILE *f;
  int fechou;

  f = fopen("ArquivosIO/vetor.txt", "rb");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  struct cadastro cad;
  
  fseek(f, 2*sizeof(struct cadastro), SEEK_SET);
  fread(&cad, sizeof(struct cadastro), 1, f);

  printf("%s\n%s\n%d\n", cad.nome, cad.endereco, cad.idade);

  rewind(f);
  fread(&cad, sizeof(struct cadastro), 1, f);

  printf("%s\n%s\n%d\n", cad.nome, cad.endereco, cad.idade);

  fechou = fclose(f);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!");
  }

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Outra opção de movimentação dentro do arquivo é simplismente voltar ao inicio do arquivo, para fazer
    isso usamos a função rewind()

  DECLARAÇÃO:

      void rewind(FILE *f);

  OBSERVAÇÃO:

    - Para executar esse programa, execute a Aula75 primeiro.

---------------------------------------------------------------------------------------- */