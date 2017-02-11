#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct aluno {
  int matricula;
  char nome[30];
  float P1, P2, P3;
};

typedef struct elemento *LISTA;
typedef struct aluno ALUNO;

int abertura();
void menu(int opcao_abertura, LISTA *lista, ALUNO aluno);
LISTA *criar_lista();
void liberar_lista(LISTA *lista);
int tamanho_lista(LISTA *lista);
int lista_vazia(LISTA *lista);
int inserir_inicio_da_lista(LISTA *lista, ALUNO aluno);
int inserir_final_da_lista(LISTA *lista, ALUNO aluno);
int inserir_lista_ordenada(LISTA *lista, ALUNO aluno);
int remover_inicio_da_lista(LISTA *lista);
int remover_final_da_lista(LISTA *lista);
int remover_da_lista(LISTA *lista, int matricula);
int buscar_lista_posicao(LISTA *lista, int posicao, ALUNO *aluno);
int buscar_lista_matricula(LISTA *lista, int matricula, ALUNO *aluno);
int mostrar_lista(LISTA *lista);
