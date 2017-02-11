#include "lista.h"

struct elemento {
  ALUNO dados;
  struct elemento *proximo;
};

typedef struct elemento ELEMENTO;

LISTA *criar_lista() {
  LISTA *lista = (LISTA*) malloc(sizeof(LISTA));                            // Alocar memoria para a lista
  if(lista != NULL)                                                         // Verificar se a lista foi alocada corretamente
    *lista = NULL;                                                          // Se não estiver insira NULL no primeiro elemento para deixar vazia
  return lista;                                                             // Retorne a lista
}

void liberar_lista(LISTA *lista) {
  if(lista != NULL && (*lista) != NULL) {                                   // Se a lista existir e não for nula
    ELEMENTO *auxiliar, *no = *lista;                                       // Criar elementos auxiliares
    while((*lista) != no->proximo) {                                        // Enquanto o conteudo do nó atual for diferente do conteudo do proximo nó
      auxiliar = no;                                                        // Auxiliar vai receber o nó atual
      no = no->proximo;                                                     // nó atual vai receber o próximo
      free(auxiliar);                                                       // Deletar o auxiliar
    }
    free(no);                                                               // Ao percorrer toda a lista liberando-a libere o ultimo nó que sobro
    free(lista);                                                            // Libere a lista
  }
}

int tamanho_lista(LISTA *lista) {
  if(lista == NULL || (*lista) == NULL)                                     // Verifica se a lista existe e se ela não está vazia
    return 0;                                                               // Lista tem nenhum elemento
  int contador = 0;                                                         // Caso passe na verificação criar um contador
  ELEMENTO  *no = *lista;                                                   // E criar um elemento com o conteudo do primeiro nó da lista
  do {
    contador++;                                                             // Incremente o contador
    no = no->proximo;                                                       // E vá para o proximo nó da lista
  }while(no != (*lista));                                                   // Enquanto o nó atual for diferente do nó do inicio da lista
  return contador;                                                          // Retorna o número de elementos da lista
}

int lista_vazia(LISTA *lista) {
  if(lista == NULL && (*lista) == NULL)                                     // Se a lista for invalida ou seja nula, e o seu conteudo for nulo
    return 1;                                                               // A lista está vazia
  else                                                                      // Caso contrario
    return 0;                                                               // A lista não está vazia
}

int inserir_inicio_da_lista(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                               // Verificar se a lista existe
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));                      // Criar um nó e alocar sua memoria
  if(no == NULL) return 0;                                                  // Verificar se a memoria do novo nó foi alocada
  no->dados = aluno;                                                        // Inserir os dados do aluno no novo nó da lista
  if((*lista) == NULL) {                                                    // Se o conteudo do inicio da lista for igual a NULL, lista vazia
    *lista = no;                                                            // O primeiro elemento da lista será o novo nó
    no->proximo = no;                                                       // E o proximo elemento será ele mesmo
  }else{                                                                    // Caso contrario
    ELEMENTO *auxiliar = *lista;                                            // Criar um elemento auxiliar com o inicio da lista
    while(auxiliar->proximo != (*lista))                                    // Enquanto o o proximo elemento for diferente do conteudo do inicio da lista
      auxiliar = auxiliar->proximo;                                         // Vamos continuar percorrendo a lista
    auxiliar->proximo = no;                                                 // Ao chegar no ultimo elemento da lista inserir o proximo elemento como o nó
    no->proximo = *lista;                                                   // O elemento após o novo nó será o conteudo do inicio da lista
    *lista = no;                                                            // E o inicio da lista sera o novo nó
  }
  return 1;
}

int inserir_final_da_lista(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                               // Verificar se a lista existe
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));                      // Criar um nó e alocar sua memoria
  if(no == NULL) return 0;                                                  // Verificar se a memoria do novo nó foi alocada
  no->dados = aluno;                                                        // Inserir os dados do aluno no novo nó da lista
  if((*lista) == NULL) {                                                    // Se o conteudo do inicio da lista for igual a NULL, lista vazia
    *lista = no;                                                            // O primeiro elemento da lista será o novo nó
    no->proximo = no;                                                       // E o proximo elemento será ele mesmo
  }else{                                                                    // Caso contrario
    ELEMENTO *auxiliar = *lista;                                            // Criar um elemento auxiliar com o inicio da lista
    while(auxiliar->proximo != (*lista))                                    // Enquanto o o proximo elemento for diferente do conteudo do inicio da lista
      auxiliar = auxiliar->proximo;                                         // Vamos continuar percorrendo a lista
    auxiliar->proximo = no;                                                 // Ao chegar no ultimo elemento da lista inserir o proximo elemento como o nó
    no->proximo = *lista;                                                   // O elemento após o novo nó será o conteudo do inicio da lista
  }
  return 1;
}

