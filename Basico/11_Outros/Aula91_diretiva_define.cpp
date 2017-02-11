#include <stdio.h>
#define PI 3.14
#define maior(x, y) x>y?x:y;
#define prod(x, y) (x)*(y);
#define troca(a,b,c) { c t = a; \
                         a = b; \
                         b = t; \
                      };

int main() {

  int a = 5, b = 8;
  int c = maior(a, b);
  int d = prod(a+2, b);
  printf("Maior: %d\n", c);
  printf("Produto: %d\n", d);

  printf("%d %d\n", a, b);
  troca(a, b, int);
  printf("%d %d\n", a, b);
  
  return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DIRETIVAS DE COMPILAÇÃO:

    - São instruções que servem para fazer alterações no código fonte antes de envia-lo 
    para o compilador.

  DIRETIVA #define

    - Essa diretiva informa ao compilador que ele deve procurar todas as ocorrências de 
    determinada expressão e substituí-la por outra quando o comando for compilado.

  SINTAXES:

    #define nome_qualquer

      - Define um nome que poderá ser testado com os comandos de inclusão condicional

    #define nomeCostante valorConstante

      - Informa ao compilador que ele deve procurar todos as ocorrências de "nomeCostante"
      e substituí-la por "valorCostante" quando o programa for compilado.

      - Normalmente o nomeCostante é com letra maiuscula.

    #define nomeMacro(parâmetros) expressão

      - Define uma função macro

      - Uma macro é um pedaço de código na qual foi atribuido um nome.

  CUIDADO:

    - É aconselhável sempre colocar, na sequência de substituição os parâmetros da macro entre
    parenteses, isso serve para preservar a precedencia dos operadores.

    - Se a macro foi complicada é aconselhavel usar chaves, porém para quebrar linha temos que
    usar uma barra vertical inclinada (\) ao final de cada linha

  DIRETIVA #undef

    - Essa diretiva é utilizada sempre que desejamos apagar a definição de uma macro, ela remove-a
    para que a macro possa ser redefinida. (#undef nome_da_macro)

------------------------------------------------------------------------------------------- */