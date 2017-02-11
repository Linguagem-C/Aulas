#include "pilha.h"

struct elemento {
  LIVRARIA dados;
  struct elemento *proximo;
};

typedef struct elemento ELEMENTO;

PILHA *criar_pilha() {
  PILHA *pilha = (PILHA*) malloc(sizeof(PILHA));                   // Crio o topo da pilha e aloco memoria para ela
  if(pilha != NULL) {                                              // Verifico se a alocação deu certo
    *pilha = NULL;                                                 // Primeiro elemento da pilha será nulo
  }
  return pilha;                                                    // Retorna a pilha criada
}

void liberar_pilha(PILHA *pilha) {
  if(pilha != NULL) {                                              // Verificar se a pilha existe
    ELEMENTO *no;                                                  // Criar um elemento auxiliar
    while((*pilha) != NULL) {                                      // Enquanto a o inicio da pilha não for nulo, enquanto não tiver alguém na pilha
      no = (*pilha);                                               // Nó auxiliar irá receber o inicio da pilha
      (*pilha) = (*pilha)->proximo;                                // E o inicio da pilha irá para o proximo elemento
      free(no);                                                    // Liberar o nó que armazenou o inicio da pilha
    }
    free(pilha);                                                   // Assim que todos os elementos da pilha forem liberados, destruir a pilha
  }
}

int tamanho_da_pilha(PILHA *pilha) {
  if(pilha == NULL) return 0;                                      // Verificar se teve problema na alocação de memoria da pilha
  int contador = 0;                                                // Cria um contador e inicializa com 0
  ELEMENTO *no = (*pilha);                                         // Cria um nó auxiliar e inicializa com o inicio da pilha
  while(no != NULL) {                                              // Enquanto nó não chega no final da pilha
    contador++;                                                    // Incrementa o contador
    no = no->proximo;                                              // Vai para o proximo elemento da pilha
  }
  return contador;                                                 // Retorna o tamanho da pilha
}

int pilha_vazia(PILHA *pilha) {
  if(pilha == NULL) return 1;                                      // Verificar se a alocação deu tudo certo
  if((*pilha) == NULL) return 1;                                   // Se o inicio da pilha é nulo, a pilha está vazia
  return 0;                                                        // Caso contrario retorna falso
}

int entrar_na_pilha(PILHA *pilha, LIVRARIA livro) {
  if(pilha == NULL) return 0;                                    // Verificar se a pilha existe
  ELEMENTO *no = (ELEMENTO*) malloc(sizeof(ELEMENTO));           // Criar um elemento auxiliar
  if(no == NULL) return 0;                                       // Se a alocação não funcionou retorna erro
  no->dados = livro;                                             // Inserir os dados do livro
  no->proximo = (*pilha);                                        // O proximo elemento da pilha irá ser o inicio da pilha
  (*pilha) = no;                                                 // E o inicio da pilha será o novo nó
  return 1;
}

int sair_da_pilha(PILHA *pilha) {
  if(pilha == NULL || pilha_vazia(pilha)) return 0;                // Se a pilha não existir ou estiver vazia não se pode remover da pilha
  ELEMENTO *no = (*pilha);                                         // Criar um nó auxiliar com o inicio da pilha
  (*pilha) = (*pilha)->proximo;                                    // Inicio da pilha recebe o elemento que vem depois dela
  free(no);                                                        // Libera o nó que armazenou o inicio da pilha anterior
  return 1;
}

int consultar_pilha(PILHA *pilha, LIVRARIA *livro) {
  if(pilha == NULL || pilha_vazia(pilha)) return 0;                // Se a pilha não existir ou estiver vazia não se pode consultar o primeiro elemento da pilha
  *livro = (*pilha)->dados;                                        // O livro recebe os dados do primeiro elemento da pilha
  return 1;
}

