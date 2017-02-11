#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union tipoU {
	//Total = 16 bits = 2 bytes
	short int x; //16 bits = 2 bytes (MAIOR)
	unsigned char c; //8 bits = 1 byte
};

struct tipoS {
	//Total = 24 bits = 3 bytes
	short int x; //16 bits = 2 bytes
	unsigned char c; //8 bits = 1 byte
};

int main() {

	//Declaração de uma variável struct
	struct tipoS s;

	s.x = 5;
	s.c = 'a';

	printf("x = %d\n", s.x);
	printf("c = %c\n", s.c);

	//Declaração de uma variável union
	// Só pode acessar uma variavel por vez.
	union tipoU u;	
	
	u.x = 5;
	//u.c = 'a';

	printf("x = %d\n", u.x);
	//printf("c = %c\n", u.c);

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

	- unsigned = sem sinal ou +

	UNION:

		- A linguagem C nós permite criar nosso próprio tipo de variável

		- Além da struct podemos criar uma union, também chamada de união

		- Forma Geral:

			union nomeDaUnion {
				tipo1 nome1;
				tipo2 nome2;
				.
				.
				.
				tipoN nomeN;
			};

		- Para acessar a union e igual ao acesso a struct, através do ponto.

	STRUCT VS UNION:

		- Struct: espaço para armazenar todos os seu elementos

		- Union: espaço para armazenar apenas o maior elemento,
		memória compartilhada.

		- Na union as variáveis menores vão ser guardadas dentro da 
		memória da variavel maior.

		- Na union como a memória é compartilhada eu não posso acessar
		os dois elementos ao mesmo tempo, já que um sobrescreve o outro

		- Crie uma union quando todas as variaveis não precisam ser usadas
		ao mesmo tempo e crie uma struct caso contrario

--------------------------------------------------------------------------- */