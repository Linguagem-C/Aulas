#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct aluno {
  int matricula;
  char nome[30];
  float nota1, nota2, nota3;
};

typedef struct aluno ALUNO;
typedef struct elemento *LISTA;

void remover_quebra_de_linha(char *string);
void limpar_buffer();
int abertura();
int adicionar_aluno();
int remover_aluno();
int buscar_aluno();
void inserir_dados_aluno(ALUNO *aluno);
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
