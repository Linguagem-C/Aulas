#include <stdio.h>

int main () {
   FILE *f;
   int c;

   f = fopen("doc/file.txt","r");
   while(1) {
      c = fgetc(f);
      if(feof(f)){
         break;
      }
      printf("%c", c);
   }
   fclose(f);
   return(0);
}