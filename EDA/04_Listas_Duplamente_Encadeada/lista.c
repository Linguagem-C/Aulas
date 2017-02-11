#include "lista.h"

struct elemento {
  ALUNO dados;
  struct elemento *anterior;
  struct elemento *proximo;
};

typedef struct elemento ELEMENTO;

LISTA *criar_lista() {
  LISTA *lista = (LISTA*) malloc(sizeof(LISTA));                    // Alocar memoria para a lista dinamicamente
  if(lista != NULL)                                                 // Se já existir algo dentro da lista
    *lista = NULL;                                                  // Seta o conteudo da lista para NULL
  return lista;                                                     // Retorna a lista criada
}

void liberar_lista(LISTA *lista) {
  if(lista != NULL) {                                               // Verificar se a lista não esta vazia
    ELEMENTO *no;                                                   // Criar um elemento nó
    while((*lista) != NULL) {                                       // Enquanto o conteudo do inicio da lista for diferente de NULL, não chegar ao final dela
      no = *lista;                                                  // O nó ira receber o conteudo da lista
      *lista = (*lista)->proximo;                                   // E o conteudo da lista ira receber o proximo elemento
      free(no);                                                     // Liberar a memoria do nó
    }
    free(lista);                                                    // Liberar a memoria da lista
  }
}

int tamanho_lista(LISTA *lista) {
  if(lista == NULL) return 0;                                       // Verificar se a lista esta vazia
  int contador = 0;                                                 // Criar um contador
  ELEMENTO *no = *lista;                                            // Criar um elemento nó que irá receber o conteudo do inicio da lista
  while(no != NULL) {                                               // Enquanto não chegar no final da lista
    contador++;                                                     // Incrementa o contador
    no = no->proximo;                                               // nó recebe o proximo elemento da lista
  }
  return contador;                                                  // Retorna o contador com a quantidade de elementos da lista
}

int lista_vazia(LISTA *lista) {
  if(lista == NULL)                                                 // Se a lista existe e for igual a NULL quer dizer que esta vazia
    return 1;
  if(*lista == NULL)                                                // Se o conteudo da lista for NULL que dizer que esta vazia
    return 1;
  return 0;                                                         // Caso contrario a lista não está vazia
}

int inserir_inicio_da_lista(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                       // Verificar se a lista existe
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));              // Alocar memoria para o nó que irá pra lista
  if(no == NULL) return 0;                                          // Verificar se a alocação de memoria foi realizada
  no->dados = aluno;                                                // Inserir os dados dos alunos no nó
  no->proximo = (*lista);                                           // Apontar o proximo nó para o inicio da lista
  no->anterior = NULL;                                              // Apontar o nó anterior a ele para NULL
  if(*lista != NULL)                                                // Se a lista não estiver vazia
    (*lista)->anterior = no;                                        // O nó anterior ao nó que aponta para null (primeiro nó da lista) receberá o novo nó
  *lista = no;                                                      // E o inicio da lista agora será o novo nó
  return 1;
}

int inserir_final_da_lista(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                       // Verificar se a lista existe
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));              // Alocar memoria para o nó que irá pra lista
  if(no == NULL) return 0;                                          // Verificar se a alocação de memoria foi realizada
  no->dados = aluno;                                                // Inserir os dados dos alunos no nó
  no->proximo = NULL;                                               // Apontar o proximo nó para NULL ou final da lista
  if((*lista) == NULL) {                                            // Verificar se a lista está vazia
    no->anterior = NULL;                                            // Se estiver o nó anterior ira ser o NULL
    *lista = no;                                                    // E o inicio da lista irá receber o novo nó
  }else{                                                            // Caso contrario
    ELEMENTO *auxiliar = *lista;                                    // Criamos um elemento auxiliar que irá receber o inicio da lista
    while(auxiliar->proximo != NULL) {                              // Enquanto não chegar ao final da lista
      auxiliar = auxiliar->proximo;                                 // O nó auxiliar irá receber o proximo elemento depois dele
    }
    auxiliar->proximo = no;                                         // Ao chegar ao final o proximo elemento depois do auxiliar irá receber o novo nó
    no->anterior = auxiliar;                                        // E o elemento antes do novo nó ira receber o auxiliar
  }
  return 1;
}

int inserir_lista_ordenada(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                       // Verificar se a lista existe
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));              // Alocar memoria para o nó que irá pra lista
  if(no == NULL) return 0;                                          // Verificar se a alocação de memoria foi realizada
  no->dados = aluno;                                                // Inserir os dados dos alunos no nó
  if(lista_vazia(lista)) {                                          // Verificar se a lista está vazia
    no->proximo = NULL;                                             // Se estiver o proximo elemento aṕos o nó será NULL
    no->anterior = NULL;                                            // E o elemento anterior a ele também
    *lista = no;                                                    // O inicio da lista irá receber esse novo nó
    return 1;
  }else{
    ELEMENTO *anterior, *atual = *lista;                                  // Criar elementos auxiliares
    while(atual != NULL && atual->dados.matricula < aluno.matricula) {    // Enquanto o meu atual for diferente de null e a matricula do aluno for maior que a atual
      anterior = atual;                                                   // O anterior irá receber o atual
      atual = atual->proximo;                                             // E o atual irá receber o proximo nó
    }
    if(atual == *lista) {                                                 // Se o atual for o inicio da lista quer dizer que a matricula era maior no primeiro nó
      no->anterior = NULL;                                                // no anterior irá receber NULL
      (*lista)->anterior = no;                                            // O nó anterior ao inicio da lista irá receber o novo nó
      no->proximo = (*lista);                                             // O proximo nó após o novo nó irá receber o inicio da lista
      *lista = no;                                                        // Logo o inicio da lista passa a ser o novo nó
    }else{                                                                // Caso contrario
      no->proximo = anterior->proximo;                                    // O proximo nó após o novo nó irá receber o nó que o anterior apontava
      no->anterior = anterior;                                            // O novo nó irá apontar para o anterior
      anterior->proximo = no;                                             // E o anterior irá apontar para o novo nó
      if(atual != NULL) {                                                 // Se o atual for diferente de NULL
        atual->anterior = no;                                             // O atual irá apontar para o nó anterior que é o novo nó
      }
    }
  }
  return 1;
}

