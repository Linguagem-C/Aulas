#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int a;

// Rotina de tratamento de sinais
void treatHUP(int sinal) {
  a = 0;
}

// Processo.
void main() {
  signal(10, treatHUP);
  printf("Meu pid eh %i\n", getpid());
  while(1) {
    printf("Valor de a = %i\n", a);
    a++;
    sleep(3);
  }
}
