#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Limpa o buffer do teclado após scanf
void flush_in(){
    int ch;
    do{
        ch = fgetc(stdin);
    }while (ch != EOF && ch != '\n');
}

struct endereco{
	char rua[50];
	int numero;
};

struct pessoa{
	char nome[50];
	int idade;
	struct endereco address;
};

int main() {

	struct pessoa p;
	p.idade = 31;
	p.address.numero = 101;

		printf("Insira o nome: ");
		fgets(p.nome, 50, stdin);
		printf("Insira a idade: ");
		scanf("%d", &p.idade);
		flush_in();
		printf("Insira a rua: ");
		fgets(p.address.rua, 50, stdin);
		printf("Insira o numero: ");
		scanf("%d", &p.address.numero);
		flush_in();



	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

	DEFINIÇÃO:

		- Estrutura também é um tipo de dado, logo uma estrutura pode possuir
		uma variável do tipo de outra estrutura previamente definida.

		- A isso chamamos de estruturas Aninhadas.

	DECLARAÇÃO:

			struct nome_struct1{
				...
			};

			struct nome_struct2{
				...
				struct nome_struct1 nome;
			};

-------------------------------------------------------------------------------- */
