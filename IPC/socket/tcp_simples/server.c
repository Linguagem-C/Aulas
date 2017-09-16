#include "tcp.h"

int main() {

  int socket_descriptor;    // Usado para escrever e ler dados no socket
  int client_descriptor;    // Armazena o descritor do cliente.
  int string_len;           // Armazena o tamanho da string de buffer
  char buffer[MSG_LEN];     // Cria a string de buffer da mensagem

  socket_descriptor = create_socket_tcp();

  configure_tcp_server(&socket_descriptor);

  accept_client_connection(&client_descriptor, &socket_descriptor);

  /* // Enviar a mensagem de bem vindo para o cliente */
  strcpy(buffer, "Bem vindo ao servidor!\n\0");
  send(client_descriptor, buffer, strlen(buffer), 0);

  // Aguarda resposta do cliente
  printf("Aguardando resposta do cliente!\n");
  while(TRUE) {
    memset(buffer, 0x0, MSG_LEN); // Limpar o buffer
    // Receber a mensagem do cliente.
    if((string_len = recv(client_descriptor, buffer, MSG_LEN, 0)) > 0) {
      // Insere o valor nulo no final e tira a quebra de linha
      buffer[string_len - 1] = '\0';
      printf("Mensagem recebida: %s\n", buffer);
      /* // Encerrar a conexão com o cliente */
      close(client_descriptor);
      break;
    }
  }

  close_connection(socket_descriptor);

  return 0;
}
