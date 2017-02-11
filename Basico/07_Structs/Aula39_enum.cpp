#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum semana {Domingo=1, Segunda, Terca, Quarta, Quinta, Sexta, Sabado};

enum escapes {retrocesso='\b', tabulacao='\t', novalinha='\n'};


int main() {

	enum semana s1, s2;
	enum escapes e = novalinha; 

	s1 = Segunda;
	s2 = Terca;

	printf("Domingo = %d\n", Domingo);
	printf("s1 = %d\n", s1);
	printf("s2 = %d\n", s2);

	if(s2 == Terca)
		printf("s3 é Terça%c", e);
	else
		printf("s3 não é Terça%c", e);



	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

	DEFINIÇÃO:

		- As Enumerações, são um tipo definido pelo usuario, utilizando se de uma lista de identificadores. 
		Os indentificadores desta lista, se assemelham a constantes.

	DECLARAÇÃO:

			enum NomeDaEnum {Lista de identificadores};

	EXEMPLO:

			enum Meses{Janeiro = 1,Fevereiro,Marco,Abril,Maio,Junho,Julho,Agosto,Setembro,Outubro,Novembro,Dezembro};

		- No exemplo acima foi definido uma enumeração de meses, onde Janeiro se torna um indentificador 
		com valor 1 e os indentificadores seguintes tendo seu valor acrescentado em 1 sucessivamente 
		até o fim da lista. Assim temos os 12 meses do ano, como indentificadores de valor entre 1~12.

--------------------------------------------------------------------------------------- */