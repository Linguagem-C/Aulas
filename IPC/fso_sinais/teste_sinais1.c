#include <signal.h>
#include <unistd.h>
#include <stdio.h>

void treat_signal(int sinal) {
  printf("\n\n **** Processo insensivel a sinais ... ****\n");
  printf("**** Sinal recebido: %i \n\n", sinal);
}

int main() {
  char c;
  int s;

  // Inibe todos os sinais na faixa de 1 a 34.
  for(s=1; s<35; s++) {
    signal(s, treat_signal);
  }

  while(1) {
    printf("Processo ainda em execução ... Meu pid é %i\n", getpid());
    sleep(3);
  }

  return 0;
}
