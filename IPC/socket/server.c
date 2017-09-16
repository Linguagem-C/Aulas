#include "tcp.h"

int main() {

  int descriptor;           // Usado para escrever e ler dados no socket
  int client;               // Armazena o descritor do cliente.
  int string_len;           // Armazena o tamanho da string de buffer
  char buffer[MSG_LEN];     // Cria a string de buffer da mensagem

  descriptor = create_socket_tcp();

  configure_tcp_server(&descriptor);

  accept_client_connection(&client, &descriptor);

  strcpy(buffer, "Bem vindo ao servidor!\n\0");

  // Enviar a mensagem de bem vindo para o cliente
  if(send(client, buffer, strlen(buffer), 0)) {
    // Aguarda resposta do cliente
    printf("Aguardando resposta do cliente!\n");
    while(TRUE) {
      memset(buffer, 0x0, MSG_LEN); // Limpar o buffer
      // Receber a mensagem do cliente.
      if((string_len = recv(client, buffer, MSG_LEN, 0)) > 0) {
        // Insere o valor nulo no final e tira a quebra de linha
        buffer[string_len - 1] = '\0';
        printf("Mensagem recebida: %s\n", buffer);
        // Encerrar a conexão com o cliente
        close(client);
        break;
      }
    }
  }

  // Encerrar a conexão do servidor
  close(descriptor);
  printf("Servidor encerrado!\n");

  return 0;
}
