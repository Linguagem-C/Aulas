#include <stdio.h>

int main() {
	printf("Aula Teorica!\n");

	return 0;
}


/* Compilar esse código junto com o da aula02 e utilizar a tag -lm */

/* -------------------------------- RESUMO DO CÓDIGO ------------------------------

	TIPO DE DADOS:

		- Define o conjunto de valores (dóminio) que uma variável pode assumir.

		- Exemplo:

			int -> ..., -2, -1, 0, 1, 2, ...

	ESTRUTURA DE DADOS:

		- Trata-se de uma relação lógica entre tipos de dados.

		- Exemplo: 

			struct pessoa {
				int idade;
				char nome;
				float salario;
			}

	TIPO ABSTRATO DE DADOS (TAD):

		- Operações para manipular dados.

		- Exemplo:

			1) Criação da estrutura.
			2) Inclusão de um elemento.
			3) Remoção de um elemento.
			4) Acesso a um elemento.
			5) etc ...

	VANTAGENS:

		- Encapsulamento e segurança:

			> Usuário não tem acesso direto aos dados, precisa dessas funções para 
			acessa-los

		- Flexibilidade e Reutilização:

			> Podemos alterar o TAD sem alterar as aplicações que o utilizam.

		- Exemplo:

			> FILE *arq;

				Nos nunca conseguimos acessar oq tem dentro do "arq" somente através de
				métodos como fprintf() fopen() fclose() e etc...



---------------------------------------------------------------------------------- */
