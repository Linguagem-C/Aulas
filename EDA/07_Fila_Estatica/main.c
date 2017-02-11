#include "fila.h"

int main() {

	FILA *fila;
  ALUNO aluno;
	int opcao;
	char sair;

  fila = criar_fila();

	while(1){
		system("clear");
		opcao = abertura();
		menu(opcao, fila, aluno);
		printf("deseja voltar ao menu?(s/n): ");
		scanf(" %c", &sair);
		sair = toupper(sair);
		if(sair == 'N'){
			printf("partiu!!...\n");
			break;
		}
	}

  liberar_fila(fila);
	return 0;
}

