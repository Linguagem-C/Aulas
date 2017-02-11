#include "lib/biblioteca.h"

int main() {
	float distancia;
	Ponto *p, *q;
	/* Ponto r; quero que de ERRO */

	p = criar_ponto(10, 21);
	q = criar_ponto(7, 25);

	/*q->x = 2; quero que de ERRO */
	
	distancia = distancia_pontos(p, q);
	printf("A distancia entre dois pontos p e q: %.2f\n", distancia);

	liberar_ponto(p);
	liberar_ponto(q);
	

	return 0;
}

/* Compilar esse código junto com o da aula02 e utilizar a tag -lm */

/* -------------------------------- RESUMO DO CÓDIGO ------------------------------

	CONVENÇÃO:

		- A convenção em linguagem C é preparar dois arquivos para implementar um TAD

		- TAD é a mesma coisa de CRUD = Create, Read, Update e Delete

		- Arquivo ".h": prótotipo das funções, tipos de ponteiros e dados globalmente
		acessiveis

		- Arquivos ".c": Declaração do tipo de dados e implementação da suas funções.

		- Assim separamos o conceito (definição do tipo) de sua implementação.

	ERROS:

		- Agora não se pode acessar o valor da struct a não ser pelas funções, por
		exemplo:

			> Não pode fazer, da erro:

				Ponto p;
				q->x = 2;


---------------------------------------------------------------------------------- */