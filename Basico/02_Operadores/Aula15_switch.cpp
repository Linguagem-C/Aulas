#include <stdio.h>
#include <stdlib.h>

int main() {

	char simbolo;

	printf("Digite um simbolo de pontuação: ");
	scanf("%c", &simbolo);

	switch(simbolo) {
		case '.':
			printf("Ponto.\n");
			break;
		case ',':
			printf("Virgula,\n");
			break;
		case ':':
			printf("Dois pontos:\n");
			break;
		case ';':
			printf("Ponto e virgula;\n");
			break;
		default:
			printf("Não é pontuação!\n");
	}

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

SWITCH:
	- Permite fazer seleções multiplas com base no valor de uma variavel
	do tipo int ou char

	Forma geral:
	switch(variavel) {
		case valor1:
			//conjunto de comandos;
			break;
		case valor2:
			//conjunto de comandos;
			break;
		case valor3:
			//conjunto de comandos;
			break;
		.
		.
		.
		case valor n:
			//conjunto de comandos;
			break;
		default:
			//conjunto de comandos;
	}

	valor = São os possiveis valores que minha variavel <variavel> pode ter
	default = Se não tiver o valor que foi estipulado pela variavel cai no default
	break = Vai impedir que os outros cases seja executado
	Poderiamos fazer a msm coisa com if-else

-----------------------------------------------------------------------------*/