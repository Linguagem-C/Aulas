#include "lista.h"

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
  printf("1) No final da lista\n");
  printf("2) No inicio da lista\n");
  printf("3) Em ordem de matricula\n");
  printf("4) Voltar\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 5)
      break;
  }

  return opcao;

}

int remover_aluno(){
  int opcao;
  system("clear");
  printf("Você escolheu a opção de remover aluno\n");
  printf("Como você deseja remover o aluno?\n");
  printf("1) No final da lista\n");
  printf("2) No inicio da lista\n");
  printf("3) Pela matricula\n");
  printf("4) Voltar\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 4)
      break;
  }

  return opcao;

}

int buscar_aluno(){
  int opcao;
  system("clear");
  printf("Você escolheu a opção de buscar aluno\n");
  printf("Como você deseja buscar o aluno?\n");
  printf("1) Pela posição na lista\n");
  printf("2) Pela matricula do aluno\n");
  printf("3) Voltar\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 3)
      break;
  }

  return opcao;

}

void menu(int opcao_abertura, LISTA *lista, ALUNO aluno) {
  int opcao, posicao;
  ALUNO busca;
  system("clear");
  switch(opcao_abertura){
    case 1:
      opcao = adicionar_aluno();
      if(opcao == 1){
        inserir_dados_aluno(&aluno);
        inserir_final_da_lista(lista, aluno);
      }else if(opcao == 2){
        inserir_dados_aluno(&aluno);
        inserir_inicio_da_lista(lista, aluno);
      }else if(opcao == 3){
        inserir_dados_aluno(&aluno);
        inserir_lista_ordenada(lista, aluno);
      }else if(opcao == 4){
        opcao = abertura();
        menu(opcao, lista, aluno);
      }
      break;

    case 2:
      opcao = remover_aluno();
      if(opcao == 1)
        remover_final_da_lista(lista);
      else if(opcao == 2)
        remover_inicio_da_lista(lista);
      else if(opcao == 3){
        printf("Insira a matricula que deseja remover: ");
        scanf("%d", &aluno.matricula);
        remover_da_lista(lista, aluno.matricula);
      }else if(opcao == 4){
        opcao = abertura();
        menu(opcao, lista, aluno);
      }
      break;

    case 3:
      opcao = buscar_aluno();
      if(opcao == 1){
        printf("Insira a posição na qual quer buscar o aluno: ");
        scanf("%d", &posicao);
        buscar_lista_posicao(lista, posicao, &busca);
        printf("A matricula do aluno é %d está na %d posição da lista\n", busca.matricula, posicao);
      }else if(opcao == 2){
        printf("Insira a matricula que deseja remover: ");
        scanf("%d", &busca.matricula);
        posicao = buscar_lista_matricula(lista, busca.matricula, &busca);
        printf("O aluno de matricula %d está na %d posição da lista \n", busca.matricula, posicao);
      }else if(opcao == 3){
        opcao = abertura();
        menu(opcao, lista, aluno);
      }
      break;

    case 4:
      if(tamanho_lista(lista) == 1) {
        printf("A lista tem %d matricula\n", tamanho_lista(lista));
      }else if(tamanho_lista(lista) > 1) {
        printf("A lista tem %d matriculas\n", tamanho_lista(lista));
      }
      mostrar_lista(lista);
      break;

    case 5:
      printf("Partiu!! ...\n");
      exit(0);
      break;
  }
}
