#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
  int matricula;
  char nome[30];
  float p1, p2, p3;
};

typedef struct aluno ALUNO;

void insertionSortMatricula(ALUNO *aluno, int quantidade) {
  int i, j;
  ALUNO auxiliar;
  for(i=1; i<quantidade; i++) {
    auxiliar = aluno[i];
    for(j=i; (j>0) && (auxiliar.matricula < aluno[j-1].matricula); j--)
      aluno[j] = aluno[j-1];
    aluno[j] = auxiliar;
  }
}

void insertionSortNome(ALUNO *aluno, int quantidade) {
  int i, j;
  ALUNO auxiliar;
  for(i=1; i<quantidade; i++) {
    auxiliar = aluno[i];
    for(j=i; (j>0) && (strcmp(auxiliar.nome, aluno[j-1].nome) < 0); j--)
      aluno[j] = aluno[j-1];
    aluno[j] = auxiliar;
  }
}

void imprimir(ALUNO *aluno) {
  int i;
  for(i=0; i<4; i++)
    printf("(%d) %s\n", aluno[i].matricula, aluno[i].nome);
}

int main() {

  ALUNO aluno[4] = {
    {2, "Andre", 9.5, 8.6, 8.5},
    {4, "Ricardo", 7.5, 8.7, 6.8},
    {1, "Bianca", 9.7, 6.7, 8.4},
    {3, "Ana", 5.7, 6.1, 7.4}
  };

  insertionSortNome(aluno, 4);
  imprimir(aluno);

  printf("\n");

  insertionSortMatricula(aluno, 4);
  imprimir(aluno);


  return 0;
}

/* strcmp(str1, str2) {
    == 0: Se as strings forem iguais
     > 0: Se a string1 vem depois da string2 no alfabeto
     < 0: Se a string1 vem antes da string2 no alfabeto
}*/
