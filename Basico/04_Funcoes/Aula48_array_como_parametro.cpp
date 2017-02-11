#include <stdlib.h>
#include <stdio.h> 

void imprime_vetor(int *n, int m){

  int i;

  for(i=0; i<m; i++){
    printf("%d\n", n[i]);
  }

}

void imprime_matriz(int m[][2], int n){

  int i,j;

  for(i=0; i<n; i++){
    for(j=0; j<2; j++){
      printf("%d \n", m[i][j]);
    }
  }
}

int main(){
  
  int v[5] = {1, 2, 3, 4, 5};
  int mat[3][2] = {{1,2}, {3,4}, {5,6}};

  imprime_vetor(v, 5);
  imprime_matriz(mat, 3);



	 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Array é sempre passado por referencia para a função

    - Isso evita a cópia desnecessaria de grandes quantidades de dados para outra área de memória
    durante a chamada da função, o que afetaria o desempenho do programa.

    - Passando um array por referencia:

  EXEMPLOS:

    void imprime(int *m, int n);
    void imprime(int m[], int n);
    void imprimi(int m[5], int n);

  OBSERVAÇÕES:

    - n é o tamanho do vetor

    - Na função continuamos a usar colchetes [] e indices

    - Na chamada da função não precisamos passar colchetes, indices e nem o asterisco &, usa-se
    apenas o nome do array e o tamanho dele, pois o nome do vetor já é seu endereço.

    - Array com mais de uma dimensão, precisa da informação do tamanho das outras dimensões.

  
	
---------------------------------------------------------------------------------------*/