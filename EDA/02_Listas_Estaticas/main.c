#include "lib/biblioteca.h"

int main() {

	lista *list;
	struct aluno fulano;
	int opcao;
	char sair;

	list = criar_lista();

	while(1){
		system("clear");
		opcao = abertura();
		menu(opcao, list, fulano);
		printf("deseja voltar ao menu?(s/n): ");
		scanf(" %c", &sair);
		sair = toupper(sair);
		if(sair == 'N'){
			printf("partiu!!...\n");
			break;
		}
	}

	liberar_lista(list);
	return 0;
}

