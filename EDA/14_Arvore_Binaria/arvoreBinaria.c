#include "lib/arvoreBinaria.h"

struct NO {
  ALUNO aluno;
  struct NO *esquerda;
  struct NO *direita;
};

ARVORE *criar_arvore_binaria() {
  ARVORE *raiz = (ARVORE*) malloc(sizeof(ARVORE));                    // Alocar memoria para a raiz da arvore binaria
  if(raiz != NULL)                                                    // Se deu certo a alocação
    *raiz = NULL;                                                     // O conteudo da raiz será NULL e futuramente ira apontar para o inicio da arvore
  return raiz;                                                        // Retorna a raiz da arvore
}

void liberar_no(struct NO *no) {
  if(no == NULL) return ;                                             // Se o nó for nula ele já ta liberado
  liberar_no(no->esquerda);                                           // Percorrer recursivamente os nós da esquerda da arvore até o final (folha) e libera ela
  liberar_no(no->direita);                                            // Percorrer recursivamente os nós da direita da arvore até o final (folha) e libera ela
  free(no);                                                           // Quando eu voltar da esquerda e da direita eu libero o nó pai delas e assim até a raiz
  no = NULL;                                                          // Coloco NULL nele para evitar futuros conflitos
}

void liberar_arvore_binaria(ARVORE *raiz) {
  if(raiz == NULL) return;                                            // Verificar se há memoria para ser liberada
  liberar_no(*raiz);                                                  // Percorre a arvore e libera cada um dos nós
  free(raiz);                                                         // Libera o nó raiz da arvore
}

int esta_vazia(ARVORE *raiz) {
  if(raiz == NULL) return 1;                                          // Se a raiz não existir, a arvore esta vazia
  if(*raiz == NULL) return 1;                                         // Se o conteudo da raiz não exitir, a arvore esta vazia
  return 0;                                                           // Caso contrario ela está cheia
}

int altura_da_arvore(ARVORE *raiz) {
  if(raiz == NULL) return 0;                                          // Verificar se a arvore foi criada
  if(*raiz == NULL) return 0;                                         // Verificar se a arvore esta vazia
  int altura_esquerda = altura_da_arvore(&((*raiz)->esquerda));       // Percorrer recursivamente a sub-arvore da esquerda até encontrar o nó folha
  int altura_direita = altura_da_arvore(&((*raiz)->direita));         // Percorrer recursivamente a sub-arvore da direita até encontrar o nó folha
  if(altura_esquerda > altura_direita)                                // Verifica qual das alturas das sub-arvores é maior
    return (altura_esquerda + 1);                                     // A altura do nó onde estou é a altura da maior sub-arvore + 1
  else
    return (altura_direita + 1);                                      // A altura do nó onde estou é a altura da maior sub-arvore + 1
}

int total_de_nos(ARVORE *raiz) {
  if(raiz == NULL) return 0;                                    // Verifica se a arvore foi criada
  if(*raiz == NULL) return 0;                                   // Verifica se a arvore está vazia
  int nos_da_esquerda = total_de_nos(&((*raiz)->esquerda));     // Percorrer recursivamente a sub-arvore da esquerda até encontrar o nó folha passando seu endereço
  int nos_da_direita = total_de_nos(&((*raiz)->direita));       // Percorrer recursivamente a sub-arvore da direita até encontrar o nó folha passando seu endereço
  return (nos_da_esquerda + nos_da_direita + 1);                // Somar o número de nós da esquerda e da direita mais 1 resultando no total de nós da arvore
}

void percorrer_arvore_pre_ordem(ARVORE *raiz) {
  if(raiz == NULL) return;                                      // Verifica se a arvore existe
  if(*raiz != NULL) {                                           // Se ela existir
    printf("%d\n", (*raiz)->aluno.matricula);                   // Imprime o conteudo do nó
    percorrer_arvore_pre_ordem(&((*raiz)->esquerda));           // Visito o filho da esquerda até o nó folha
    percorrer_arvore_pre_ordem(&((*raiz)->direita));            // Visito o filho da direita
  }
}

