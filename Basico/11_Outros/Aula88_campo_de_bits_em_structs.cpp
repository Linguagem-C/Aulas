#include <stdio.h>

struct status {
  unsigned int ligado:1; //valores 0 ou 1
  signed int valor:4; //valores de -8 a 7, já que 1 bit é de sinal
  unsigned int :3; //sem nome! completa 8 bits
};

void check_status(struct status s) {
  if(s.ligado == 1){
    printf("Ligado!\n");
  }
  if(s.ligado == 0){
    printf("Desligado!\n");
  }
}

int main() {

  struct status ESTADO;

  ESTADO.ligado = 1;

  check_status(ESTADO);  

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Trabalhando com campos de bits podemos acessar diretamente os bits, ou um único bit,
    sem fazer uso dos operadores bit a bit.

    - Trata-se de um tipo especial de membro de estruturas e unios chamados de campos de bits
    ou bitfield

    - Seu uso é extremamente útil quando a quantidade de memória para armazenamento de dados é
    limitada

      ex: flags, comunicação com dispositivos de hardware e etc...

  DECLARAÇÃO:

      tipo nome_campo: comprimento;

  OBSERVAÇÕES:

    - O valor do comprimento pode ser um número ou uma expressão constante.

    - O comprimento de um campo de bits não deve exceder o número total de bits do tipo
    da variável utilizada na declaração.

    - Só pode ser declarado como do tipo int sendo possivel utilizar os modificadores signed
    e unsigned

    - Se ele for do tipo int ou signed int seu comprimento deve ser maior que 1 por causa
    do bit de sinal.

    - Campo de bits sem nome são úteis para preencher uma estrutura de modo a fazer com que ela 
    esteja adequada a um layout especificado, não podem ser acessados ou inicializados.

    - Campos de bits podem ter comprimento zero, não podem possuir nome, e sua função é de
    fazer com que o próximo campo de bits seja alinhado com o próximo byte da memória do
    mesmo tipo do campo de bits.

    - Em outras palavras, um campo de bits de comprimento zero indica que nenhum campo de bits
    adicional deve ser colocado dentro desse byte.

    - Campos de bits não possuem endereço, logo não podem ser acessados com o operador &

    - Não pode ter ponteiro ou array deles, e o operador sizeof tb não pode ser utilizado.

------------------------------------------------------------------------------------------- */