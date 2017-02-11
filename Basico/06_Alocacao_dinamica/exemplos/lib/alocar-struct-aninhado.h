#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct telefone {
  int ddd;
  char numero[50];
};

struct pessoa {
  char nome[50], endereco[50], cpf[50];
  struct telefone *tel;
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

PESSOA *alocar_pessoa(int qtd_pessoas, int qtd_tels) {
  int i;
  PESSOA *p = (PESSOA*) malloc(qtd_pessoas * sizeof(PESSOA));
  for(i=0; i<qtd_pessoas; i++){
    p[i].tel = (struct telefone*) malloc(qtd_tels * sizeof(struct telefone));
  }
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

char *getNome(PESSOA *p, int i) {
  return p[i].nome;
}

void setEndereco(PESSOA *p, char *endereco, int i) {
  strcpy(p[i].endereco, endereco);
}

char *getEndereco(PESSOA *p, int i) {
  return p[i].endereco;
}

void setCpf(PESSOA *p, char *cpf, int i) {
  strcpy(p[i].cpf, cpf);
}

char *getCpf(PESSOA *p, int i) {
  return p[i].cpf;
}

void setIdade(PESSOA *p, int idade, int i) {
  p[i].idade = idade;
}

int getIdade(PESSOA *p, int i) {
  return p[i].idade;
}

void setNumero(PESSOA *p, char *numero, int i, int j) {
  strcpy(p[i].tel[j].numero, numero);
}

char *getNumero(PESSOA *p, int i, int j) {
  return p[i].tel[j].numero;
}

void setDDD(PESSOA *p, int ddd, int i, int j) {
  p[i].tel[j].ddd = ddd;
}

int getDDD(PESSOA *p, int i, int j) {
  return p[i].tel[j].ddd;
}

void escrever_struct(PESSOA *p, int qtd_pessoas, int qtd_tels) {
  int i, j;
  for(i=0; i<qtd_pessoas; i++){
    printf("Insira o nome da %d° pessoa: ", i+1);
    fgets(getNome(p, i), 50, stdin);
    remover_quebra_de_linha(getNome(p, i));

    printf("Insira a idade da %d° pessoa: ", i+1);
    scanf("%d", &p[i].idade);
    flush_in();

    printf("Insira o endereço da %d° pessoa: ", i+1);
    fgets(getEndereco(p, i), 50, stdin);
    remover_quebra_de_linha(getEndereco(p, i));

    printf("Insira o cpf da %d° pessoa: ", i+1);
    fgets(getCpf(p, i), 50, stdin);
    remover_quebra_de_linha(getCpf(p, i));

    for(j=0; j<qtd_tels; j++){
      printf("Insira o %d° ddd da %d° pessoa: ", j+1, i+1);
      scanf("%d", &p[i].tel[j].ddd);
      flush_in();

      printf("Insira o %d° telefone da %d° pessoa: ", j+1, i+1);
      fgets(getNumero(p, i, j), 50, stdin);
      remover_quebra_de_linha(getNumero(p, i, j));
    }
  }
}

void imprimir_struct(PESSOA *p, int qtd_pessoas, int qtd_tels) {
  int i, j;
  for(i=0; i<qtd_pessoas; i++){
    printf("Nome      da %d° pessoa: %s\n",      i+1, getNome(p, i));
    printf("Idade     da %d° pessoa: %d anos\n", i+1, getIdade(p, i));
    printf("Endereço  da %d° pessoa: %s\n",      i+1, getEndereco(p, i));
    printf("CPF       da %d° pessoa: %s\n",    i+1, getCpf(p, i));
    for(j=0; j<qtd_tels; j++){
      printf("DDD  do %d° telefone da %d° pessoa: %d\n", j+1, i+1, getDDD(p, i, j));
      printf("Numero do %d° telefone da %d° pessoa: %s\n",  j+1, i+1, getNumero(p, i, j));
    }
    printf("\n");
  }
}
