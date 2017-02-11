#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno {
  int matricula;
  char nome[30];
  float p1, p2, p3;
};

typedef struct aluno ALUNO;

int comparaCrescente(const void *a, const void *b);
int comparaDecrescente(const void *a, const void *b);
int comparaMatricula(const void *a, const void *b);
int comparaNome(const void *a, const void *b);
