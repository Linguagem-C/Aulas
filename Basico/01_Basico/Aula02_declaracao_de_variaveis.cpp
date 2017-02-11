#include <stdio.h>
#include <stdlib.h>

int main() {

	char letra = 'a';
	char ascii = 10;
	int numero = 10;
	float pi = 13.1415;
	double numeroReal = 10.2563498435743759847358743957938475834957439574389;
	double mol = 6.0e23;

	int num1, num2, num3;
	num1 = 10;
	num2 = 20;
	num3 = 30;

	return 0;
}

/* ----------------------- RESUMO DO CÓDIGO -----------------------------------

L7: É equivalenta a um caractere da Tabela ASCII (-127 a 128)
L9: Ponto separa as casas decimais do valor e não a virgula
L11: É equivale a base 10, 5.0x10^3


TIPOS DE VARIÁVEIS:
	- char = guarda um caractere do teclado
	- int = guarda valores inteiros
	- float = guarda valores reais
	- double = guarda valores reais de precisão dupla, valores muito grandes

NOME DAS VARIÁVEIS:
	- letras maiusculas -> int variavel
	- letras maiusculas -> float Variavel
	- undescore -> _variavel
	- Não se usa números no começo da variavel -> 1Variavel
	- Não se usa acentuação -> Variável
	- Não se usa caracteres especiais -> Variavel!
	- Não se usa palavras reservadas da linguagem C -> int, if, else, case ...
	- Case Sensitive -> Maiusculo e minusculo são coisas distintas

ATRIBUIÇÃO vs COMPARAÇÃO:
	- Atribuição é quando atribuimos um valor a uma variavel -> char letra = 'a'
	- Comparação é quando comparamos a variavel com algo -> int numero == 10, 
	normalmente usado com o if/else


-----------------------------------------------------------------------------*/
