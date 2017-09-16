#include "tcp.h"

int main() {

  int descriptor;           // Usado para escrever e ler dados no socket
  int string_len;           // Armazena o tamanho da string de buffer
  char buffer[MSG_LEN];     // Cria a string de buffer da mensagem

  descriptor = create_socket_tcp();

  configure_tcp_client();

  connect_to_server(&descriptor);

  // Aguarda resposta do servidor
  while(TRUE) {
    // Receber a mensagem do servidor.
    if((string_len = recv(descriptor, buffer, MSG_LEN, 0)) > 0) {
      // Insere o valor nulo no final e tira a quebra de linha
      buffer[string_len - 1] = '\0';
      printf("Mensagem recebida: %s\n", buffer);
    }

    memset(buffer, 0x0, MSG_LEN); // Limpar o buffer
    fgets(buffer, MSG_LEN, stdin);
    send(descriptor, buffer, strlen(buffer), 0);
    break;
  }

  // Encerrar a conexão do servidor
  close(descriptor);
  printf("Cliente encerrado!\n");

  return 0;
}
