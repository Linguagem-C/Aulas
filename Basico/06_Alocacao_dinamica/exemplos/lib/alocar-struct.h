#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct pessoa {
  char nome[50], endereco[50], cpf[50];
  int idade;
};

typedef struct pessoa PESSOA;

/* Limpa o buffer do teclado */
void flush_in(){
    int ch;
    do{
        ch = fgetc(stdin);
    }while (ch != EOF && ch != '\n');
}

/* remove '\n' e atualiza o tamanho */
void remover_quebra_de_linha(char *string) {
  size_t size;
  size = strlen(string);
  if (string[size - 1] == '\n'){
    string[--size] = 0;
  }
}

PESSOA *alocar_struct() {
  PESSOA *p = (PESSOA*) malloc(sizeof(PESSOA));
  if(p == NULL)
    printf("Memória insuficiente!\n");
  return p;
}

void liberar_memoria(PESSOA *p) {
  free(p);
}

void contrutor(PESSOA *p, char *nome, int idade, char *endereco, char *cpf) {
  strcpy(p->nome, nome);
  strcpy(p->endereco, endereco);
  strcpy(p->cpf, cpf);
  p->idade = idade;
}

void imprimir_struct(PESSOA *p) {
  printf("Nome: %s\n", p->nome);
  printf("Idade: %d anos\n", p->idade);
  printf("Endereço: %s\n", p->endereco);
  printf("CPF: %s\n", p->cpf);
}

void setNome(PESSOA *p, char *nome) {
  strcpy(p->nome, nome);
}

void setEndereco(PESSOA *p, char *endereco) {
  strcpy(p->endereco, endereco);
}

void setCpf(PESSOA *p, char *cpf) {
  strcpy(p->cpf, cpf);
}

void setIdade(PESSOA *p, int idade) {
  p->idade = idade;
}

char *getNome(PESSOA *p) {
  return p->nome;
}

char *getEndereco(PESSOA *p) {
  return p->endereco;
}

char *getCpf(PESSOA *p) {
  return p->cpf;
}

int getIdade(PESSOA *p) {
  return p->idade;
}

void escrever_struct(PESSOA *p) {
  printf("Insira o nome da pessoa: ");
  fgets(p->nome, 50, stdin);
  remover_quebra_de_linha(p->nome);

  printf("Insira a idade da pessoa: ");
  scanf("%d", &p->idade);
  remover_quebra_de_linha(p->nome);
  flush_in();

  printf("Insira o endereço da pessoa: ");
  fgets(p->endereco, 50, stdin);
  remover_quebra_de_linha(p->endereco);

  printf("Insira o cpf da pessoa: ");
  fgets(p->cpf, 50, stdin);
  remover_quebra_de_linha(p->cpf);
}
