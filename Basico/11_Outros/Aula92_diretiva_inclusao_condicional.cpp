#include <stdio.h>
#define tamanho 55

int main() {

  #ifdef valor
    printf("Valor definido\n");
    int vetor[valor];
  #elif tamanho > 55
    #undef tamanho
    #define tamanho 55
    int vetor[tamanho];
  #else
    printf("Valor não definido\n");
    #define valor 55
    int vetor[valor];
  #endif

  printf("Tamanho: %d Valor: %d\n", tamanho, valor);


  
  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DIRETIVAS DE INCLUSÃO CONDICIONAL:

    - São estruturas condiciconais do pré-processador da linguagem C

    - Elas permitem excluir ou descartar parte do código de um programa sempre que
    determinada condição for satisfeita.

  LISTA DE DIRETIVAS:

    #ifdef
    #ifndef
    #if
    #else
    #elif

    - Para indicar o fim de uma diretiva de inclusão condicional usamos: #endif

  DIRETIVAS #ifdef E #ifndef

    - Essas diretivas permitem verificar se uma determinada macro foi previamente 
    definida #ifdef ou não #ifndef

    #ifdef nome_da_macro       #ifndef nome_da_macro
      código                      Código
    #endif                     #endif

    - As diretivas #if, #else e #elif são iguais aos comandos if, else, else if

    - As diretivas #if e #elif só podem ser utilizadas para avaliar expressões constantes

---------------------------------------------------------------------------------------- */