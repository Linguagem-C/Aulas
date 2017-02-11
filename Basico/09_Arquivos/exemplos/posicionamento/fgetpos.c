#include <stdio.h>

int main () {
   FILE *f;
   fpos_t position;

   f = fopen("doc/file.txt","w+");
   fgetpos(f, &position);
   fputs("Hello, World!", f);
  
   fsetpos(f, &position);
   fputs("This is going to override previous content", f);
   fclose(f);
   
   return(0);
}