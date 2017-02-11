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

PESSOA *alocar_vetor_struct(int qtd) {
  PESSOA *p = (PESSOA*) malloc(qtd * sizeof(PESSOA));
  if(p == NULL)
    printf("Memória insuficiente!\n");
  return p;
}

void liberar_memoria(PESSOA *p) {
  free(p);
}

void setNome(PESSOA *p, char *nome, int i) {
  strcpy(p[i].nome, nome);
}

void setEndereco(PESSOA *p, char *endereco, int i) {
  strcpy(p[i].endereco, endereco);
}

void setCpf(PESSOA *p, char *cpf, int i) {
  strcpy(p[i].cpf, cpf);
}

void setIdade(PESSOA *p, int idade, int i) {
  p[i].idade = idade;
}

char *getNome(PESSOA *p, int i) {
  return p[i].nome;
}

char *getEndereco(PESSOA *p, int i) {
  return p[i].endereco;
}

char *getCpf(PESSOA *p, int i) {
  return p[i].cpf;
}

int getIdade(PESSOA *p, int i) {
  return p[i].idade;
}

void escrever_struct(PESSOA *p, int qtd) {
  int i;
  for(i=0; i<qtd; i++){
    printf("Insira o nome da %d° pessoa: ", i+1);
    fgets(p[i].nome, 50, stdin);
    remover_quebra_de_linha(p[i].nome);

    printf("Insira a idade da %d° pessoa: ", i+1);
    scanf("%d", &p[i].idade);
    remover_quebra_de_linha(p[i].nome);
    flush_in();

    printf("Insira o endereço da %d° pessoa: ", i+1);
    fgets(p[i].endereco, 50, stdin);
    remover_quebra_de_linha(p[i].endereco);

    printf("Insira o cpf da %d° pessoa: ", i+1);
    fgets(p[i].cpf, 50, stdin);
    remover_quebra_de_linha(p[i].cpf);
  }
}

void imprimir_struct(PESSOA *p, int qtd) {
  int i;
  for(i=0; i<qtd; i++){
    printf("Nome      da %d° pessoa: %s\n",      i+1, p[i].nome);
    printf("Idade     da %d° pessoa: %d anos\n", i+1, p[i].idade);
    printf("Endereço  da %d° pessoa: %s\n",      i+1, p[i].endereco);
    printf("CPF       da %d° pessoa: %s\n\n",    i+1, p[i].cpf);
  }
}