int inserir_lista_ordenada(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                               // Verificar se a lista existe
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));                      // Criar um nó e alocar sua memoria
  if(no == NULL) return 0;                                                  // Verificar se a memoria do novo nó foi alocada
  no->dados = aluno;                                                        // Inserir os dados do aluno no novo nó da lista
  if((*lista) == NULL) {                                                    // Se o conteudo do inicio da lista for igual a NULL, lista vazia
    *lista = no;                                                            // O primeiro elemento da lista será o novo nó
    no->proximo = no;                                                       // E o proximo elemento será ele mesmo
    return 1;
  }else{                                                                    // Caso contrario
    if((*lista)->dados.matricula > aluno.matricula) {                       // Insere no inicio da lista
      ELEMENTO *atual = *lista;                                               // Criar um elemento auxiliar com o inicio da lista
      while(atual->proximo != (*lista))                                       // Procura o ultimo elemento
        atual = atual->proximo;                                               // O atual vai receber o proximo nó após ele até o ultimo elemento
      no->proximo = *lista;                                                 // O novo nó irá apontar para o o inicio da lista
      atual->proximo = no;                                                  // proximo nó após o atual irá receber o novo nó
      *lista = no;                                                          // O inicio da lista será no novo nó
      return 1;
    }
    ELEMENTO *anterior = *lista;                                            // Caso a inserção seja após o inicio da lista criar um anterior com o inicio da lista
    ELEMENTO *atual = (*lista)->proximo;                                    // Criar um atual com o proximo elemento após o inicio da lista
    while(atual != (*lista) && atual->dados.matricula < aluno.matricula) {  // Percorrer a lista até encontrar a matricula ou até chegar ao inicio da lista
      anterior = atual;                                                     // Jogar o atual para o anterior
      atual = atual->proximo;                                               // E o atual agora será o proximo elemento
    }
    anterior->proximo = no;                                               // Ao achar o nó com a matricula maior que a inserida, vamos jogar o novo nó no anterior
    no->proximo = atual;                                                  // O nó após o novo nó passa a ser o atual que tem a matricula maior que a dele
  }
  return 1;
}

int remover_inicio_da_lista(LISTA *lista) {
  if(lista == NULL) return 0;                                             // Verificar se a lista existe
  if((*lista) == NULL) return 0;                                          // Verificar se a lista não está vazia
  if((*lista) == (*lista)->proximo) {                                     // Se o conteudo do inicio da lista for igual ao conteúdo do proximo nó
    free(*lista);                                                         // A lista tem um único elemento, logo vamos deleta-lo
    *lista = NULL;                                                        // E o inicio da lista vai apontar para NULL
    return 1;
  }
  ELEMENTO *atual = *lista;                                               // Caso a lista teja mais de 1 nó criar um elemento que recebe o inicio da lista
  while(atual->proximo != (*lista))                                       // Enquanto a lista não chegar no primeiro elemento dela novamente
    atual = atual->proximo;                                               // O nó atual vai para o próximo
  ELEMENTO *no = *lista;                                                  // Criar um nó auxiliar com o inicio da lista
  atual->proximo = no->proximo;                                           // ao chegar no ultimo elemento, ele irá apontar para o proximo nó depois do 1° nó
  *lista = no->proximo;                                                   // E o inicio da lista irá apontar para o nó que está após o primeiro nó
  free(no);                                                               // Vamos liberar o primeiro nó da lista
  return 1;
}

int remover_final_da_lista(LISTA *lista) {
  if(lista == NULL) return 0;                                             // Verificar se a lista existe
  if((*lista) == NULL) return 0;                                          // Verificar se a lista não está vazia
  if((*lista) == (*lista)->proximo) {                                     // Se o conteudo do inicio da lista for igual ao conteúdo do proximo nó
    free(*lista);                                                         // A lista tem um único elemento, logo vamos deleta-lo
    *lista = NULL;                                                        // E o inicio da lista vai apontar para NULL
    return 1;
  }
  ELEMENTO *no = *lista;                                                  // Caso a lista teja mais de 1 nó criar um elemento que recebe o inicio da lista
  ELEMENTO *anterior;                                                     // Criar um nó auxiliar
  while(no->proximo != (*lista)) {                                        // Enquanto a lista não chegar no primeiro elemento dela novamente
    anterior = no;                                                        // Vamos guardar o nó atual para o anterior
    no = no->proximo;                                                     // O nó atual vai para o próximo
  }
  anterior->proximo = no->proximo;                                        // O nó anterior ao ultimo nó irá apontar para o primeiro nó da lista
  free(no);                                                               // Remover o ultimo nó da lista
  return 1;
}

