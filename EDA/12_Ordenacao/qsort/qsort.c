#include "lib/qsort.h"

int comparaCrescente(const void *a, const void *b) {
  if(*(int*)a == *(int*)b) {
    return 0;
  }else{
    if(*(int*)a > *(int*)b)
      return 1;
    else
      return -1;
  }
}

int comparaDecrescente(const void *a, const void *b) {
  if(*(int*)a == *(int*)b) {
    return 0;
  }else{
    if(*(int*)a < *(int*)b)
      return 1;
    else
      return 0;
  }
}

int comparaMatricula(const void *a, const void *b) {
  if((*(ALUNO*)a).matricula == (*(ALUNO*)b).matricula) {
    return 0;
  }else{
    if((*(ALUNO*)a).matricula > (*(ALUNO*)b).matricula)
      return 1;
    else
      return -1;
  }
}

int comparaNome(const void *a, const void *b) {
  int resultado = strcmp((*(ALUNO*)a).nome, (*(ALUNO*)b).nome);
  if(resultado == 0) {
    return 0;
  }else{
    if(resultado > 0)
      return 1;
    else
      return -1;
  }
}
