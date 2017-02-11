#include <stdio.h>
#include <string.h>

int x[5] = {1,2,3,4,5};
int y[5] = {2,2,2,2,2};

void imprime(int *v, int n){
  int i;
  for(i=0; i<n; i++){
    printf("%d, ", v[i]);
  }
  printf("\n");
}

void preenchimento_memoria() {

  imprime(x, 5);

  memset(x, 0, 4);
  imprime(x, 5);

  memset(x, 0, sizeof(x));
  imprime(x, 5);

}

void copiar_memoria() {

  imprime(x, 5);

  memcpy(x, y, 4);
  imprime(x, 5);

  memmove(x, y, sizeof(y));
  imprime(x, 5);

}

void comparar_memoria() {
  int resultado;

  resultado = memcmp(x, y, 4);

   if(resultado > 0)
      printf("str1 é maior que str2\n");
   else if(resultado < 0)
      printf("str1 é menor que str2\n");
   else 
      printf("str1 é igual a str2\n");

  imprime(x, 5);
  imprime(y, 5);
}

void procurar_memoria(int caractere){

  char str[50] = "Exemplo de string em C";
  char *p;

  p = (char*) memchr(str, caractere, strlen(str));

  if(p != NULL)
    printf("Encontrado na posição: %d\n", (p-str+1));
  else
    printf("Não encontrado!\n");
}

int main() {
  printf("\n\n");

  preenchimento_memoria();
  printf("\n\n");

  copiar_memoria();
  printf("\n\n");

  comparar_memoria();
  printf("\n\n");

  procurar_memoria('s');
  printf("\n\n");
   
  return(0);
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:
    
    - A linguagem C possui algumas funções para manipulação de memória

    - Essas funções estão na biblioteca <string.h>

  FUNÇÕES:

    - memset(): preenchimento de memória.
    - memcpy(): cópia de memória.
    - memmove(): cópia de memória mais segura.
    - memcmp(): comparação de memória.
    - memchr(): busca de memória.

  OBSERVAÇÕES:

    - int v[4] = 16 bytes pois int = 4 bytes e temos 4 int logo, 4 x 4 = 16


--------------------------------------------------------------------------------------- */