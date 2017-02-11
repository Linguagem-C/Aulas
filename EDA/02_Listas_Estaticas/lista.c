#include "lib/biblioteca.h"

struct lista {
  int quantidade;
  struct aluno alunos[MAX];
};

LISTA *criar_lista() {
  LISTA *list;
  list = (LISTA*) malloc(sizeof(LISTA));
  if(list != NULL)
    list->quantidade = 0;

  return list;
}

void liberar_lista(LISTA *list){
  free(list);
}

int tamanho_lista(LISTA *list){
  if(list == NULL){
    return VAZIO;
  }else{
    return list->quantidade;
  }
}

int lista_cheia(LISTA *list){
  int cheio;

  if(list == NULL) return FALSE;

  cheio = list->quantidade == MAX;

  return cheio;
}

int lista_vazia(LISTA *list){
  if(list == NULL){
    return FALSE;
  }
  return (list->quantidade == VAZIO);
}

LISTA *deslocar_direita(LISTA *list, int posicao){
  int i;
  for(i=tamanho_lista(list); i>=posicao; i--){
    list->alunos[i+1] = list->alunos[i];
  }

  list->quantidade++;

  return list;
}

LISTA *deslocar_esquerda(LISTA *list, int posicao){
  int i;
  for(i=posicao; i<tamanho_lista(list)-1; i++){
    list->alunos[i] = list->alunos[i+1];
  }

  list->quantidade--;

  return list;
}

int inserir_final_da_lista(LISTA *list, ALUNO fulano){

  if(list == NULL || lista_cheia(list)) return FALSE;

  printf("Insira a matricula do aluno: ");
  scanf("%d", &fulano.matricula);

  list->alunos[tamanho_lista(list)] = fulano;
  list->quantidade++;

  return TRUE;
}

int inserir_inicio_da_lista(LISTA *list, ALUNO fulano){
  int inicio_lista = 0;

  if(list == NULL || lista_cheia(list)) return FALSE;

  deslocar_direita(list, inicio_lista);

  printf("Insira a matricula do aluno: ");
  scanf("%d", &fulano.matricula);

  list->alunos[0] = fulano;

  return TRUE;
}

int inserir_lista_ordenada(LISTA *list, ALUNO fulano) {
  int posicao=0, i;

  if(list == NULL || lista_cheia(list)) return FALSE;

  printf("Insira a matricula do aluno: ");
  scanf("%d", &fulano.matricula);

  while(i<tamanho_lista(list) && list->alunos[i].matricula < fulano.matricula){
      posicao++;
  }

  deslocar_direita(list, posicao);

  list->alunos[posicao] = fulano;

  return TRUE;
}

int inserir_na_lista(LISTA *list, ALUNO fulano, int posicao){
  if(list == NULL || lista_cheia(list)) return FALSE;

  deslocar_direita(list, posicao);

  printf("Insira a matricula do aluno: ");
  scanf("%d", &fulano.matricula);

  list->alunos[posicao-1] = fulano;

  return TRUE;
}

int remover_final_da_lista(LISTA *list){
    if(list == NULL || tamanho_lista(list) == 0) return FALSE;

    list->quantidade--;
    return TRUE;
}

int remover_inicio_da_lista(LISTA *list){
  int inicio_lista = 0;

  if(list == NULL || tamanho_lista(list) == 0) return FALSE;

  deslocar_esquerda(list, inicio_lista);

  return TRUE;
}

int remover_da_lista(LISTA *list, int matricula){
  int posicao = 0;

  if(list == NULL || tamanho_lista(list) == 0) return FALSE;

  while(posicao<tamanho_lista(list) && list->alunos[posicao].matricula != matricula){
    posicao++;
  }

  if(posicao == tamanho_lista(list)) {
    printf("Matricula não encontrada!\n");
    return FALSE;
  }

  deslocar_esquerda(list, posicao);

  return TRUE;

}

int buscar_lista_posicao(LISTA *list, int posicao, ALUNO *busca){

  if(list == NULL || posicao <= 0 || posicao > tamanho_lista(list)) return FALSE;

  /* Normalmente a pessoa pede a primeira posição como 1 e não como 0 */
  *busca = list->alunos[posicao-1];

  return TRUE;
}

int buscar_lista_conteudo(LISTA *list, int matricula, ALUNO *busca){
  int posicao = 0;

  if(list == NULL) return FALSE;

  while(posicao < tamanho_lista(list) && list->alunos[posicao].matricula == matricula){
    posicao++;
  }

  if(posicao == tamanho_lista(list)) return FALSE;

  *busca = list->alunos[posicao];

  return posicao;

}

int mostrar_lista(LISTA *list){
  int i;
  if(list == NULL || tamanho_lista(list) == 0){
    printf("Lista vazia!\n");
    return FALSE;
  }

  printf("********************************\n");
  printf("*LISTA DE MATRICULAS DOS ALUNOS*\n");
  printf("********************************\n\n");
  printf("[%d", list->alunos[0].matricula);
  for(i=1; i<tamanho_lista(list); i++){
    printf(", %d", list->alunos[i].matricula);
  }
  printf("]\n");

  return TRUE;

}
