#include <stdlib.h>
#include <stdio.h> 

int main(){

  int quantidade, i;
  float *salario;

  printf("Insira a quantidade de funcionarios: ");
  scanf("%d", &quantidade);

  salario = (float*) malloc(quantidade * sizeof(float));

  if(salario == NULL){
    printf("Erro, Sem memória!");
    exit(1);
  }

  for(i=0; i<quantidade; i++){
    printf("Insira o salario do %d° funcionario: ", i);
    scanf("%f", &salario[i]);
  }

   for(i=0; i<quantidade; i++){
    printf("O salario do funciorario %d° foi: %.2f\n", i, salario[i]);
  }

  free(salario);

	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - Serve para alocar memória durante a execução do programa.

  - Ela faz o pedido de memória ao computador e retorna um ponteiro com o endereço do 
  inicio do espaço de memória alocado.

  - Por padrão a função retorna um tipo void, logo a gente tem que fazer um cast para o 
  tipo desejado

  - A função malloc() recebe por parametro a quantidade de bytes a ser alocado e 
  retorna o um ponteiro para a primeira posição do array

  - Se retorna null quer dizer que deu erro, não houve memória suficiente para ser 
  alocado

  - Assim que alocar você pode usar esse ponteiro como um vetor normal.

  - Sempre que alocarmos memória ela precisa ser liberada para ser utilizado por outros 
  plicativos quando não mais necessaria, usamos a função free() pra isso

------------------------------------------------------------------------------------------*/