void percorrer_arvore_em_ordem(ARVORE *raiz) {
  if(raiz == NULL) return;                                      // Verifica se a arvore existe
  if(*raiz != NULL) {                                           // Se ela existir
    percorrer_arvore_em_ordem(&((*raiz)->esquerda));            // Visito o filho da esquerda até o nó folha
    printf("%d\n", (*raiz)->aluno.matricula);                   // Imprime o conteudo do nó
    percorrer_arvore_em_ordem(&((*raiz)->direita));             // Visito o filho da direita
  }
}

void percorrer_arvore_pos_ordem(ARVORE *raiz) {
  if(raiz == NULL) return;                                      // Verifica se a arvore existe
  if(*raiz != NULL) {                                           // Se ela existir
    percorrer_arvore_em_ordem(&((*raiz)->esquerda));            // Visito o filho da esquerda até o nó folha
    percorrer_arvore_em_ordem(&((*raiz)->direita));             // Visito o filho da direita
    printf("%d\n", (*raiz)->aluno.matricula);                   // Imprime o conteudo do nó
  }
}

int inserir_no(ARVORE *raiz, int matricula) {
  if(raiz == NULL) return 0;                                    // Verifica se a arvore existe
  struct NO *novo;                                              // Criar um novo nó
  novo = (struct NO*) malloc(sizeof(struct NO));                // Alocar memoria para esse novo nó
  if(novo == NULL) return 0;                                    // Verificar se a memoria do novo nó foi alocada
  novo->aluno.matricula = matricula;                            // Inserir o conteudo no novo nó
  novo->direita = NULL;                                         // O novo nó sempre será uma nova folha na arvore logo
  novo->esquerda = NULL;                                        // a direita e a esquerda dele será NULL
  if(*raiz == NULL) {                                           // Se a arvore estiver vazia
    *raiz = novo;                                               // Inserir o novo nó nela
  } else {                                                      // Caso contrario
    struct NO *atual = *raiz;                                   // Criar um novo nó auxiliar chamado atual que irá apontar para o começo da arvore
    struct NO *anterior = NULL;                                 // Criar um novo nó auxiliar chamado anterior que irá apontar para null
    while(atual != NULL) {                                      // Enquanto o nó atual não chegar em um nó folha vou descendo na arvore
      anterior = atual;                                         // O nó anterior irá receber o atual
      if(matricula == atual->aluno.matricula) {                 // Se o valor inserido for igual ao conteudo do nó atual
        free(novo);                                             // delete o novo nó pois ele já existe na arvore
        return 0;                                               // Saia da função
      }
      if(matricula > atual->aluno.matricula)                    // Se o valor inserido for maior que o conteudo do nó atual
        atual = atual->direita;                                 // O atual irá para o nó da direita
      else                                                      // Caso o valor inserido seja menor que o conteudo do nó atual
        atual = atual->esquerda;                                // O atual irá para o nó da esquerda

    }
    if(matricula > anterior->aluno.matricula)                   // Se ao chegar no nó folha o valor inserido for maior que o conteudo da folha
      anterior->direita = novo;                                 // Inserir o novo nó no lado direito do nó folha
    else                                                        // Caso contrario
      anterior->esquerda = novo;                                // Inserir o novo nó no lado esquerdo do nó folha
  }
  return 1;
}

struct NO *remover_atual(struct NO *atual) {
  struct NO *no1, *no2;                                   // Criamos dois nós auxiliares
  if(atual->esquerda == NULL) {                           // Verifica se o nó atual da esquerda é uma folha (tratá nó folha e com 1 filho)
    no2 = atual->direita;                                 // Se for o nó2 irá receber o nó filho da direita que é o maior antes do atual
    free(atual);                                          // Deleta o nó atual
    return no2;                                           // Retorna o nó2 para ser inserido no nó atual
  }
  no1 = atual;                                            // Caso o nó a esquerda não seja a folha o nó1 irá receber o nó atual
  no2 = atual->esquerda;                                  // E o nó2 irá receber o nó a esquerda do atual
  while(no2->direita != NULL) {                           // Iremos procurar o nó filho mais a direita na sub-arvore da esquerda descendo a arvore
    no1 = no2;                                            // nó1 irá receber o nó2 até encontrar o nó folha a direita
    no2 = no2->direita;                                   // nó2 irá receber o nó2 mais a direita até encontrar o nó folha a direita
  }

