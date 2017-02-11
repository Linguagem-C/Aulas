#include "fila.h"

struct fila {
  int inicio, final, quantidade;
  ALUNO dados[MAX];
};

FILA *criar_fila() {
  FILA *fila = (FILA*) malloc(sizeof(FILA));                      // Crio uma fila e aloco memoria para ela
  if(fila != NULL) {                                              // Verifico se a alocação deu certo
    fila->inicio = 0;                                             // O inicio da fila será zero
    fila->final = 0;                                              // O final da fila será zero
    fila->quantidade = 0;                                         // E a quantidade será zero, fila vazia
  }
  return fila;                                                    // Retorna a fila criada
}

void liberar_fila(FILA *fila) {
  free(fila);                                                     // Libera a fila da memória
}

int tamanho_da_fila(FILA *fila) {
  if(fila == NULL)                                                // Verificar se teve problema na alocação de memoria da fila
    return -1;
  return fila->quantidade;                                        // Caso não tenha dado, retornar a quantidade de elementos da fila
}

int fila_cheia(FILA *fila) {
  if(fila == NULL) return -1;                                     // Verificar se a alocação deu tudo certo
  if(fila->quantidade == MAX)                                     // Se a quantidade for igual ao maximo de elementos, a fila está cheia
    return 1;                                                     // Retorna verdadeiro
  else
    return 0;                                                     // Caso contrario retorna falso
}

int fila_vazia(FILA *fila) {
  if(fila == NULL) return -1;                                     // Verificar se a alocação deu tudo certo
  if(fila->quantidade == 0)                                       // Se a quantidade for igual a zero, a fila está vazia
    return 1;                                                     // Retorna verdadeiro
  else
    return 0;                                                     // Caso contrario retorna falso
}

int entrar_na_fila(FILA *fila, ALUNO aluno) {
  if(fila == NULL) return 0;                                    // Verificar se a fila existe
  if(fila_cheia(fila)) return 0;                                // Se a fila estiver cheia não pode inserir elemento
  fila->dados[fila->final] = aluno;                             // Inserir o aluno no final da fila
  fila->final++;                                                // Aumentar uma posição na fila
  if(fila->final == MAX) fila->final = 0;                       // Se o final da fila for o ultimo elemento, ele retorna para o zero
  fila->quantidade++;                                           // A quantidade da fila aumenta (+1)
  return 1;
}

int sair_da_fila(FILA *fila) {
  if(fila == NULL || fila_vazia(fila)) return 0;                // Se a fila não existir ou estiver vazia não se pode remover da fila
  fila->inicio++;                                               // O inicio da fila irá andar uma casa já que o seu primeiro elemento irá ser deletado
  if(fila->inicio == MAX) fila->inicio = 0;                     // Se o inicio da fila for igual ao ultimo logo o inicio volta para o zero
  fila->quantidade--;                                           // A quantidade de elementos na fila irá diminuir em uma casa
  return 1;
}

int consultar_fila(FILA *fila, ALUNO *aluno) {
  if(fila == NULL || fila_vazia(fila)) return 0;                // Se a fila não existir ou estiver vazia não se pode consultar o primeiro elemento da fila
  *aluno = fila->dados[fila->inicio];                           // Consultar o primeiro da fila
  return 1;
}
