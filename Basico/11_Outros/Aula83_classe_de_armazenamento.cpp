#include <stdio.h>
#include "Aula84_classe_de_armazenamento2.c"

int soma = 0;

void imprime() {
  static int n = 0;
  printf("%d\n", n++);
  soma += n;
}

int main(){

  register int i;
  for(i=0; i<10; i++){
    imprime();
  }

  escreve();

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Conjunto de modificadores que permitem alterar a maneira como o compilador vai armazenar uma
    variável.

    - São utilizadas para definir o escopo e o tempo de vida das variaveis dentro do programa.

  TIPOS DE ARMAZENAMENTO:

    - Existem quatro classes de armazenamento: auto, extern, static, register.

    - AUTO:

      > permite definir variaveis locais.
      
      > As variáveis são automaticamente alocadas no início de uma função/bloco de comandos, 
      e automaticamente liberadas quando essa função/bloco de comandos termina.

      > Modo padrão de definição de variáveis e, por esse motivo, raramente usados

      > As variaveis a seguir possui a mesma classe de armazenamento

        int x;
        auto int y;

    - STATIC

      > Seu funcionamento depende de como ela é utilizada.

      > É o modo padrão de definição de variáveis globais e, por esse motivo, raramente é usada
      na declaração das variáveis globais.

      > As variáveis a seguir possui a mesma classe de armazenamento.

        int x = 20;
        static int y = 10;

        int main() {...}

      > Também pode ser definidas como variáveis locais, no caso delas serem definidas dentro de uma
      função.

      > Nesse caso, a variável é inicializada em tempo de compilação (valor constante) e manterá o
      seu valor entre as diferentes chamadas da função.

      > Também pode ser utilizado para definir funções, assim garantimos que a função será visivel
      apenas dentro daquele arquivo do programa, ou seja, apenas funções dentro daquele arquivo
      poderão ver uma função static.

    - REGISTER

      > Serve para especificar que uma variavel será muito utilizada e que seria interessante
      armazena-la no registrador da CPU do computador

      > Acesso mais rapido que a RAM

      > É como uma dica de armazenamento que damos ao compilador.

      > O compilador é livre para decidir se vai ou não armazenar essa variavel no registrador.

        register int y;

      > Não se pode mais usar o operador de endereço & porque a variavel está no registrador e
      não na memoria

      > Apenas variaveis com poucos bytes podem ser definidas como register, pois o tamanho do
      registrador é limitado

      > Raramente utilizada, já que os compiladores modernos fazem trabalhos de otimização na
      alocação de variáveis melhores que os programadores.


------------------------------------------------------------------------------------------ */