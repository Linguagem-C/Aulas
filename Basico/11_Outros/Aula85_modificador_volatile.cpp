#include <stdio.h>

int resposta1;

void espera1() {
  resposta1 = 0;
  while(resposta1 != 255); /* Feito pelo programador */
}

/* --------------------------------- RESUMO DO CÓDIGO ----------------------------------------

  - O compilador otimizado notará que nenhum outro código pode modificar o valor da variável
  resposta e substituirá a condição por 1, indicando assim também um laço infinito, mas
  economizando a contagem da variavel resposta

/* ----------------------------------------------------------------------------------------- */

int resposta2;

void espera2() {
  resposta2 = 0;
  while(1); /* Interpretado pelo compilador */
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  - Vamos supor que a variavel resposta possa ser modificada a qualquer momento por um
  dispositivo de hardware mapeado na memória RAM

  - Neste caso, o seu valor pode ser modificado enquanto ela estiver sendo testada no
  comando while, finalizando o laço.

  - Para impedir que o compilador faça esse tipo de otimização, utilizamos o modificador volatile

------------------------------------------------------------------------------------------ */

  int resposta3;

  void espera3(){
    resposta3 = 0;
    while(*(volatile int*)&resposta3 != 255);
  }

int main() {
  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  - Pode ser aplicado a qualquer declaração de variável, incluindo estruturas, uniões e
  enumerações.

  - Informa ao compilador que aquela variável poderá ser alterada por outros meios e,
  por esse motivo, ela não deve ser otimizada.

    volatile tipo nome;
    volatile int x;

  - O principal motivo de uso tem a ver com problemas que trabalham com sistemas dinâmicos,
  em tempo real e comunicação com dispositivos de hardware mapeado por memória.

----------------------------------------------------------------------------------------- */