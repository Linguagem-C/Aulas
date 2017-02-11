#include "lib/biblioteca.h"

int abertura() {
  int opcao;
  system("clear");
  printf("*******************************\n");
  printf("********* BEM VINDO! **********\n");
  printf("*******************************\n");
  printf("Escolha uma das opções para o cadastro de alunos:\n");
  printf("1) Adicionar matricula\n");
  printf("2) Remover matricula\n");
  printf("3) Buscar matricula\n");
  printf("4) Mostrar lista de matriculas\n");
  printf("5) Sair\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 5)
      break;
  }

  return opcao;
}

int adicionar_matricula(){
  int opcao;
  system("clear");
  printf("Você escolheu a opção de adicionar matricula\n");
  printf("Como você deseja adicionar a matricula?\n");
  printf("1) No final da lista\n");
  printf("2) No inicio da lista\n");
  printf("3) Em ordem de matricula\n");
  printf("4) Na posição desejada\n");
  printf("5) Voltar\n");

  while(1){
    printf("Insira a opção: ");
    scanf("%d", &opcao);

    if(opcao <= 5)
      break;
  }

  return opcao;

}

int remover_matricula(){
  int opcao;
  system("clear");
  printf("Você escolheu a opção de remover matricula\n");
  printf("Como você deseja remover a matricula?\n");
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

void menu(int opcao_abertura, LISTA *list, ALUNO fulano) {
  int opcao, posicao;
  struct aluno busca;
  system("clear");
  switch(opcao_abertura){
    case 1:
      opcao = adicionar_matricula();
      if(opcao == 1)
        inserir_final_da_lista(list, fulano);
      else if(opcao == 2)
        inserir_inicio_da_lista(list, fulano);
      else if(opcao == 3)
        inserir_lista_ordenada(list, fulano);
      else if(opcao == 4){
        printf("Insira a posição na qual quer inserir o aluno: ");
        scanf("%d", &posicao);
        inserir_na_lista(list, fulano, posicao);
      }else if(opcao == 5){
        opcao = abertura();
        menu(opcao, list, fulano);
      }
      break;

    case 2:
      opcao = remover_matricula();
      if(opcao == 1)
        remover_final_da_lista(list);
      else if(opcao == 2)
        remover_inicio_da_lista(list);
      else if(opcao == 3){
        printf("Insira a matricula que deseja remover: ");
        scanf("%d", &fulano.matricula);
        remover_da_lista(list, fulano.matricula);
      }else if(opcao == 4){
        opcao = abertura();
        menu(opcao, list, fulano);
      }
      break;

    case 3:
      opcao = buscar_aluno();
      if(opcao == 1){
        printf("Insira a posição na qual quer buscar o aluno: ");
        scanf("%d", &posicao);
        buscar_lista_posicao(list, posicao, &busca);
        printf("A matricula do aluno é %d está na %d posição da lista\n", busca.matricula, posicao);
      }else if(opcao == 2){
        printf("Insira a matricula que deseja remover: ");
        scanf("%d", &fulano.matricula);
        posicao = buscar_lista_conteudo(list, fulano.matricula, &busca);
        printf("O aluno de matricula %d está na %d posição da lista \n", busca.matricula, posicao);
      }else if(opcao == 3){
        opcao = abertura();
        menu(opcao, list, fulano);
      }
      break;

    case 4:
      if(tamanho_lista(list) == 1)
        printf("A lista tem %d matricula\n", tamanho_lista(list));
      else if(tamanho_lista(list) > 1)
        printf("A lista tem %d matriculas\n", tamanho_lista(list));
      mostrar_lista(list);
      break;

    case 5:
      printf("Partiu!! ...\n");
      exit(0);
      break;
  }
}
