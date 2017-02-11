#include "pilha.h"

void remover_quebra_de_linha(char *string) {
  size_t size;
  size = strlen(string);
  if (string[size - 1] == '\n'){
    string[--size] = 0;
  }
}

void limpar_buffer(){
    int ch;
    do{
        ch = fgetc(stdin);
    }while (ch != EOF && ch != '\n');
}

void inserir_dados_livro(LIVRARIA *livro) {
  printf("Insira o codigo do livro: ");
  scanf("%d", &livro->codigo);
  printf("Insira o titulo do livro: ");
  limpar_buffer();
  fgets(livro->titulo, 50, stdin);
  remover_quebra_de_linha(livro->titulo);
  printf("Código: %d, Titulo: %s\n", livro->codigo, livro->titulo);
}

int abertura() {
  int opcao;
  system("clear");
  printf("*******************************\n");
  printf("********* BEM VINDO! **********\n");
  printf("*******************************\n");
  printf("Escolha uma das opções abaixo:\n");
  printf("1) Empilhar livro\n");
  printf("2) Desempilhar livro\n");
  printf("3) Consultar livro\n");
  printf("4) Tamanho da pilha de livros\n");
  printf("5) Sair\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 5)
      break;
  }

  return opcao;
}

void menu(int opcao_abertura, PILHA *pilha, LIVRARIA livro) {
  system("clear");
  switch(opcao_abertura){
    case 1:
      inserir_dados_livro(&livro);
      entrar_na_pilha(pilha, livro);
      printf("Livro '%s' acabou de entrar na pilha de livros!\n", livro.titulo);
      break;

    case 2:
      printf("Primeiro Livro da pilha acabou de sair da pilha de livros!\n");
      sair_da_pilha(pilha);
      break;

    case 3:
      if(pilha_vazia(pilha)) {
        printf("Não há livros na pilha\n");
        break;
      }
      consultar_pilha(pilha, &livro);
      printf("Livro '%s' de código [%d] esta sendo retirado da pilha para consulta!\n", livro.titulo, livro.codigo);
      sair_da_pilha(pilha);
      printf("Livro retirado da pilha\n");
      break;

    case 4:
      if(tamanho_da_pilha(pilha) == 0) {
        printf("A pilha tem %d livros\n", tamanho_da_pilha(pilha));
      }else if(tamanho_da_pilha(pilha) > 0) {
        printf("A pilha tem %d livros\n", tamanho_da_pilha(pilha));
      }
      //mostrar_pilha(pilha);
      break;

    case 5:
      printf("Saindo...!! ...\n");
      exit(0);
      break;
  }
}
