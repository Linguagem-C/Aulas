#include <stdio.h>

int main(){

	FILE *f = fopen("doc/file.txt", "r");
	char caracter;
	int linha=1, linha_de_pesquisa;

	printf("Insira a linha que deseja pegar: ");
	scanf("%d", &linha_de_pesquisa);

	caracter = fgetc(f);
	while(caracter != EOF) {
		if(linha == linha_de_pesquisa && caracter != '\n') {
			printf("%c",caracter);
		}
		if(caracter == '\n'){
			linha++;
		}
	caracter = fgetc(f);
}
printf("\n");
if(linha < linha_de_pesquisa){
	printf("Não existe linha %d no seu arquivo", linha_de_pesquisa);
}

}
