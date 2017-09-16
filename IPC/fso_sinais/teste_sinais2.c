#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void treat_signal1(int signal) {
  printf("Processo abortado em funcao de timeout!\n");
  // A função raise envia um sinal para o próprio processo.
  // Esse sinal equivale a kill(getpid(), sinal).
  raise(15);
}

void treat_signal2(int sinal) {
  printf("Tempo esgotado... Aguardando nova digitacao dentro de 4 segundos!\n");
  // Redefine o sinal SIGALRM para outra funcao
  signal(SIGALRM, treat_signal1);
  alarm(4); //agenda 4 segundos.
}

int main() {
  int a;
  signal(SIGALRM, treat_signal2);

  printf("Meu pid eh %i\n", getpid());
  alarm(7); // agenda 7 segundos para disparar o sinal SIGALRM
  printf("Digite um numero: \n");
  scanf("%i", &a);
  alarm(0); // cancela agendamento
  printf("Obrigado.\n");
  return 0;
}
