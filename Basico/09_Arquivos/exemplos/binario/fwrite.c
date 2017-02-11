#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

struct cadastro {
  char nome[50], endereco[30];
  int idade;
};

int main(){

  FILE *f;
  int total_gravado, td1, td2, td3;
  int v[5] = {1, 2, 3, 5, 7};
  char str[20] = "Hello World";
  float x = 5;
  int fechou;
  struct cadastro cad = {"Andre Ferreira", "Rua 26 Norte", 22};

  f = fopen("doc/vetor.txt", "wb");

  if(f == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }

  total_gravado = fwrite(v, sizeof(int), 5, f);
  td1 = fwrite(str, sizeof(char), 20, f);
  td2 = fwrite(&x, sizeof(float), 1, f);
  td3 = fwrite(&cad, sizeof(struct cadastro), 1, f);

  if(total_gravado != 5 || td1 != 20 || td2 != 1 || td3 != 1) {
      printf("Erro na escrita do arquivo!\n");
      exit(1);
  }

  fechou = fclose(f);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!");
  }

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - As funçes de escrita de blocos de bytes permitem escrever dados mais complexos, como os tipos int, float e double, array ou mesmo
    um tipo definido pelo programador com a struct.

    - Elas devem ser usadas preferenciamente com arquivos binarios.

    - Para escrever um bloco de bytes em um arquivo, utilizamos a função fwrite()

  DECLARAÇÃO:

    int fwrite(void *buffer, int bytes, int count, FILE *f);

  PARAMETROS:

    buffer = Ponteiro generico para os dados, onde na memoria está os dados que eu quero gravar no arquivo.

    bytes = tamanho, em bytes, de cada unidade de dado a ser gravada, sizeof().

    count = total de unidades de dados que devem ser gravada, tamanho do array que sera gravado.

    f = O ponteiro para o arquivo.

  RETORNO

    Retorna o total de unidades de dados gravadas com sucesso, ou seja, retorna o count se der tudo certo.


----------------------------------------------------------------------------------------- */
