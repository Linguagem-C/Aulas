#include "lista.h"

struct elemento {
  ALUNO dados;
  struct elemento *proximo;
};

typedef struct elemento ELEMENTO;

//Aloca memoria para o primeiro nó da lista apontando ela como NULL ou vazia
LISTA *criar_lista() {
  LISTA *lista = (LISTA*) malloc(sizeof(LISTA));
  if(lista != NULL) {
    *lista = NULL;
  }
  return lista;
}

// Lista != Null que dizer que a lista não esta vazia e esta em uso, vamos esvaziar a lista
void liberar_lista(LISTA *lista) {
  if(lista != NULL) {
    ELEMENTO *no;
    while((*lista) != NULL){
      no = *lista;
      *lista = (*lista)->proximo;
      free(no);
    }
    free(lista);
  }
}

int tamanho_lista(LISTA *lista) {
  if(lista == NULL) return 0;
  int contador = 0;
  ELEMENTO *no = *lista;
  while(no != NULL) {
    contador++;
    no = no->proximo;
  }
  return contador;
}

int lista_vazia(LISTA *lista) {
  if(lista == NULL)
    return 1;

  if(*lista == NULL)
    return 1;

  return 0;
}

int inserir_inicio_da_lista(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                   // Testar se a lista é valida
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));          // Alocar memoria para o novo nó
  if(no == NULL) return 0;                                      // Verificar se tem espaço de memoria para o novo nó
  no->dados = aluno;                                            // Inserir os dados do aluno no novo nó
  no->proximo = (*lista);                                       // Aponta o novo nó para o elemento do inicio da lista
  *lista = no;                                                  // E o inicio da lista irá receber o nó
  return 1;
}

int inserir_final_da_lista(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                     // Testar se a lista é valida
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));            // Aloca memoria para o novo nó
  if(no == NULL) return 0;                                        // Verifica se tem espaço de memoria para alocar o novo nó
  no->dados = aluno;                                              // copia os dados do aluno para o novo nó
  no->proximo = NULL;                                             // Novo nó aponta para NULL já que vai ser o ultimo elemento da lista
  if((*lista) == NULL) {                                          // Verifica se a lista esta vazia
    *lista = no;                                                  // Se tiver insere o novo nó no inicio da lista
  }else{                                                          // Caso contrario
   ELEMENTO *auxiliar = *lista;                                   // Crie um elemento auxiliar e insere a primeira posição ou a cabeça da lista nela
   while(auxiliar->proximo != NULL)                               // Percorra toda a lista até achar o nó que aponta para o ultimo elemento
     auxiliar = auxiliar->proximo;                                // Enquanto o auxiliar não apontar para null insere o proximo elemento no auxiliar
   auxiliar->proximo = no;                                        // Ao encontrar o final da lista insira o nó no proximo elemento que será o ultimo
  }
  return 1;
}

int inserir_lista_ordenada(LISTA *lista, ALUNO aluno) {
  if(lista == NULL) return 0;                                         // Testar se a lista é valida;
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));                // Alocar memoria para o novo nó
  if(no == NULL) return 0;                                            // Verificar se tem espaço de memória para alocar o novo nó
  no->dados = aluno;                                                  // Copia os dados do aluno para o novo nó
  if(lista_vazia(lista)) {                                            // Verifica se a lista está vazia
    no->proximo = (*lista);                                           // Se a lista for vazia o nó aponta para o inicio da lista
    *lista = no;                                                      // e o inicio da lista recebe o nó
    return 1;
  }else{                                                              // Se não for uma lista vazia temos que saber onde por o elemento
   ELEMENTO *anterior, *atual = *lista;                               // Criamos dois elementos um que vai ser o anterior e o atual que será o inicio da lista
   while(atual != NULL && atual->dados.matricula < aluno.matricula) { // Enquanto o atual for diferente de NULL e a matricula do atual for menor que a matricula do elemento inserido
    anterior = atual;                                                 // O anterior recebe o atual
    atual = atual->proximo;                                           // e o atual recebe o elemento que ele apontava ou o proximo elemento da lista
  }
    if(atual == *lista) {                                               // Se o atual for o inicio da lista
      no->proximo = (*lista);                                           // O novo nó ira apontar para o nó que erá o inicio da lista
      (*lista) = no;                                                    // Inicio da lista irá receber o novo nó
    }else{                                                              // Caso o atual não seja o inicio da lista, to inserindo ou no final ou no meio dela
      no->proximo = anterior->proximo;                                  // novo nó ira apontar para onde o nó anterior estava apontando
      anterior->proximo = no;                                           // e o nó anterior irá apontar para o novo nó
    }
    return 1;
  }
  return 0;
}

