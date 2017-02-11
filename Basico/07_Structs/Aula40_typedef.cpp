#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct cadastroAlunos{
	char nome[50];
	int idade;
	char matricula[20];
};

typedef int inteiro;
typedef unsigned int positivos[5];
typedef struct cadastroAlunos Alunos;

int main() {

	int x = 10, i;
	inteiro y = 20;
	positivos v = {10, 20, 30, 40, 50};

	y = y + x;

	printf("Soma = %d\n", y);

	for (i=0; i<5; i++)
		printf("v[%d]: %d\n",i, v[i]);

	Alunos al;

	al.idade = 22;

	printf("Idade: %d\n", al.idade);


	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

	DEFINIÇÃO:

		- O Comando Typedef é usado para criar “apelidos” para tipos já existentes.

		- O comando é muito usados em TADs, de forma a simplificar a criação de estruturas já definidas.

	DECLARAÇÃO:

			typedef tipoExistente novoNome

	EXEMPLO: 

			L6: positivo é uma variável unsigned(sem sinal) do tipo int com tamanho 5

			L13: Foi criado uma estrutura do tipo cadastroAlunos e usamos um typedef para criar 
			um “apelido” Alunos. O asterisco antes do nome Alunos, indica que Alunos é um 
			ponteiro para a struct cadastroAlunos.

----------------------------------------------------------------------------------------- */