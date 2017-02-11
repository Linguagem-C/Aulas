#include <stdio.h>
#include <time.h>
#include <locale.h>

void converter_localidade(){
  struct lconv * locale;

   setlocale(LC_ALL, "");
   locale = localeconv();
   printf("Símbolo de moeda local: %s\n",locale->currency_symbol);
   printf("Símbolo internacional de moeda: %s\n",locale->int_curr_symbol);
   printf("Separador decimal local: %s\n", locale->decimal_point);
   printf("Separador decimal internacional: %s\n", locale->thousands_sep);
   printf("Separador decimal local monetário: %s\n", locale->mon_decimal_point);
   printf("Separador decimal internacional monetário: %s\n", locale->mon_thousands_sep);
   printf("Símbolo de valores monetarios positivos: %s\n", locale->positive_sign);
   printf("Símbolo de valores monetarios negativos: %s\n", locale->negative_sign);
   printf("Número de dígitos para mostrar depois do ponto decimal em valores monetários internacionais: %d\n", locale->int_frac_digits);
   printf("Número de dígitos para mostrar depois do ponto decimal em valores monetários locais: %d\n", locale->frac_digits);
   printf("1(Símbolo aparece depois de valores monetários positivos), 0(antes): %d\n", locale->p_cs_precedes);
   printf("1(Símbolo é separado por espaço do valor monetário positivo), 0(caso contrario): %d\n", locale->p_sep_by_space);
   printf("1(Símbolo antecede valores monetários negativo), 0(caso contrario): %d\n", locale->n_cs_precedes);
   printf("1(Símbolo é separado por espaço do valor monetário negativos), 0(caso contrario): %d\n", locale->n_sep_by_space);
   printf("Representa a posição do sinal positivo num valor monetário positiva: %d\n", locale->p_sign_posn);
   printf("Representa a posição do sinal negativo num valor monetário negativo: %d\n", locale->n_sign_posn);
   printf("Para os casos de n_sign_posn\n");
   printf("0(Valor do Símbolo é encapsulado por parenteses)\n");
   printf("1(O sinal antecede o Símbolo de moeda local e seu valor)\n");
   printf("2(O sinal sucede o Símbolo de moeda local e seu valor)\n");
   printf("3(O sinal imediatamente antecede o Símbolo de moeda local e seu valor)\n");
   printf("4(O sinal imediatamente sucede o Símbolo de moeda local e seu valor)\n");
   printf("\n\n");
}

void tempo(){
  float f = 3.45;
  time_t tempo;
  struct tm *infotempo;
  char data[80];
  time(&tempo);
  infotempo = localtime(&tempo);

  printf("Alô mundo!\n");
  printf("Valor de f = %f\n", f);
  strftime(data, 80, "Data: %A, %d/%b/%Y", infotempo);
  puts(data);
  printf("\n");
  
  printf("Locale: %s\n", setlocale(LC_ALL, ""));
  
  printf("\nAlô mundo!\n");
  printf("Valor de f = %f\n", f);
  strftime(data, 80, "%c", infotempo);
  printf("Data: %s\n", data);
  printf("\n\n");
}

int main(){

  tempo();

  converter_localidade();

  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Sempre que utilizamos a função printf() nós evitamos usar acentuações porque o 
    padrão americano não suporta caracteres acentuados.

    - podemos instalar a localidade do sistema especificando, ou apenas uma parte dela, 
    como localidade da linguagem C usando a função: setlocale().

  DECLARAÇÃO:

    char *setlocale(int categoria, const char *local);

  PARÂMETROS:

    categoria -- É uma das macros definidas para localidade.

    local -- É o identificador de localidade do sistema especificado.

  RETORNO:

    Null caso de erro

    Um ponteiro para uma string contendo a identificação da nova localidade.

  VALORES POSSIVEIS PARA MACRO:

    1) LC_ALL: Afeta todo o local da linguagem.
    2) LC_COLLATE: Afeta as funções strcoll() e strxfrm() que trabalha com strings.
    3) LC_CTYPE: Afeta as funções que manipulam caracteres.
    4) LC_MONETARY: Afeta a informação de formatação monetaria.
    5) LC_NUMERIC: Afeta a formatação numerica da localidade em C.
    6) LC_TIME: Afeta a função de formatação de data e hora strftime().
    7) LC_MESSAGES: Afeta mensagens do sistema.

  - Local é um valor especifico do sistema, porém dois valores sempre existiram:

    C -- Para localidade minima da linguagem.
    "" -- Para localidade padrão do sistema.

  TIPOS DE RETORNO DA FUNÇÃO LOCALECONV()

    - Converte caracteres de uma localidade para outra.

    typedef struct {
     char *decimal_point;
     char *thousands_sep;
     char *grouping;  
     char *int_curr_symbol;
     char *currency_symbol;
     char *mon_decimal_point;
     char *mon_thousands_sep;
     char *mon_grouping;
     char *positive_sign;
     char *negative_sign;
     char int_frac_digits;
     char frac_digits;
     char p_cs_precedes;
     char p_sep_by_space;
     char n_cs_precedes;
     char n_sep_by_space;
     char p_sign_posn;
     char n_sign_posn;
    } lconv;

---------------------------------------------------------------------------------------- */