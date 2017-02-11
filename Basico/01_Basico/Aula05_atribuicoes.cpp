#include <stdio.h>
#include <stdlib.h>

int main() {

	int x = 5, y, z;

	y = 10;
	x = x + 1;
	x = y;

	x = y = z = 10;

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

ATRIBUIÇÕES:
	- Variavel = Expressão;

	- Perceba que a atribuição é sempre da direita para a esquerda

	- A varivável que irá receber a expressão tem sempre que esta do lado esquerdo

	- No caso de int = char vai está relacionado com a tabela ASCII e char = int 
	também se a expressão for algo entre (-127 e 128)

	- É possivel também no caso de int e float nesse caso o de int = float vai
	perder a casa decimal, caso float = int vai permanecer da msm forma, 
	pois o conjunto dos interios está dentro dos números reais

- Se for o caso de char = float e float = char vai cair no msm caso do char = int 
e int = char


EXPRESSÕES:
	- Pode ser um número -> x = 10;
	- Pode ser uma conta -> x = 10/5;
	- Pode ser uma outra váriavel -> x = y;
	- Poder ser atribuições multiplas -> x = y = z = 10


-----------------------------------------------------------------------------*/