int remover_inicio_da_lista(LISTA *lista) {
  if(lista == NULL) return 0;                                       // Verificar se a lista existe
  if((*lista) == NULL) return 0;                                    // Verificar se o primeiro elemento da lista é nulo, lista vazia
  ELEMENTO *no = *lista;                                            // Criar um nó que irá receber o inicio da lista
  *lista = no->proximo;                                             // O proximo elemento após o nó ira para o inicio da lista
  if(no->proximo != NULL)                                           // Se o proximo elemento após o nó não for o ultimo elemento
    no->proximo->anterior = NULL;                                   // O proximo elemento após o nó irá apontar para NULL como nó anterior a ele
  free(no);                                                         // deletar o nó
  return 1;
}

int remover_final_da_lista(LISTA *lista) {
  if(lista == NULL) return 0;                                       // Verificar se a lista existe
  if((*lista) == NULL) return 0;                                    // Verificar se o primeiro elemento da lista é nulo, lista vazia
  ELEMENTO *no = *lista;                                            // Criar um nó que irá receber o inicio da lista
  while(no->proximo != NULL) {                                      // Enquanto o proximo nó não for o final da lista
    no = no->proximo;                                               // o no irá receber o proximo nó
  }
  if(no->anterior == NULL)                                          // Ao chegar no final da lista e o nó anterior for nulo, quer dizer que a lista só tem 1 nó
    *lista = no->proximo;                                           // A lista irá apontar para o próximo elemento que é NULL
  else
    no->anterior->proximo = NULL;                                   // Caso contrario o nó anterior irá apontar para o proximo que irá receber NULL
  free(no);                                                         // deletar o nó
  return 1;
}

int remover_da_lista(LISTA *lista, int matricula) {
  if(lista == NULL) return 0;                                       // Verificar se a lista existe
  ELEMENTO *no = *lista;                                            // Criar um nó que irá receber o inicio da lista
  while(no != NULL && no->dados.matricula != matricula) {           // Enquanto o meu nó atual for diferente de null e a matricula for diferente que a inserida
    no = no->proximo;                                               // E o atual irá receber o proximo nó
  }
  if(no == NULL)                                                    // Se após percorrer a lista o nó for igual a null, quer dizer que não foi encontrado o nó
    return 0;
  if(no->anterior == NULL)                                          // Ao chegar no final da lista e o nó anterior for nulo, quer dizer que a lista só tem 1 nó
    *lista = no->proximo;                                           // A lista irá apontar para o próximo elemento que é NULL
  else
    no->anterior->proximo = no->proximo;                            // Caso contrario o nó anterior irá apontar para o proximo nó após o nó atual
  free(no);
  return 1;
}

int buscar_lista_posicao(LISTA *lista, int posicao, ALUNO *busca) {
  if(lista == NULL || posicao <= 0) return 0;                       // Verificar se a lista não existi ou a posição é menor ou igual a zero
  ELEMENTO *no = *lista;                                            // Criar um nó auxiliar que irá receber o inicio da lista
  int i = 1;                                                        // Criar um contador
  while(no != NULL && i < posicao) {                                // Enquanto o nó não chegar ao final da lista e o contador for menor que posicao
    no = no->proximo;                                               // Continuar percorrendo a lista
    i++;                                                            // Incrementer o contador
  }
  if(no == NULL)                                                // Se o no for igual a null significa que a posição que foi inserida é maior que o número de nós
    return 0;
  else{
    *busca = no->dados;                                         // Caso contrario achamos a posição e pegamos os dados do aluno que buscamos
    return 1;
  }
}

int buscar_lista_matricula(LISTA *lista, int matricula, ALUNO *busca) {
  if(lista == NULL) return 0;                                       // Verificar se a lista não existi ou a posição é menor ou igual a zero
  ELEMENTO *no = *lista;                                            // Criar um nó auxiliar que irá receber o inicio da lista
  while(no != NULL && no->dados.matricula != matricula) {           // Enquanto o nó não chegar ao final da lista e as matriculas não forem iguais
    no = no->proximo;                                               // Continuar percorrendo a lista
  }
  if(no == NULL)                                                    // Se o no for igual a null significa que nunca achei a matricula que estava procurando
    return 0;
  else{
    *busca = no->dados;                                             // Caso contrario achamos a matricula e pegamos os dados do aluno que buscamos
    return 1;
  }
}

int mostrar_lista(LISTA *lista) {
	if(lista == NULL) return 0;                                       // Verificar se a lista não existi ou a posição é menor ou igual a zero
  ELEMENTO *no = *lista;                                            // Criar um nó auxiliar que irá receber o inicio da lista
  while(no != NULL) {          				 															// Enquanto o nó não chegar ao final da lista
    printf("%d %s %.2f %.2f %.2f\n", no->dados.matricula, no->dados.nome, no->dados.P1, no->dados.P2, no->dados.P3);
    no = no->proximo;                                               // Continuar percorrendo a lista
  }
  return 1;
}