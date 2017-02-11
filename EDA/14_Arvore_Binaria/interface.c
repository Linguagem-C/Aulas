#include "lib/arvoreBinaria.h"

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

void inserir_dados_aluno(ALUNO *aluno) {
  printf("Insira a matricula do aluno: ");
  scanf("%d", &aluno->matricula);
  printf("Insira o nome do aluno: ");
  fgets(aluno->nome, 30, stdin);
  limpar_buffer();
  remover_quebra_de_linha(aluno->nome);
  printf("insira as notas do aluno: ");
  scanf("%f %f %f", &aluno->nota1, &aluno->nota2, &aluno->nota3);
  printf("Matricula: %d, Nome: %s, P1: %.2f, P2: %.2f, P3: %.2f\n", aluno->matricula, aluno->nome, aluno->nota1, aluno->nota2, aluno->nota3);
}

int abertura() {
  int opcao;
  system("clear");
  printf("*******************************\n");
  printf("********* BEM VINDO! **********\n");
  printf("*******************************\n");
  printf("Escolha uma das opções para o cadastro de alunos:\n");
  printf("1) Adicionar aluno\n");
  printf("2) Remover aluno\n");
  printf("3) Buscar aluno\n");
  printf("4) Mostrar lista de alunos\n");
  printf("5) Sair\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 5)
      break;
  }

  return opcao;
}

int adicionar_aluno(){
  int opcao;
  system("clear");
  printf("Você escolheu a opção de adicionar aluno\n");
  printf("Como você deseja adicionar o aluno?\n");
  printf("1) Adicionar aluno pela matricula\n");
  printf("2) Adicionar aluno pelo nome\n");
  printf("3) Voltar\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 3)
      break;
  }

  return opcao;

}

int remover_aluno(){
  int opcao;
  system("clear");
  printf("Você escolheu a opção de remover aluno\n");
  printf("Como você deseja remover o aluno?\n");
  printf("1) Remover aluno pela matricula\n");
  printf("2) Remover aluno pelo nome\n");
  printf("3) Voltar\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 3)
      break;
  }

  return opcao;

}

int buscar_aluno(){
  int opcao;
  system("clear");
  printf("Você escolheu a opção de buscar aluno\n");
  printf("Como você deseja buscar o aluno?\n");
  printf("1) Buscar aluno pela matricula\n");
  printf("2) Buscar aluno pelo nome\n");
  printf("3) Voltar\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 3)
      break;
  }

  return opcao;

}

void menu(int opcao_abertura, ARVORE *raiz, ALUNO aluno) {
  int pesquisa;
  system("clear");
  switch(opcao_abertura){
    case 1:
      inserir_dados_aluno(&aluno);
      inserir_no(raiz, aluno.matricula);
      break;

    case 2:
      printf("Insira a matricula que deseja remover da arvore: ");
      scanf("%d", &pesquisa);
      remover_no(raiz, pesquisa);
      break;

    case 3:
      printf("Mostrar arvore em ordem crescente\n");
      percorrer_arvore_em_ordem(raiz);

      break;

    case 4:
      printf("A altura da arvore é %d\n", altura_da_arvore(raiz));
      printf("O total de nós da arvore é %d\n", total_de_nos(raiz));
      break;

    case 5:
      printf("Partiu!! ...\n");
      exit(0);
      break;
  }
}
