#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct aluno {
  int matricula;
  char nome[30];
  float nota1, nota2, nota3;
};

typedef struct aluno ALUNO;
typedef struct NO *ARVORE;

int adicionar_aluno();
int abertura();
void menu(int opcao_abertura, ARVORE *raiz, ALUNO aluno);

ARVORE *criar_arvore_binaria();
void liberar_arvore_binaria(ARVORE *raiz);
int esta_vazia(ARVORE *raiz);
int altura_da_arvore(ARVORE *raiz);
int total_de_nos(ARVORE *raiz);
void percorrer_arvore_pre_ordem(ARVORE *raiz);
void percorrer_arvore_em_ordem(ARVORE *raiz);
void percorrer_arvore_pos_ordem(ARVORE *raiz);
int inserir_no(ARVORE *raiz, int matricula);
int remover_no(ARVORE *raiz, int matricula);
int consulta_arvore_binaria(ARVORE *raiz, int matricula);


