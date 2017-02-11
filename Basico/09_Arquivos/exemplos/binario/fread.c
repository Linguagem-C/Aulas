#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct cadastro {
  char nome[50], endereco[30];
  int idade;
};

int main(){

  FILE *f;
  int total_lido, tl1, tl2, tl3;
  int v[5] = {1, 2, 3, 5, 7};
  char str[20] = "Hello World";
  float x = 5;
  int fechou;
  struct cadastro cad = {"Andre Ferreira", "Rua 26 Norte", 22};

  f = fopen("doc/vetor.txt", "rb");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  total_lido = fread(v, sizeof(int), 5, f);
  tl1 = fread(str, sizeof(char), 20, f);
  tl2 = fread(&x, sizeof(float), 1, f);
  tl3 = fread(&cad, sizeof(struct cadastro), 1, f);

  if(total_lido != 5 || tl1 != 20 || tl2 != 1 || tl3 != 1) {
      printf("Erro na escrita do arquivo!\n");
      exit(1);
  }

  fechou = fclose(f);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!");
  }

  printf("%d, %d, %d, %d, %d\n", v[0], v[1], v[2], v[3], v[4]);
  printf("%s\n", str);
  printf("%.2f\n", x);
  printf("%s, %s, %d\n", cad.nome, cad.endereco, cad.idade);


  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Para ler um bloco de bytes em um arquivo, utilizamos a função fread()

  DECLARAÇÃO:

    int fread(void *buffer, int bytes, int count, FILE *f);

  PARAMETROS:

    buffer = Ponteiro generico para os dados, onde na memoria está os dados que eu quero ler do arquivo.

    bytes = tamanho, em bytes, de cada unidade de dado a ser gravada, sizeof().

    count = total de unidades de dados que devem ser gravada, tamanho do array que sera lido.

    f = O ponteiro para o arquivo.

  RETORNO

    Retorna o total de unidades de dados gravadas com sucesso, ou seja, retorna o count se der tudo certo.


----------------------------------------------------------------------------------------- */
