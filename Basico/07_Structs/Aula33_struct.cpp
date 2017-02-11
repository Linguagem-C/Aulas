#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
	char nome[50], rua[50];
	int idade, numero;
};

int main() {

	//Declaração de uma variavel struct
	struct pessoa p1, p2, p3;


	p1.idade = 31;
	p1.numero += p1.idade +110;

	printf("Digite o nome da pessoa: ");
	fgets(p1.nome, 50, stdin);


	printf("A idade da pessoa é %d\n", p1.idade);
	printf("O Número da pessoa é %d\n", p1.numero);
	printf("O nome da pessoa é %s\n", p1.nome);

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

	DEFINIÇÃO:

		- Struct é como um array que pode ter qualquer tipo de variavel.

		- A linguagem C nos permite também criar nosso proprio tipo de variável
		um dele é o struct ou estrutura.

		- Estrutura nada mais é que empacotar um conjunto de dados de um programa

		- char, double, float, int, arrays e etc...

		- Dentro da variavel p do tipo struct pessoa vou ter as variáveis nome,
		rua, idade e numero.

		- Cada variavel da struct pode ser acessada usando o perador ponto .

		- Estruturas diferentes podem ter campos com o mesmo nome

	DECLARAÇÃO:

		struct NomeDaStruct {
			tipo1 nome1;
			tipo2 nome2;
			.
			.
			.
			tipoN nomeN
		};

	OPERAÇÕES COM STRUCTS:

		p.idade = 31;
		scanf("%d", &p.numero);
		fgets(p.nome, 50, stdin);
		p.numero = p.numero + p.idade -100;


----------------------------------------------------------------------------- */
