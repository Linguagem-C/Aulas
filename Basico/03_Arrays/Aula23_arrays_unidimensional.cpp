#include <stdio.h>
#include <stdlib.h>
#define N 5

int main() {

	float notas[N], media=0.0;
	int i;

	for(i=0; i<N; i++){
		printf("Digite a nota do aluno %d: ", i);
		scanf("%f", &notas[i]);
		media += notas[i];
	}

	media /= N;
	printf("A média foi: %.1f\n\n", media);

	for(i=0; i<N; i++){
		if(notas[i] > media)
			printf("Aluno %d: %.1f\n", i, notas[i]);
	}

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

ARRAY UNIDIMENSIONAL: -------------------------------------------
	- Conjunto de variáveis do mesmo tipo usando o mesmo nome

	tipo nome_array[tamanho];
	float nota[100]; //guarda a nota de 100 alunos

TAMANHO DE UM ARRAY: --------------------------------------------
	- O tamanho de um array tem que ser sempre um valor ou expressão 
	inteira e constante(#define CONSTANTE 100)

	int = 5;
	float F[CONSTANTE+1]; //CERTO
	char txt[30]; //CERTO
	int vetor[n]; //ERRADO
	int V[4.5]; //ERRADO

POSIÇÃO DE UM ARRAY: ---------------------------------------------
	- Como acessar os elementos dentro de um array, através do indice
	- No caso do exemplo abaixo cada posição do array corresponde a 
	um aluno
	- O array vai de 0 até n-1

	float notas[100];
	notas[0] = 8.1; //Inserir a nota 8.1 na primeira posição do array
	notas[1] = 5.5; //Inserir a nota 5.5 na segunda posição do array
	...
	notas[99] = 7.2; //Inserir a nota 7.2 na ultima posição do array

COMANDOS EM UM ARRAY: --------------------------------------------
	- Como o array é um conjunto de variáveis então posso fazer tudo 
	que eu posso fazer com um única variável

	float notas[100], vetor[100];
	scanf("%d", &notas[5]); //Comando de escrita
	printf("%d\n", notas[5]); //Comando de leitura
	notas[0] = 5.0; //Comando de atribuição
	notas[1] = notas[5] + notas[0]; //Expressões
	notas[5] = vetor[3]; //Comando de atribuição
	notas = vetor; //ERRADO, teria que copiar posição por posição do array
	
-----------------------------------------------------------------------------*/