int remover_inicio_da_lista(LISTA *lista) {
  if(lista == NULL) return 0;                                           // Verifica se a lista existe
  if((*lista) == NULL) return 0;                                        // Verificar se a lista está vazia
  ELEMENTO *no = *lista;                                                // Se não tiver vazia o nó irá receber o elemento do inicio da lista
  *lista = no->proximo;                                                 // O inicio da lista ira apontar para o elemento seguinte do nó
  free(no);                                                             // Liberar a memória do nó para poder ser deletado
  return 1;
}

int remover_final_da_lista(LISTA *lista) {
  if(lista == NULL) return 0;                                           // Verificar se a lista existe
  if((*lista) == NULL) return 0;                                        // Verificar se a lista está vazia
  ELEMENTO *anterior, *no = *lista;                                     // Criar um elemento anterior e um nó recebendo o elemento do inicio da lista
  while(no->proximo != NULL) {                                          // Enquanto o proximo nó for diferente de NULL
    anterior = no;                                                      // O anterior ira receber o valor de nó
    no = no->proximo;                                                   // E o nó ira receber o valor do proximo
  }
  if(no == (*lista))                                                    // Se o no for o inicio da lista
    *lista = no->proximo;                                               // Vamos inserir o inicio da lista no proximo elemento após o nó
  else
    anterior->proximo = no->proximo;                                    // Caso contrario o anterior ao nó irá apontar para onde aponta o nó
  free(no);                                                             // Logo em seguida vamos deletar o nó liberando sua memória
  return 1;
}

int remover_da_lista(LISTA *lista, int matricula) {
  if(lista == NULL) return 0;                                           // Verificar se a lista existe
  ELEMENTO *anterior, *no = *lista;                                     // Criar um elemento anterior e um no que irá receber o elemento do inicio da lista
  while(no != NULL && no->dados.matricula != matricula) {               // Enquanto nó for diferente de NULL e as matriculas forem diferentes
    anterior = no;                                                      // O anterior recebe o nó
    no = no->proximo;                                                   // E o nó recebe o proximo elemento
  }
  if(no == NULL) return 0;                                              // Se ao percorrer a lista não encontrar o nó com a matricula retorna zero
  if(no == *lista)                                                      // Se o nó com a matricula estiver no inicio da lista
    *lista = no->proximo;                                               // O inicio da lista vai receber o proximo nó
  else
    anterior->proximo = no->proximo;                                    // Caso contrario o nó anterior ao nó com a matricula vai receber o proximo nó
  free(no);                                                             // E o nó que tiver a matricula será liberado
  return 1;
}

int buscar_lista_posicao(LISTA *lista, int posicao, ALUNO *aluno) {
  if(lista == NULL || posicao <= 0) return 0;                           // Verificar se a lista existe e se a posição é maior que zero
  ELEMENTO *no = *lista;                                                // Criar um nó que recebe o elemento do inicio da lista
  int i = 1;                                                            // Criar um contador i que inicia em 1
  while(no != NULL && i < posicao) {                                    // Enquanto no != NULL e i for menor que a posição passada pelo usuario
    no = no->proximo;                                                   // no ira receber o proximo elemento da lista
    i++;                                                                // contador será incrementado
  }
  if(no == NULL)                                                        // Se o no for igual a NULL
    return 0;                                                           // Retorne zero
  else                                                                  // Caso contrario
    *aluno = no->dados;                                                 // Retorne os dados do aluno encontrado
  return 1;
}


int buscar_lista_matricula(LISTA *lista, int matricula, ALUNO *aluno) {
  if(lista == NULL) return 0;                                           // Verificar se a lista existe
  ELEMENTO *no = *lista;                                                // Criar um nó que recebe o elemento do inicio da lista
  while(no != NULL && no->dados.matricula != matricula)                 // Enquanto no != NULL e as matriculas forem diferentes
    no = no->proximo;                                                   // no ira receber o proximo elemento da lista
  if(no == NULL)                                                        // Se o no for igual a NULL, quer dizer que a matricula não foi encontrada.
    return 0;                                                           // Retorne zero
  else                                                                  // Caso contrario
    *aluno = no->dados;                                                 // Retorne os dados do aluno encontrado
  return 1;
}

int mostrar_lista(LISTA *lista) {
  if(lista == NULL) return 0;                                       // Verificar se a lista não existi ou a posição é menor ou igual a zero
  ELEMENTO *no = *lista;                                            // Criar um nó auxiliar que irá receber o inicio da lista
  while(no != NULL) {                                               // Enquanto o nó não chegar ao final da lista
    printf("%d %s %.2f %.2f %.2f\n", no->dados.matricula, no->dados.nome, no->dados.nota1, no->dados.nota2, no->dados.nota3);
    no = no->proximo;                                               // Continuar percorrendo a lista
  }
  return 1;
}

