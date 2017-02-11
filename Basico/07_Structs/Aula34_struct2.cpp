#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
	char nome[50], rua[50];
	int idade, numero;
};
 
struct ponto {
	int x, y;
};

struct novo_ponto{
	int x, y;
};

int main() {

	//Inicializando: nome, rua, idade, numero
	struct pessoa p1 = {"Ricardo", "Rua 1", 31, 101};
	struct pessoa p2;
	struct ponto pt1, pt2={1,2};
	struct novo_ponto pt3={3,4};

	//Sendo do msm tipo pode fazer a copia de uma para outra struct
	//pt1 = pt3 -> ERRO, não são do mesmo tipo
	p2 = p1;
	pt1 = pt2;

	printf("pt1 = %d e %d\n", pt1.x, pt1.y);
	printf("Nome: %s\n", p2.nome);
	printf("Rua: %s\n", p2.rua);
	printf("Idade: %d\n", p2.idade);
	printf("Numero: %d\n", p2.numero);






	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

	- Podemos definir uma lista de valores para colocar na estrutura,
	como nos arrays

	- Campos não definidos são inicializados com zeros ou com string vazia ""

	- A estrutura suporta atribuição, desde que elas sejam do mesmo tipo

------------------------------------------------------------------------------- */
