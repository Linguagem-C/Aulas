#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100
#define FALSE 0
#define TRUE 1
#define VAZIO 0

struct aluno{
  int matricula;
  char nome[30];
  float n1, n2, n3;
};

typedef struct lista LISTA;
typedef struct aluno ALUNO;

LISTA *criar_lista();
void liberar_lista(LISTA *list);
int tamanho_lista(LISTA *list);
int lista_cheia(LISTA *list);
int lista_vazia(LISTA *list);
int inserir_final_da_lista(LISTA *list, struct aluno fulano);
int inserir_inicio_da_lista(LISTA *list, struct aluno fulano);
int inserir_lista_ordenada(LISTA *list, struct aluno fulano);
int inserir_na_lista(LISTA *list, struct aluno fulano, int posicao);
int remover_final_da_lista(LISTA *list);
int remover_inicio_da_lista(LISTA *list);
int remover_da_lista(LISTA *list, int matricula);
int buscar_lista_posicao(LISTA *list, int posicao, struct aluno *fulano);
int buscar_lista_conteudo(LISTA *list, int matricula, struct aluno *busca);
int mostrar_lista(LISTA *list);
int abertura();
void menu(int opcao_abertura, LISTA *list, struct aluno fulano);
