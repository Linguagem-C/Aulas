#include "struct.h"

int quantidade_registros() {
  FILE *file;
  int fechou;
  int qtd=0;

  file = fopen("doc/arquivo.txt", "r");

  if(file == NULL) {
    printf("Erro na abertuda do arquivo, arquivo não encontrado\n");
    exit(0);
  }

  while(feof(file) == 0){
    /*fscanf(file, "%s: %s")*/
  }



  fechou = fclose(file);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!\n");
    exit(0);
  }

  return qtd;
}
 
void criar_arquivo(PESSOA *p, int qtd_pessoas) {
  FILE *file;
  int i, j, fechou;

  file = fopen("doc/arquivo.txt", "w");

  if(file == NULL) {
    printf("Erro na abertuda do arquivo, arquivo não encontrado\n");
    exit(0);
  }

  preencher_struct(p, qtd_pessoas);

  for(i=0; i<qtd_pessoas; i++){
    fprintf(file, "Nome: %s\n",     getNome(p, i));
    fprintf(file, "Idade: %d\n",    getIdade(p, i));
    fprintf(file, "Endereço: %s, %s, %s\n", getCidade(p, i), getBairro(p, i), getComplemento(p, i));
    fprintf(file, "Cpf: %s\n",      getCpf(p, i));
    if(getQtdTelefones(p, i) > 0) {
      for(j=0; j<getQtdTelefones(p, i); j++)
        fprintf(file, "%d° Numero: (%d) %s\n", j+1, getDDD(p, i, j), getNumero(p, i, j));
    }
    fprintf(file, "\n");
  }

  fechou = fclose(file);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!\n");
    exit(0);
  }
}

void vizualizar_registros() {
  FILE *file;
  int fechou;
  char ch;

  file = fopen("doc/arquivo.txt", "r");

  if(file == NULL) {
    printf("Erro na abertuda do arquivo, arquivo não encontrado\n");
    exit(0);
  }

  ch = fgetc(file);
  while(ch != EOF) {
    printf("%c", ch);
    ch = fgetc(file);
  }
  printf("\n");

  fechou = fclose(file);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!\n");
    exit(0);
  }
}

void recuperar_registros(PESSOA *p, int qtd_pessoas) {
  FILE *file;
  int fechou;

  file = fopen("doc/arquivo.txt", "r");

  if(file == NULL) {
    printf("Erro na abertuda do arquivo, arquivo não encontrado\n");
    exit(0);
  }







  fechou = fclose(file);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!\n");
    exit(0);
  }
}


void editar_registro(PESSOA *p, int qtd_pessoas) {
  FILE *file;
  int fechou;

  file = fopen("doc/arquivo.txt", "r+");

  if(file == NULL) {
    printf("Erro na abertuda do arquivo, arquivo não encontrado\n");
    exit(0);
  }







  fechou = fclose(file);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!\n");
    exit(0);
  }
}

void buscar_registro(PESSOA *p, int qtd_pessoas) {
  FILE *file;
  int fechou;

  file = fopen("doc/arquivo.txt", "r+");

  if(file == NULL) {
    printf("Erro na abertuda do arquivo, arquivo não encontrado\n");
    exit(0);
  }







  fechou = fclose(file);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!\n");
    exit(0);
  }
}

void add_registro(PESSOA *p, int qtd_pessoas) {
  FILE *file;
  int fechou, i, j;

  file = fopen("doc/arquivo.txt", "a+");

  if(file == NULL) {
    printf("Erro na abertuda do arquivo, arquivo não encontrado\n");
    exit(0);
  }

  preencher_struct(p, qtd_pessoas);

  for(i=0; i<qtd_pessoas; i++){
    fprintf(file, "Nome: %s\n",     getNome(p, i));
    fprintf(file, "Idade: %d\n",    getIdade(p, i));
    fprintf(file, "Endereço: %s, %s, %s\n", getCidade(p, i), getBairro(p, i), getComplemento(p, i));
    fprintf(file, "Cpf: %s\n",      getCpf(p, i));
    if(getQtdTelefones(p, i) > 0) {
      for(j=0; j<getQtdTelefones(p, i); j++)
        fprintf(file, "%d° Numero: (%d) %s\n", j+1, getDDD(p, i, j), getNumero(p, i, j));
    }
    fprintf(file, "\n");
  }

  fechou = fclose(file);

  if(fechou != 0) {
    printf("Erro no fechamento do arquivo!\n");
    exit(0);
  }

}
