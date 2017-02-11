#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
	char nome[50], rua[50];
	int idade, numero;
};
 
//Limpa o buffer do teclado após scanf
void flush_in(){
    int ch;
    do{
        ch = fgetc(stdin);
    }while (ch != EOF && ch != '\n');
}

int main() {

	//struct pessoa p1, p2, p3, p4;
	struct pessoa p[4];
	int i;

	for(i=0; i<4; i++){
		printf("Insira o %d° nome: ", i+1);
		fgets(p[i].nome, 50, stdin);
		printf("Insira a %d° idade: ", i+1);
		scanf("%d", &p[i].idade);
		flush_in();
		printf("Insira a %d° rua: ", i+1);
		fgets(p[i].rua, 50, stdin);
		printf("Insira o %d° numero: ", i+1);
		scanf("%d", &p[i].numero);
		flush_in();
	}


	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

	DEFINIÇÃO:

		- A struct é um tipo de dado, e portanto a linguagem C suporta
		a declaração de uma array de estrutura.

		- Em um array de estrutura, o operador de ponto vem sempre depois
		dos colchetes [] do indice do array

		- Usado normalmente para criar cadastro de vários usuários, pois você
		consegue manipular várias variáveis de estrutura.

		- P[Indice].Campo
		- P[Linha][Coluna].Campo

	EXEMPLOS:
			p[0].idade = 31;
			p[0].numero = 110;
			strcpy(p[1].nome, "Ricardo");
			p[2].numero = p[0].numero -1;

		- A função flush_in vai repetitivamente ler o buffer de entrada
		até encontrar uma quebra de linha ou até que o buffer acabe.
		Ou seja, vai consumir toda a linha atual.

------------------------------------------------------------------------------ */
