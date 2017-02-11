#include "fila.h"

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
  limpar_buffer();
  fgets(aluno->nome, 30, stdin);
  remover_quebra_de_linha(aluno->nome);
  printf("insira as notas do aluno: ");
  scanf("%f %f %f", &aluno->P1, &aluno->P2, &aluno->P3);
  printf("Matricula: %d, Nome: %s, P1: %.2f, P2: %.2f, P3: %.2f\n", aluno->matricula, aluno->nome, aluno->P1, aluno->P2, aluno->P3);
}

int abertura() {
  int opcao;
  system("clear");
  printf("*******************************\n");
  printf("********* BEM VINDO! **********\n");
  printf("*******************************\n");
  printf("Escolha uma das opções abaixo:\n");
  printf("1) Entrar na fila\n");
  printf("2) Sair da fila\n");
  printf("3) Atendimento\n");
  printf("4) Tamanho da fila\n");
  printf("5) Sair\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 5)
      break;
  }

  return opcao;
}

void menu(int opcao_abertura, FILA *fila, ALUNO aluno) {
  system("clear");
  switch(opcao_abertura){
    case 1:
      inserir_dados_aluno(&aluno);
      entrar_na_fila(fila, aluno);
      printf("Aluno %s acabou de entrar na fila!\n", aluno.nome);
      break;

    case 2:
      printf("Em contrução!\n");
      break;

    case 3:
      if(fila_vazia(fila)) {
        printf("Não há alunos na fila\n");
        break;
      }
      consultar_fila(fila, &aluno);
      printf("Aluno %s de matricula %d esta sendo atendido!\n", aluno.nome, aluno.matricula);
      sair_da_fila(fila);
      printf("Aluno já foi atendido e saiu da fila\n");
      break;

    case 4:
      if(tamanho_da_fila(fila) == 0) {
        printf("A fila tem %d alunos\n", tamanho_da_fila(fila));
      }else if(tamanho_da_fila(fila) > 0) {
        printf("A lista tem %d alunos\n", tamanho_da_fila(fila));
      }
      //mostrar_fila(fila);
      break;

    case 5:
      printf("Saindo...!! ...\n");
      exit(0);
      break;
  }
}
