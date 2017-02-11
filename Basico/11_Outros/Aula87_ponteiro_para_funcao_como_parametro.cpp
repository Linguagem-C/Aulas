#include <stdio.h>

int executa(int (*funcao)(int, int), int x, int y){
  return funcao(x, y);
}

int max(int a, int b){
  return (a>b) ? a : b;
}

int soma(int a, int b){
  return a+b;
}

int main() {

  int x, y;

  printf("Digite 2 números: ");
  scanf("%d %d", &x, &y);

  printf("Maior = %d\n", executa(max, x, y));

  printf("Soma = %d\n", executa(soma, x, y));

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Passando um ponteiro para função como parametro:

  DECLARAÇÃO:

      > Para declara uma função que possa receber um ponteiro para função como parâmetro,
      tudo que devemos fazer é incorporar a declaração de um ponteiro para uma função dentro
      da declaração dos parâmetros da função.

        int (*ptr)(int, int);

  OBSERVAÇÕES:

      > Se quisermos passar esse ponteiro para outra função, devemos declarar esse ponteiro
      na sua lista de parâmetros.

        int executa(int (*ptr)(int, int), int x, int y){...}

  CURIOSIDADES:

    - Olhar a função qsort() para entender melhor isso.

----------------------------------------------------------------------------------------- */