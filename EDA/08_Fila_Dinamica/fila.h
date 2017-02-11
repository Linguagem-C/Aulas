#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

struct aluno {
  int matricula;
  char nome[30];
  float P1, P2, P3;
};

typedef struct fila FILA;
typedef struct aluno ALUNO;

int abertura();
void menu(int opcao_abertura, FILA *fila, ALUNO aluno);
FILA *criar_fila();
void liberar_fila(FILA *fila);
int tamanho_da_fila(FILA *fila);
int fila_cheia(FILA *fila);
int fila_vazia(FILA *fila);
int entrar_na_fila(FILA *fila, ALUNO aluno);
int sair_da_fila(FILA *fila);
int consultar_fila(FILA *fila, ALUNO *aluno);
void mostrar_fila(FILA *fila);
