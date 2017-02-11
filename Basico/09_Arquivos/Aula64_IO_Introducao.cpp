#include <stdlib.h>
#include <stdio.h> 

int main(){

  FILE *arq;

  arq = fopen("doc/arquivo.txt", "w");

  if( arq == NULL){
    printf("Erro na abertura do arquivo!");
    exit(1);
  }else{
    printf("Arquivo aberto com sucesso!\n");
  }

  int fechou = fclose(arq);

  if(fechou == 0)
    printf("Arquivo fechado com sucesso!\n");

	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

  DEFINIÇÃO:

    - Arquivo é uma coleção de bytes armazenado em um dispositivo de armazenamento 
    secundario: CD, DVD disco rigido e etc...

    - A linguagem C usa um tipo especial de ponteiro para armazenar arquivos: FILE *v;

    - Esse ponteiro que controla o fluxo de leitura e escrita do arquivo.

    - A linguagem C só trabalha com 2 tipos de arquivos, arquivos de texto e arquivos 
    binarios, porém todos os arquivos que existem pode se classificado como um desses dois

  DECLARAÇÃO:

    - fopen() -> permite abrir um arquivo em um determinado modo de leitura ou escrita

      FILE *fopen(char *arquivo, char *modo_de_leitura);

  OBSERVAÇÕES:

    - Para o endereço do arquivo podemos passa-lo com absoluto ou relatio

      absoluto = Endereço completo do arquivo -> /home/victor/Desktop/arquivo.txt
      relativo = Endereço parcial, começa onde está o programa. -> ../ArquivoIO/arquivo.txt

  MODO DE ABERTURA:

    - modo de abertura especifica o tipo de uso do arquivo

      "r" = read = Leitura de um arquivo texto, porém o arquivo deve existir.
      "w" = write = Escrita de um arquivo texto, cria se não houver e sobrescreve se existir.
      "a" = append = Escrita em que os dados serão armazenados no fim do arquivo.
      "r+" = Leitura e escrita = O arquivo deve existir e pode ser modificado
      "w+" = Leitura e escrita = Cria o arquivo se não houver e sobrescreve o anterior se existir
      "a+" = Leitura e escrita = Os dados serão adicionados no fim do arquivo

      "rb" = read binary = Leitura de um arquivo binario
      "wb" = write binary = Escrita de um arquivo binario
      "ab" = append binary = Dados escrito no fim do arquivo binario
      "r+b" = Leitura e escrita = O arquivo binario deve existir e pode ser modificado
      "w+b" = Leitura e escrita = Cria o arquivo binario se não houver e sobrescreve o anterior se existir
      "a+b" = Leitura e escrita = Os dados serão adicionados no fim do arquivo binario

  FECHAMENTO:

    - Sempre que terminarmos de ler um arquivo devemos fecha-lo com o fclose(FILE *f), 
    retorna zero caso seja fechado com sucesso.

    - fechar o arquivo garante que tudo foi gravado com sucesso


-----------------------------------------------------------------------------------------*/