                                                          // Ira copiar o filho mais a direita na sub-arvore a esquerda para o lugat do nó removido
  if(no1 != atual) {                                      // Ao encontrar o ultimo nó a direita e armazenar no nó2 iremos verificar se o nó1 é diferente do atual
    no1->direita = no2->esquerda;                         // Se for o nó1 a direita irá receber o nó2 a esquerda
    no2->esquerda = atual->direita;                       // E o nó2 a esquerda irá receber o nó atual a direita
  }
  no2->direita = atual->direita;                          // O nó2 a direita irá receber o nó atual da direita
  free(atual);                                            // Deletar o nó atual
  return no2;                                             // Retorna o nó2 para ser inserido no nó atual
}

int remover_no(ARVORE *raiz, int matricula) {
  if(raiz == NULL) return 0;                                // Verifica se a arvore existe
  struct NO *anterior = NULL;                               // Cria um nó auxiliar que ira receber os nós anteriores ao atual, inicialmente como NULL
  struct NO *atual = *raiz;                                 // Cria um nó auxiliar que ira receber o nó atual, inicialmente como o primeiro elemento da arvore
  while(atual != NULL) {                                    // Enquanto o nó atual não chegar ao final da arvore
    if(matricula == atual->aluno.matricula) {               // Verificar se o valor inserido é igual ao conteudo do nó atual
      if(atual == *raiz) {                                  // Se for igual verificar se o conteudo do nó atual é o primeiro elemento da arvore ou raiz dela
        *raiz = remover_atual(atual);                       // Se for a raiz da arvore irá receber o retorno da função remove_atual() com o nó que ira ser removido
      }else{                                                // Caso contrario
        if(anterior->direita == atual)                      // Se não é a raiz da arvore então ou é o filho da direita ou da esquerda do atual, se for da direita
          anterior->direita = remover_atual(atual);         // O anterior aponta para o atual, a função irá retorna o novo nó para onde o anterior ira apontar
        else                                                // Caso contrario
          anterior->esquerda = remover_atual(atual);        // O anterior aponta para o atual, a função irá retorna o novo nó para onde o anterior ira apontar
      }
      return 1;                                             // Ao ser eliminado sair da função
    }
    anterior = atual;                                       // Caso o valor não seja igual ao conteudo do nó atual
    if(matricula > atual->aluno.matricula)                  // Verificar se o valor é maior que o conteudo do nó atual
      atual = atual->direita;                               // Se for maior andar para a direita da arvore a procura do nó a ser removido
    else                                                    // Caso contrario
      atual = atual->esquerda;                              // Se for menor andar para a esquerda da arvore a procura do nó a ser removido
  }
  return 0;
}

int consulta_arvore_binaria(ARVORE *raiz, int matricula) {
  if(raiz == NULL) return 0;                                // Verificar se a arvore existe
  struct NO *atual = *raiz;                                 // Criar um nó auxiliar chamado atual que irá receber o primeiro elemento da arvore
  while(atual != NULL) {                                    // Enquanto não chegar no fim da arvore
    if(matricula == atual->aluno.matricula) return 1;       // Verificar se o valor inserido é igual ao conteudo do nó atual se for achou
    if(matricula > atual->aluno.matricula)                  // Verificar se o valor inserido é maior que o conteudo do nó atual
      atual = atual->direita;                               // Se for o nó atual irá para a direita
    else                                                    // Caso contrario
      atual = atual->esquerda;                              // O atual irá para a esquerda
                                                            // O processo é repetido até achar o valor inserido dentro da arvore ou chegar no final da arvore
  }
  return 0;                                                 // Não achou o valor inserido na arvore
}
