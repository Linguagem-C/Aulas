#include "fila.h"

struct elemento {
  ALUNO dados;
  struct elemento *proximo;
};

typedef struct elemento ELEMENTO;

struct fila {
  ELEMENTO *inicio;
  ELEMENTO *final;
};

FILA *criar_fila() {
  FILA *fila = (FILA*) malloc(sizeof(FILA));                      // Crio uma fila e aloco memoria para ela
  if(fila != NULL) {                                              // Verifico se a alocação deu certo
    fila->inicio = NULL;                                          // O inicio da fila será nulo
    fila->final = NULL;                                           // O final da fila será nul
  }
  return fila;                                                    // Retorna a fila criada
}

void liberar_fila(FILA *fila) {
  if(fila != NULL) {                                              // Verificar se a fila existe
    ELEMENTO *no;                                                 // Criar um elemento auxiliar
    while(fila->inicio != NULL) {                                 // Enquanto a o inicio da fila não for nulom enquanto não tiver alguém na fila
      no = fila->inicio;                                          // Nó auxiliar irá receber o inicio da fila
      fila->inicio = fila->inicio->proximo;                       // E o inicio da fila irá para o proximo elemento
      free(no);                                                   // Liberar o nó que armazenou o inicio da fila
    }
    free(fila);                                                   // Assim que todos da fila forem liberados destruir a fila
  }
}

int tamanho_da_fila(FILA *fila) {
  if(fila == NULL) return 0;                                      // Verificar se teve problema na alocação de memoria da fila
  int contador = 0;                                               // Cria um contador e inicializa com 0
  ELEMENTO *no = fila->inicio;                                    // Cria um nó auxiliar e inicializa com o inicio da fila
  while(no != NULL) {                                             // Enquanto nó não chega no final da fila
    contador++;                                                   // Incrementa o contador
    no = no->proximo;                                             // Vai para o proximo elemento da fila
  }
  return contador;                                                // Retorna o tamanho da fila
}

int fila_vazia(FILA *fila) {
  if(fila == NULL) return 1;                                      // Verificar se a alocação deu tudo certo
  if(fila->inicio == NULL) return 1;                              // Se o inicio da fila é nulo, a fila está vazia
  return 0;                                                       // Caso contrario retorna falso
}

int entrar_na_fila(FILA *fila, ALUNO aluno) {
  if(fila == NULL) return 0;                                    // Verificar se a fila existe
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));          // Criar um elemento auxiliar
  if(no == NULL) return 0;                                      // Se a alocação não funcionou retorna erro
  no->dados = aluno;                                            // Inserir os dados do aluno
  no->proximo = NULL;                                           // Inserir o proximo da fila como nulo já que vai inserir no final da fila
  if(fila->final == NULL)                                       // Se a fila tiver nula, fila vazia
    fila->inicio = no;                                          // Inserir o nó no inicio da fila
  else                                                          // Caso contrario
    fila->final->proximo = no;                                  // O ultimo elemento da fila irá apontar para o novo nó
  fila->final = no;                                             // E o ultimo elemento da fila passa a ser o nó
  return 1;
}

int sair_da_fila(FILA *fila) {
  if(fila == NULL || fila_vazia(fila)) return 0;                // Se a fila não existir ou estiver vazia não se pode remover da fila
  ELEMENTO *no = fila->inicio;                                  // Criar um nó auxiliar com o inicio da fila
  fila->inicio = fila->inicio->proximo;                         // Inicio da fila recebe o elemento que vem depois dela
  if(fila->inicio == NULL)                                      // Se a fila ficar vazia(NULL) ao receber o proximo elemento
    fila->final = NULL;                                         // O final da fila passa a ser nulo também, já que está vazia
  free(no);                                                     // Libera o nó que armazenou o inicio da fila anterior
  return 1;
}

int consultar_fila(FILA *fila, ALUNO *aluno) {
  if(fila == NULL || fila_vazia(fila)) return 0;                // Se a fila não existir ou estiver vazia não se pode consultar o primeiro elemento da fila
  *aluno = fila->inicio->dados;                                 // O aluno recebe os dados do primeiro elemento da fila
  return 1;
}
