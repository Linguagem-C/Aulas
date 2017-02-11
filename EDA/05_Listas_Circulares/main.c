#include "lista.h"

int main() {

	LISTA *lista;
  ALUNO aluno;
	int opcao;
	char sair;

  lista = criar_lista();

	while(1){
		system("clear");
		opcao = abertura();
		menu(opcao, lista, aluno);
		printf("deseja voltar ao menu?(s/n): ");
		scanf(" %c", &sair);
		sair = toupper(sair);
		if(sair == 'N'){
			printf("partiu!!...\n");
			break;
		}
	}

  liberar_lista(lista);
	return 0;
}

