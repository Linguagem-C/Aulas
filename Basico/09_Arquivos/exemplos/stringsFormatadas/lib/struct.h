#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAM 50
#define MAX 5

struct telefone {
  int ddd;
  char numero[TAM];
};

struct endereco {
  char cidade[TAM];
  char bairro[TAM];
  char complemento[TAM];
};

struct pessoa {
  char nome[TAM], cpf[TAM];
  struct telefone tel[MAX];
  struct endereco address;
  int idade, qtd_tels;
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

PESSOA *alocar_pessoa(int qtd_pessoas) {
  PESSOA *p = (PESSOA*) malloc(qtd_pessoas * sizeof(PESSOA));
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

void setCidade(PESSOA *p, char *cidade, int i) {
  strcpy(p[i].address.cidade, cidade);
}

char *getCidade(PESSOA *p, int i) {
  return p[i].address.cidade;
}

void setBairro(PESSOA *p, char *bairro, int i) {
  strcpy(p[i].address.bairro, bairro);
}

char *getBairro(PESSOA *p, int i) {
  return p[i].address.bairro;
}

void setComplemento(PESSOA *p, char *complemento, int i) {
  strcpy(p[i].address.complemento, complemento);
}

char *getComplemento(PESSOA *p, int i) {
  return p[i].address.complemento;
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

void setQtdTelefones(PESSOA *p, int qtd_tels, int i) {
  p[i].qtd_tels = qtd_tels;
}

int getQtdTelefones(PESSOA *p, int i) {
  return p[i].qtd_tels;
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

void preencher_struct(PESSOA *p, int qtd_pessoas) {
  int i, j;
  for(i=0; i<qtd_pessoas; i++){
    printf("Insira o nome da %d° pessoa: ", i+1);
    fgets(getNome(p, i), 50, stdin);
    remover_quebra_de_linha(getNome(p, i));

    printf("Insira a idade da %d° pessoa: ", i+1);
    scanf("%d", &p[i].idade);
    flush_in();

    printf("Insira o cpf da %d° pessoa: ", i+1);
    fgets(getCpf(p, i), 50, stdin);
    remover_quebra_de_linha(getCpf(p, i));

    printf("Insira o cidade da %d° pessoa: ", i+1);
    fgets(getCidade(p, i), 50, stdin);
    remover_quebra_de_linha(getCidade(p, i));

    printf("Insira o bairro da %d° pessoa: ", i+1);
    fgets(getBairro(p, i), 50, stdin);
    remover_quebra_de_linha(getBairro(p, i));

    printf("Insira o complemento do endereço da %d° pessoa: ", i+1);
    fgets(getComplemento(p, i), 50, stdin);
    remover_quebra_de_linha(getComplemento(p, i));

    printf("Insira a quantidade de telefones da %d° pessoa: ", i+1);
    scanf("%d", &p[i].qtd_tels);

    if(getQtdTelefones(p, i) > 0) {
      for(j=0; j<getQtdTelefones(p, i); j++){
        printf("Insira o %d° ddd da %d° pessoa: ", j+1, i+1);
        scanf("%d", &p[i].tel[j].ddd);
        flush_in();

        printf("Insira o %d° telefone da %d° pessoa: ", j+1, i+1);
        fgets(getNumero(p, i, j), 50, stdin);
        remover_quebra_de_linha(getNumero(p, i, j));
      }
    }
  }
}

void imprimir_struct(PESSOA *p, int qtd_pessoas) {
  int i, j;
  for(i=0; i<qtd_pessoas; i++){
    printf("Nome      da %d° pessoa: %s\n",       i+1, getNome(p, i));
    printf("Idade     da %d° pessoa: %d anos\n",  i+1, getIdade(p, i));
    printf("CPF       da %d° pessoa: %s\n",       i+1, getCpf(p, i));
    printf("Cidade  da %d° pessoa: %s\n",         i+1, getCidade(p, i));
    printf("Bairro  da %d° pessoa: %s\n",         i+1, getBairro(p, i));
    printf("Complemento  da %d° pessoa: %s\n",    i+1, getComplemento(p, i));
    if(getQtdTelefones(p, i) > 0) {
      for(j=0; j<getQtdTelefones(p, i); j++){
        printf("DDD  do %d° telefone da %d° pessoa:   %d\n", j+1, i+1, getDDD(p, i, j));
        printf("Numero do %d° telefone da %d° pessoa: %s\n", j+1, i+1, getNumero(p, i, j));
      }
    }
    printf("\n");
  }
}
