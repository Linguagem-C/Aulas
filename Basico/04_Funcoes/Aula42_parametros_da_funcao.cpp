#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float raiz(float r);
int soma(int x, int y);
float leitura();

int main() {

	float k, w = 5.4;
	int x, y=1, z=2;

	k = raiz(w);
	k = raiz(5.4);
	k = leitura();
	//k = raiz(); ERRO, nenhum argumentos
	//k = raiz(w, 5.4); ERRO, muitos argumentos

	x = soma(y,z);
	x = soma(1,2);
	x = soma(y,2);


	return 0;
}

float raiz(float r){
	return 0;
}

int soma(int x, int y){
	return 0;
}

float leitura(){
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

	DEFINIÇÃO:

		- Permite ao programador passar uma informação ou trecho de código para dentro da função

	EXEMPLOS:

			float raiz(float r);
			float exp(float a, int b);
			int soma(int x, int y);
			int soma(int x , y); //ERRADO

	OBSERVAÇÕES:

		- Podemos declarar funções sem parametros, basta deixar a lista de parametros vazia ou passar
		a palavra reservada void

			float leitura();
			int le_arquivo(void);

	
---------------------------------------------------------------------------------------- */