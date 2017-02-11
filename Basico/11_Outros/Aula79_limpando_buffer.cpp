#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


/*Limpa o buffer do teclado*/
void flush_in(){ 
    int ch;
    do{
        ch = fgetc(stdin);
    }while (ch != EOF && ch != '\n');
}

void remover_quebra_de_linha(char *string) {
  
  size_t tamanho;

  tamanho = strlen(string);

  /* remove '\n' e atualiza o tamanho */
  if (string[tamanho - 1] == '\n'){
    string[--tamanho] = 0;
  }
}

int main(){

  char ch;
  char str[5];
  int i;

  printf("Digite uma string de mais de 5 caracteres: ");
  fgets(str, 5, stdin);
  
  remover_quebra_de_linha(str);
  flush_in();
  
  printf("%s\n", str);

  for(i=0; i<5; i++) {
    printf("Digite o %d caractere: ", i+1);
    scanf(" %c", &ch);
  }

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Toda  a informação que digitamos no teclado é armazenado em um buffer e fica 
    disponivel para nossa utilização

    - quando usamos a função scanf(), ela recupera informação do buffer. Porém, ela pode 
    deixar sujeira no buffer, comprometendo futuras leituras.

  FORMAS DE LIMPAR O BUFFER:

    -  Existe diversas formas de limpar o buffer:

      setbuf(stdin, NULL) = Vai colocar NULL no buffer do teclado

      fflush(stdin) = Limpa o buffer, porém não se sabe o comportamento para o buffer do 
      teclado, então não é recomendado usar

  OBSERVAÇÕES:

    - Você pode simplismente colocar um espaço antes do %c do scanf(" %c", &ch); 
    que também limpa, porém tb não se saber o comportamento dele.

----------------------------------------------------------------------------------------- */