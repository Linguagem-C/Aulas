#include "descritor.h"

struct elemento {
  ALUNO dados;
  struct elemento *proximo;
};

typedef struct elemento ELEMENTO;

struct descritor {
  ELEMENTO *inicio;
  ELEMENTO *final;
  int qtd;
};

LISTA *criar_lista() {
  LISTA *lista =  (LISTA*) malloc(sizeof(LISTA));               // Aloca memória para a lista
  if(lista != NULL) {                                           // Verifica se deu certo a alocação
    lista->inicio = NULL;                                       // Aponta o inicio da lista para null
    lista->final = NULL;                                        // Aponta o final da lista para null
    lista->qtd = 0;                                             // Quantidade inicial da lista será zero
  }
  return lista;
}

void liberar_lista(LISTA *lista) {
  if(lista != NULL) {                                           // Se a lista for valida posso liberar ela
    ELEMENTO *no;                                               // Crio um elemento auxiliar
    while((lista->inicio) != NULL) {                            // Enquanto o inicio da lista for diferente de NULL
      no = lista->inicio;                                       // Nó auxiliar irá receber o inicio da lista
      lista->inicio = lista->inicio->proximo;                   // E o inicio da lista irá receber o proximo elemento
      free(no);                                                 // Desalocamos memoria do nó auxiliar
    }
    free(lista);                                                // Desalocamos memoria da lista completa
  }
}

int tamanho_lista(LISTA *lista) {
  if(lista == NULL) {                                           // Se a lista estiver vazia
    return 0;                                                   // Retorne 0
  }
  return lista->qtd;                                            // Caso contrario retorne sua quantidade armazenada
}

int inserir_inicio_da_lista(LISTA *lista, ALUNO aluno) {
  if (lista == NULL) return 0;                                  // Se a lista não for valida retornar 0
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));          // Alocar memória para o elemento nó
  if (no == NULL) return 0;                                     // Se o nó não for alocado retorna 0
  no->dados = aluno;                                            // No campo de dados do no será inserido a informação aluno
  no->proximo = lista->inicio;                                  // O proximo elemento do nó aponta para o inicio da lista
  if(lista->inicio == NULL) {                                   // Se a lista estiver vazia
    lista->final = no;                                          // O final da lista será o proprio nó
  }
  lista->inicio = no;                                           // Iremos inserir o nó no inicio da lista
  lista->qtd++;                                                 // E a quantidade será incrementada
  return 1;
}

int inserir_final_da_lista(LISTA *lista, ALUNO aluno) {
  if (lista == NULL) return 0;                                  // Se a lista não for valida retornar 0
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));          // Reservo espaço de memória para o novo elemento
  if (no == NULL) return 0;                                     // Se o nó não for alocado retorna 0
  no->dados = aluno;                                            // No campo de dados do nó será inserido as informações do aluno
  no->proximo = NULL;                                           // Como ele é o ultimo elemento o proximo será NULL
  if(lista->inicio == NULL) {                                   // Se a lista estiver vazia
    lista->inicio = no;                                         // O inicio da lista será o proprio nó
  } else {                                                      // Caso contrario
    lista->final->proximo = no;                                 // O ultimo elemento da lista apontará para o novo nó e deixará de ser o ultimo
  }
  lista->final = no;                                            // Agora o ultimo elemento é o novo nó
  lista->qtd++;                                                 // Como foi adicionado um novo nó incrementa a quantidade
  return 1;
}

int inserir_lista_ordenada(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                         // Testar se a lista é valida;
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));                // Alocar memoria para o novo nó
  if(no == NULL) return 0;                                            // Verificar se tem espaço de memória para alocar o novo nó
  no->dados = aluno;                                                  // Copia os dados do aluno para o novo nó
  if(lista->inicio == NULL) {                                         // Verifica se a lista está vazia
    lista->inicio = no;                                                  // O inicio da lista será o novo nó
    return 1;
  }else{                                                              // Se não for uma lista vazia temos que saber onde por o elemento
   ELEMENTO *anterior, *atual = lista->inicio;                        // Criamos dois elementos um que vai ser o anterior e o atual que será o inicio da lista
   while(atual != NULL && atual->dados.matricula < aluno.matricula) { // Enquanto o atual não dor o ultimo elemento e a matricula do atual for menor que a matricula do elemento inserido
    anterior = atual;                                                 // O anterior recebe o atual
    atual = atual->proximo;                                           // e o atual recebe o elemento que ele apontava ou o proximo elemento da lista
  }
    if(atual == lista->inicio) {                                        // Se o atual for o inicio da lista
      no->proximo = lista->inicio;                                      // O novo nó ira apontar para o nó que erá o inicio da lista
      lista->inicio = no;                                               // Inicio da lista irá receber o novo nó
    }else{                                                              // Caso o atual não seja o inicio da lista, será inserindo ou no final ou no meio dela
      no->proximo = anterior->proximo;                                  // novo nó ira apontar para onde o nó anterior estava apontando
      anterior->proximo = no;                                           // e o nó anterior irá apontar para o novo nó
    }
    return 1;
  }
  return 0;
}

int remover_inicio_da_lista(LISTA *lista) {
  if (lista == NULL) return 0;                        // Se a lista não for valida retornar 0
  if(lista->inicio == NULL) return 0;                 // Verifica se a lista está vazia se tiver retorne 0
  ELEMENTO *no = lista->inicio;                       // Criar um nó auxiliar irá receber o inicio da lista
  lista->inicio = no->proximo;                        // O inicio da lista irá receber o proximo nó
  free(no);                                           // Libera a memória do nó auxiliar
  if(lista->inicio == NULL) {                         // Se o inicio da lista se tornou NULL, significa que a lista ta vazia
    lista->final = NULL;                              // Logo o final da lista deve ser NULL também
  }
  lista->qtd--;                                       // Diminuir a quantidade de elementos da lista em 1
  return 1;
}

int remover_final_da_lista(LISTA *lista) {
  if (lista == NULL) return 0;                        // Se a lista não for valida retornar 0
  if(lista->inicio == NULL) return 0;                 // Verifica se a lista está vazia se tiver retorne 0
  ELEMENTO *anterior, *no = lista->inicio;            // Criamos dois elementos um que vai ser o anterior e o nó atual que será o inicio da lista
  while(no->proximo != NULL) {                        // Enquanto não chegar no final da lista
    anterior = no;                                    // O anterior passa a valer o nó
    no = no->proximo;                                 // E o nó passa a valer o proximo elemento
  }
  if(no == lista->inicio) {                           // Se o nó for o inicio da lista
    lista->inicio = NULL;                             // Vamos deixar a lista vazia apontando o inicio para NULL
    lista->final = NULL;                              // E o final para NULL
  } else {
    anterior->proximo = no->proximo;                  // O anterior irá apontar para o proximo nó
    lista->final = anterior;                          // E o final da lista agora será o anterior
  }
  free(no);                                           // Pois o proximo nó será liberado
  lista->qtd--;                                       // Diminui a quantidade
  return 1;
}
