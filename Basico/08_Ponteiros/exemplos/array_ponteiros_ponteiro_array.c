#include <stdio.h>

int main() {

   // ponteiro de arrays (ponteiro para um array de 10 inteiros)
  int (*p3)[10];

  // Array de ponteiros (array de 10 ponteiros para inteiros)
  int *p4[10];


  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

RELEMBRANDO:

  - Arrays são agrupamentos sequenciais de dados do mesmo tipo de memória.

  - O nome do array é apenas um ponteiro que aponta para o primeiro elemento do array.

  - Podemos atribuir o endereço de um array a um ponteiro de duas formas:

    int vet[5] = {1, 2, 3, 4, 5}
    int *p1 = vet;
    int *p2 = &vet[0];

  - A linguagem C também permite o uso de arrays e ponteiros de forma conjunta na declaração
  de variáveis.

EXEMPLOS:

  - Cria um tipo array de 10 inteiros

    typedef int vetor[10];

  - Declarando um array de 10 inteiros

    vetor p1;

  - Ponteiro para o tipo array de 10 inteiros.

    vetor *p2;

    int (*p3)[10];

  - Note que (*p3) está dentro de parênteses, temos então um ponteiro para um 
  "array de 10 inteiros" (p2 e p3 são equivalentes)

    int *p4[10];

  - Apesar de semelhante a declaração de p3, note que p4 não tem parenteses, temos então
  um array de 10 "ponteiros para inteiros"

-------------------------------------------------------------------------------------- */