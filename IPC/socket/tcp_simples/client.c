#include "tcp.h"

int main() {

  int socket_descriptor;    // Usado para escrever e ler dados no socket
  char buffer[MSG_LEN];     // Cria a string de buffer da mensagem

  socket_descriptor = create_socket_tcp();

  configure_tcp_client();

  connect_to_server(&socket_descriptor);

  receive_message(&socket_descriptor, buffer);

  // Envia a mensagem para o servidor
  memset(buffer, 0x0, MSG_LEN); // Limpar o buffer
  fgets(buffer, MSG_LEN, stdin);
  send(socket_descriptor, buffer, strlen(buffer), 0);

  close_connection(socket_descriptor);

  return 0;
}