int remover_da_lista(LISTA *lista, int matricula) {
  if(lista == NULL) return 0;                                             // Verificar se a lista existe
  if((*lista) == NULL) return 0;                                          // Verificar se a lista não está vazia
  ELEMENTO *no = *lista;                                                  // Criar um nó que recebe o primeiro elemento da lista
  if(no->dados.matricula == matricula) {                                  // Remover do inicio da lista
    if(no == no->proximo) {                                               // Verificar se o nó atual é igual ao proximo nó, lista com 1 elemento
      free(no);                                                           // Liberar esse único nó
      *lista = NULL;                                                      // Conteúdo da lista recebe NULL
      return 1;
    }else{                                                                // Caso teja mais de um elemento na lista
      ELEMENTO *atual = *lista;                                           // Criar um elemento para percorrer a lista e inserir o primeiro nó da lista nele
      while(atual->proximo != (*lista))                                   // Enquanto não achar o ultimo elemento da lista
        atual = atual->proximo;                                           // O atual irá receber o próximo
      atual->proximo = (*lista)->proximo;                                 // Quando achar o ultimo elemento ele irá apontar para o nó após o 1° nó da lista
      *lista = (*lista)->proximo;                                         // E o primeiro nó da lista irá receber o nó após ele
      free(no);                                                           // Logo em seguida o primeiro nó ira ser deletado
      return 1;
    }
  }
  ELEMENTO *anterior = no;                                                // Caso não seja do inicio criar um nó anterior que irá receber o nó do inicio da lista
  no = no->proximo;                                                       // O nó ira para o proximo nó
  while(no != (*lista) && no->dados.matricula != matricula) {             // Enquanto o nó não voltar ao inicio e as matriculas forem diferentes
    anterior = no;                                                        // O anterior irá receber o nó atual
    no = no->proximo;                                                     // E o nó atual irá para o proximo nó
  }
  if(no == *lista) return 0;                                              // Se o nó for o inicio da lista que dizer que a matricula não foi encontrada
  anterior->proximo = no->proximo;                                        // Caso contrario, o nó anterior ao nó encontrado irá apontar para onde apontavo o nó
  free(no);                                                               // Liberar o nó encontrado
  return 1;
}

int buscar_lista_posicao(LISTA *lista, int posicao, ALUNO *aluno) {
  if(lista == NULL || (*lista) == NULL || posicao <= 0) return 0;       // Verificar se a lista existe, se é vazia e se a posição é maior que zero
  ELEMENTO *no = *lista;                                                // Criar um nó que recebe o elemento do inicio da lista
  int i = 1;                                                            // Criar um contador i que inicia em 1
  while(no->proximo != (*lista) && i < posicao) {                       // Enquanto no não volta ao inicio da lista e i for menor que a posição passada
    no = no->proximo;                                                   // no ira receber o proximo elemento da lista
    i++;                                                                // contador será incrementado
  }
  if(i != posicao)                                                      // Se o contador for diferente da posição passada
    return 0;                                                           // Retorne zero
  else                                                                  // Caso contrario
    *aluno = no->dados;                                                 // Retorne os dados do aluno encontrado
  return 1;
}


int buscar_lista_matricula(LISTA *lista, int matricula, ALUNO *aluno) {
  if(lista == NULL || (*lista) == NULL) return 0;                       // Verificar se a lista existe e não é vazia
  ELEMENTO *no = *lista;                                                // Criar um nó que recebe o elemento do inicio da lista
  while(no->proximo != (*lista) && no->dados.matricula != matricula)    // Enquanto no não voltar ao inicio da lista e as matriculas forem diferentes
    no = no->proximo;                                                   // no ira receber o proximo elemento da lista
  if(no->dados.matricula != matricula)                                  // Se a matricula não for encontrada
    return 0;                                                           // Retorne zero
  else                                                                  // Caso contrario
    *aluno = no->dados;                                                 // Retorne os dados do aluno encontrado
  return 1;
}

// ARRUMAR
int mostrar_lista(LISTA *lista) {
  if(lista == NULL || (*lista) == NULL) return 0;                   // Verificar se a lista não existi ou se ela está vazia
  ELEMENTO *no = *lista;                                            // Criar um nó auxiliar que irá receber o inicio da lista
  while(no->proximo != (*lista)) {                                  // Enquanto o nó não chegar ao inicio da lista novamente
    printf("%d %s %.2f %.2f %.2f\n", no->dados.matricula, no->dados.nome, no->dados.P1, no->dados.P2, no->dados.P3);
    no = no->proximo;                                               // Continuar percorrendo a lista
  }
  return 1;
}
