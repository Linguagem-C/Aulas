#include <stdlib.h>
#include <stdio.h>

/* Inserir 2 strings e n numeros */
int main(int argc, char *argv[]){

  if (argc == 1){
    printf("Programa %s sem parametros\n", argv[0]);
  }else{
    int i, soma=0;
    printf("Parametro do programa %s:\n", argv[0]);
    printf("Parametro 1: %s\n", argv[1]);
    printf("Parametro 2: %s\n", argv[2]);
    for(i=3; i<argc; i++){
      soma = soma + atoi(argv[i]);
    }
    printf("Soma = %d\n", soma);
  }

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Vimos que o main() indicava a função principal do programa, ela é responsavel pelo 
    inicio da execução do programa.

    - A função main() também pode receber uma lista de parâmetros no inicio da execução 
    do programa.

    - Esses parametros virão da prompt da linha de comando do sistema operacional

  PARÂMETROS:

    - int argc = Valor que indica o número de parametros com as quais a função main() 
                 foi chamada (args >= 1)

    - char *argv[] = Ponteiro para um vetor contendo "argc" strings. cada string é um 
                     dos parametros para a main.

    - argv[0] sempre aponta para o nome do programa.

  OBSERVAÇÕES:

    - Os parametros são passados após a compilação ao executar o ./prog Parametros.....

    - Todos os parametros passado são strings, para converter string para inteiro usamos 
    a função atoi();

----------------------------------------------------------------------------------------- */