#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

void remover_quebra_de_linha(char *string) {
  
  size_t tamanho;

  tamanho = strlen(string);

  if (string[tamanho - 1] == '\n'){
    string[--tamanho] = 0;
  }
}

int main(){

  int flag = 0;
  char password[11];

  printf("Digite sua senha: ");
  fgets(password, 11, stdin);
  remover_quebra_de_linha(password);

  if(strcmp("linguagemc", password) == 0){
    flag = 1;
  }

  if(flag){
    printf("Acesso garantido!\n");
  }else{
    printf("Acesso negado!\n");
  }

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

  - Esse código é um exemplo simples de proteção por senha.

  - Porém, ele tem um grave problema: pode ser facilmente hackeado!

  - Para tanto, basta digitar uma senha qualquer com mais de 11 caracteres.

  - Isso vai estourar o buffer de memória da string passwd, vazando para a variável flag, 
  alterando seu valor, e assim garantindo o acesso.

  - É sempre importante garantir que não estamos gravando dentro de uma string mais do que ela suporta.

---------------------------------------------------------------------------------------- */