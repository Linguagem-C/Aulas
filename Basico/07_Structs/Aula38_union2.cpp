#include <stdio.h>
#include <stdlib.h>
#include <string.h>

union tipo {
	short int x; //16 bits
	unsigned char c[2]; //16 bits -> 8+8
};

int main() {

//------------- ECONOMIA DE MEMÓRIA -------------------
	printf("---------------\n");
		union tipo v;

		v.x = 1545;
		printf("x = %d\n", v.x);

		v.c[0] = 'a';
		v.c[1] = 'b';

		printf("c[0] = %c\n", v.c[0]);
		printf("c[1] = %c\n", v.c[1]);
//-----------------------------------------------------

//---------- MANIPULAÇÃO DE BITS SEM UNION ------------
	printf("--------------\n");
		//quebra os bits em 2		 c1       c0
		short int x = 1545; //00000110 00001001
		unsigned char c0, c1;

		//0x -> número hexadecimal
		//00 -> eliminar a primeira parte = 00000110
		//FF -> deixar a segunda parte = 00001001
		c0 = 0x00FF & x; //00001001 -> 9

		//Deslocamento de 8 bits a direita
		c1 = x >> 8; //00000110 -> 6

		printf("x = %d\n", x);
		printf("c0 = %d\n", c0);
		printf("c1 = %d\n", c1);

//-----------------------------------------------------

//---------- MANIPULAÇÃO DE BITS COM UNION ------------
	printf("---------------\n");

		union tipo t;

		t.x = 1545; //00000110 00001001

		printf("x = %d\n", t.x); //00000110 00001001 = 1545

		printf("c[0] = %d\n", t.c[0]); //00001001 = 9

		printf("c[1] = %d\n", t.c[1]); //00000110 = 6

//-----------------------------------------------------



	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

PORQUE USAR UNION:

	- Economia de memória: Se os seus campos nunca são usados ao mesmo tempo,
	não faz sentido reservar espaços para ambos

	- Manipulação de bits: Uma union permite fazer acessos controlados a
	níveis de bits.

	 _______X________
	|__C0___|___C1___|

------------------------------------------------------------------------------ */