#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX 100

struct livraria {
  int codigo;
  char titulo[50];
};

typedef struct pilha PILHA;
typedef struct livraria LIVRARIA;

int abertura();
void menu(int opcao_abertura, PILHA *pilha, LIVRARIA livro);
PILHA *criar_pilha();
void liberar_pilha(PILHA *pilha);
int tamanho_da_pilha(PILHA *pilha);
int pilha_cheia(PILHA *pilha);
int pilha_vazia(PILHA *pilha);
int entrar_na_pilha(PILHA *pilha, LIVRARIA livro);
int sair_da_pilha(PILHA *pilha);
int consultar_pilha(PILHA *pilha, LIVRARIA *livro);
void mostrar_pilha(PILHA *pilha);
