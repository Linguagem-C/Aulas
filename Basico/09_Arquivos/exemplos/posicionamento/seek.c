#include <stdio.h>
#include <stdlib.h>

int seekLine(FILE *f, int lineNumber, char *line) {

   //Este código funcionará diferente em relação ao outro.

   int currentSeek = ftell(f);
   fseek(f, 0, SEEK_SET);
   while(--lineNumber && (fgets(line, 256, f) != NULL));

   //Isso mesmo, coloquei ponto e virgula depois do WHILE, pois quero que o ponteiro(seek) dentro do arquivo 
   //aponte para uma linha anterior da que queremos.

   if(!lineNumber) // Se lineNumber é 0 escontramos nossa linha, avançamos e a colocamos no buffer
      fgets(line, 256, f);

   fseek(f, currentSeek, SEEK_SET);

  return !lineNumber;

   //Retorna que não encontrou, mas matem a ultima linha encontrada.

}


int main() {

  FILE *file;
  file = fopen("doc/file.txt", "r");
  if(!file){
    printf("erro abrindo arquivo\n");
    return 0;
  }

  char line[256];
  int quero = 13; // Digite aqui qual linha pegar


  if(seekLine(file, quero, line))
    printf("Number line %d: %s\n", quero, line);
  else
    printf("Não existe a linha %d ou o arquivo está vazio\n", quero);

  fclose(file);

  return 0;

}
