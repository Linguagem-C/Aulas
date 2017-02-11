#include "lib/qsort.h"

int main() {

  int i, vet[10] = {23, 4, 67, -8, 54, 90, 21, 14, -5, 1};
  ALUNO aluno[4] = {
    {2, "Andre", 9.5, 8.6, 8.5},
    {4, "Ricardo", 7.5, 8.7, 6.8},
    {1, "Bianca", 9.7, 6.7, 8.4},
    {3, "Ana", 5.7, 6.1, 7.4}
  };

  printf("\n");

  qsort(vet, 10, sizeof(int), comparaCrescente);
  for(i=0; i<10; i++)
    printf("v[%d] = %d\n", i, vet[i]);

  printf("\n");

  qsort(vet, 10, sizeof(int), comparaDecrescente);
  for(i=0; i<10; i++)
    printf("v[%d] = %d\n", i, vet[i]);

  printf("\n");

  qsort(aluno, 4, sizeof(ALUNO), comparaMatricula);
  for(i=0; i<4; i++)
    printf("(%d) %s\n", aluno[i].matricula, aluno[i].nome);

  printf("\n");

  qsort(aluno, 4, sizeof(ALUNO), comparaNome);
  for(i=0; i<4; i++)
    printf("(%d) %s\n", aluno[i].matricula, aluno[i].nome);

  printf("\n");
  return 0;
}
