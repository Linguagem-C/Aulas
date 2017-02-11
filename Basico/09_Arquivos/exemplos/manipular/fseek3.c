#include <stdio.h>

int main () {

   FILE *f;

   f = fopen("doc/myfile.txt","w+");
   fputs("This is tutorialspoint.com", f);
  
   fseek(f, 7, SEEK_SET);
   fputs(" C Programming Language", f);
   fclose(f);
   
   return(0);
}