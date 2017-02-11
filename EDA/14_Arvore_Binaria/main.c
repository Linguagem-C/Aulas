#include "lib/arvoreBinaria.h"
int main() {

  // Ponteiro para ponteiro da struct elemento *LISTA
	ARVORE *raiz;
  ALUNO aluno;
	int opcao;
	char sair;

  raiz = criar_arvore_binaria();

	while(1){
		system("clear");
		opcao = abertura();
		menu(opcao, raiz, aluno);
		printf("deseja voltar ao menu?(s/n): ");
		scanf(" %c", &sair);
		sair = toupper(sair);
		if(sair == 'N'){
			printf("partiu!!...\n");
			break;
		}
	}

  liberar_arvore_binaria(raiz);
	return 0;
}

