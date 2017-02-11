#include <stdarg.h>
#include <stdio.h>

int soma_int(int n, ...){
  va_list lista;

  int i, soma = 0;

  va_start(lista, n);

  for(i=0; i<=n; i++){
    soma += va_arg(lista, int);
  }

  va_end(lista);

  return soma;
}

int main() {

  int soma = 0;

  soma = soma_int(2, 4, 5);

  printf("Soma 2 parâmetros: %d\n", soma);

  soma = soma_int(4, 4, 5, 6, 10);

  printf("Soma 4 parâmetros: %d\n", soma);

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Funções com parametros variados, por exemplo o printf(), podem ser utilizadas com um
    dois, três ou mais parâmetros.

    - Podemos escrever funções que aceitam quantidades variável de parâmentros, que podem ser
    de diversos tipos, como é o caso da função printf() e scanf().

    - Para declarar uma função com quantidades variáveis de parâmentros, basta colocar "..."
    como o ultimo parâmetro na declaração da função.

  DECLARAÇÃO:

    - tipo_retorno nome_funcao(lista_parâmetros, ...){}

  IMPORTANTE:

    - Uma função com quantidade variável de parâmetros deve possuir pelo menos um parâmetro
    normal antes do ..., ou seja, antes das partes variáveis 

    - Isso é necessário porque a função não sabe quantos parâmentros será passado para ela e
    nem o seu tipo

    - Portanto, o primeiro parâmetro deve ser usado para informar isso dentro da função.

  EXEMPLO:
    
    - A função printf() e scanf() sabe quantos parâmetros ela receberá, e os seu tipos, por
    meio dos tipos de saída presentes dentro do primeiro parâmetro.

      "%c" para char, "%d" para int, e etc...

  BIBLIOTECA DE USO:

    - A biblioteca "stdarg.h" possui as definições de tipos e macros necessárias para acessar
    a lista de parâmetros da função.

  TIPOS E MACROS:

    - va_list: 
      
      > Tipo usado como parâmetro para as macros definidas na biblioteca "stdarg.h"
        para recuperar os parâmetros adicionais da função.

    - va_start(lista, ultimo_parametro):
      
      > Macro que inicializa uma variável "lista", do tipo "va_list", com as informações
        necessárias para recuperar os parâmetros adicionais.

    - va_arg(lista, tipo_dado)
      
      > Macro que retorna o parâmetro atual contido na variável "lista", do tipo "va_list"
        sob a forma do tipo informado em "tipo_dado".

      Em seguida, a macro move a variável lista para o próximo parâmetro, se este existir.

      > Exemplo: x = va_arg(lista, float)
        
        Retornará para a variável "x" o valor do parâmetro "atual" em "lista" formatado para
        o tipo float.

        Se o parâmetro atual da lista for %f transforme para float e armazene em x

    - va_end(lista)

      > Essa macro deve executar antes da finalização da função (ou do comando return se ele 
      existir), seu objetivo e destruir a variável lista de modo apropriado.

  CUIDADO:

    - Não existe definição de tipos

      > Funções com quantidades variáveis de parâmetros devem ser usadas com moderação porque
      potencial muito grande para que uma função projetada para trabalhar com um tipo seja
      usada com outro.

    - Não existe segurança baseada em tipo (type-safety)

      > Funções com quantidades variáveis de parâmetros podem expor o programa a uma série de
      problemas de segurança baseada em tipo (type-safety)

      > Pode-se tentar recuperar mais parâmetros do que foram passados, corrompendo assim
      o funcionamento do programa, que poderá apresentar comportamento inesperado.

      > Exemplo, tente passa um float usando um %d no printf(), irá ter erro

------------------------------------------------------------------------------------------- */