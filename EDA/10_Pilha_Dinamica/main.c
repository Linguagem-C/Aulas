#include "pilha.h"

int main() {

	PILHA *pilha;
  LIVRARIA livro;
	int opcao;
	char sair;

  pilha = criar_pilha();

	while(1){
		system("clear");
		opcao = abertura();
		menu(opcao, pilha, livro);
		printf("deseja voltar ao menu?(s/n): ");
		scanf(" %c", &sair);
		sair = toupper(sair);
		if(sair == 'N'){
			printf("partiu!!...\n");
			break;
		}
	}

  liberar_pilha(pilha);
	return 0;
}

