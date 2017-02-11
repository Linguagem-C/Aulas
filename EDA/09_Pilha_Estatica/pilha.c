#include "pilha.h"

struct pilha {
  int quantidade;
  LIVRARIA dados[MAX];
};

PILHA *criar_pilha() {
  PILHA *pilha = (PILHA*) malloc(sizeof(PILHA));                   // Crio uma pilha e aloco memoria para ela
  if(pilha != NULL) {                                              // Verifico se a alocação deu certo
    pilha->quantidade = 0;                                         // A quantidade será zero, pilha vazia
  }
  return pilha;                                                    // Retorna a pilha criada
}

void liberar_pilha(PILHA *pilha) {
  free(pilha);                                                     // Libera a pilha da memória
}

int tamanho_da_pilha(PILHA *pilha) {
  if(pilha == NULL)                                                // Verificar se teve problema na alocação de memoria da pilha
    return -1;
  return pilha->quantidade;                                        // Caso não tenha dado, retornar a quantidade de elementos da pilha
}

int pilha_cheia(PILHA *pilha) {
  if(pilha == NULL) return -1;                                     // Verificar se a alocação deu tudo certo
  if(pilha->quantidade == MAX)                                     // Se a quantidade for igual ao maximo de elementos, a pilha está cheia
    return 1;                                                      // Retorna verdadeiro
  else
    return 0;                                                      // Caso contrario retorna falso
}

int pilha_vazia(PILHA *pilha) {
  if(pilha == NULL) return -1;                                     // Verificar se a alocação deu tudo certo
  if(pilha->quantidade == 0)                                       // Se a quantidade for igual a zero, a pilha está vazia
    return 1;                                                      // Retorna verdadeiro
  else
    return 0;                                                      // Caso contrario retorna falso
}

int entrar_na_pilha(PILHA *pilha, LIVRARIA livro) {
  if(pilha == NULL) return 0;                                      // Verificar se a pilha existe
  if(pilha_cheia(pilha)) return 0;                                 // Se a pilha estiver cheia não pode inserir elemento
  pilha->dados[pilha->quantidade] = livro;                         // Inserir o livro na primeira vaga disponivel da pilha
  pilha->quantidade++;                                             // Aumentar uma posição na pilha
  return 1;
}

int sair_da_pilha(PILHA *pilha) {
  if(pilha == NULL || pilha_vazia(pilha)) return 0;                // Se a pilha não existir ou estiver vazia não se pode remover da pilha
  pilha->quantidade--;                                             // A quantidade de elementos na pilha irá diminuir em uma casa
  return 1;
}

int consultar_pilha(PILHA *pilha, LIVRARIA *livro) {
  if(pilha == NULL || pilha_vazia(pilha)) return 0;                // Se a pilha não existir ou estiver vazia não se pode consultar o primeiro elemento da pilha
  *livro = pilha->dados[pilha->quantidade-1];                      // Consultar o primeiro da pilha
  return 1;
}

void mostrar_pilha(PILHA *pilha) {
  int i;
  if(pilha == NULL || pilha_vazia(pilha)){
    printf("A pilha de livros está vazia\n");
  }else{
    for(i=1; i<=pilha->quantidade; i++) {
      printf("[%d]: %s\n", pilha->dados[pilha->quantidade-i].codigo, pilha->dados[pilha->quantidade-i].titulo);
    }
  }
}
