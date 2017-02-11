#include <stdio.h>

int soma(int a, int b){
  return a+b;
}

int main() {

  int x, y, z;
  int (*p)(int, int);

  printf("Digite 2 números: ");
  scanf("%d %d", &x, &y);

  // Recebendo o endereço da função
  p = soma;

  // z recebe a função apontada por p com os parametros x e y 
  z = p(x, y);

  printf("Soma = %d\n", z);

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Uma função é um conjunto de instrução armazenado na memória.

    - Podemos acessar uma função por meio de um ponteiro que aponte para onde a função está
    na meḿória.

    - Isso permite a construção de código genérico.

  EXEMPLO:

    - Podemos definir um algoritmo que ordene numeros inteiros e querer reutilizar
    essa implementação para ordenar outros tipos de dados.

    - Em vez de reescrever toda a função de ordenação, podemos passar para a função o ponteiro
    da função de comparação que desejamos utilizar para cada tipo de dado.

  DECLARAÇÃO:

      tipo_retornado (*nome_do_ponteiro)(lista_de_tipos);

  OBSERVAÇÕES:

    - O nome do ponteiro deve sempre ser colocado entre parenteses juntamente com o asterisco.

    - Isso é necessário para evitar confusões com declarações de funções que retornem ponteiros

        tipo_retornado *nome_da_função(lista_de_parametros){...}

    - Um ponteiro para função só pode apontar para funções que possuam o mesmo prototipo.

  EXEMPLOS:

      int (*ptr)(int, int);

    - Ele poderá apontar para qualquer função que receba dois parametros inteiro e retorne um valor
    inteiro por exemplo:

      int soma(int x, int y);

    - O nome de uma função é o seu endereço na memória prt = soma

  LEMBRETES:

    > Ponteiro não inicializados apontam para lugares indefinidos

    > O ponteiro para função também pode ser inicializado com a constante NULL.

---------------------------------------------------------------------------------------- */