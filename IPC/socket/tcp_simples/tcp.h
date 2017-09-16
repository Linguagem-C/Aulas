#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// Headers para socket
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Constantes
#define ERROR  -1
#define TRUE  1
#define FALSE  0
#define PORTA 2000
#define NUMBER_OF_CONNECTION 1
#define MSG_LEN 2048

// Placa de rede do servidor remoto (CLIENTE)
struct sockaddr_in client_host;
// Armazena o tamanho da placa de rede do cliente
int len = sizeof(client_host);

// Placa de rede do servidor local - 127.0.0.1 ou localhost (SERVIDOR)
struct sockaddr_in server_host;


int create_socket_tcp() {
  int socket_descriptor;  // Usado para escrever e ler dados no socket

  // Cria a comunicação (endpoint) via protocolo IPv4 da camada de redes (dominio)
  // e protocolo TCP da camada de transporte (tipo)
  socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);

  // Caso ocorra algum erro
  if (socket_descriptor == ERROR) {
    perror("socket");
    exit(1);
  } else {
    printf("Socket criado com sucesso!\n");
  }

  return socket_descriptor;
}


void configure_tcp_server(int *socket_descriptor) {
  // Pega o protocolo IPv4
  server_host.sin_family = AF_INET;
  // Transforma a porta em números de rede
  server_host.sin_port = htons(PORTA);

  // Zera a memória da estrutura de dados local
  memset(server_host.sin_zero, 0x0, 8);

  // Atribui o endereço local ao socket descritor. Ou seja atribui um nome ao socket
  if(bind(*socket_descriptor, (struct sockaddr*) &server_host, sizeof(server_host)) == ERROR) {
    perror("bind");
    exit(1);
  }

  // Colocar a porta em escuta para alguma conexão de um socket.
  listen(*socket_descriptor, NUMBER_OF_CONNECTION);
}


void configure_tcp_client() {
  // Pega o protocolo IPv4
  client_host.sin_family = AF_INET;
  // Transforma a porta em números de rede
  client_host.sin_port = htons(PORTA);
  // Insere o ip do servidor, transforma o IP em IP de rede.
  client_host.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Zera a memória da estrutura de dados local
  memset(client_host.sin_zero, 0x0, 8);
}


void connect_to_server(int *socket_descriptor) {
  // Se conecta com o servidor
  if(connect(*socket_descriptor, (struct sockaddr*) &client_host, len) == ERROR) {
    perror("connect");
    exit(1);
  } else {
    printf("Conexão estabelecida com sucesso!\n");
  }
}


void accept_client_connection(int *socket_client, int *socket_descriptor) {
  // Receber e aceitar as conexões dos clientes
  if((*socket_client = accept(*socket_descriptor, (struct sockaddr*) &client_host, &len)) == ERROR) {
    perror("accept");
    exit(1);
  } else {
    printf("Conexão estabelecida com sucesso!\n");
  }
}


void close_connection(int socket) {
  // Encerrar a conexão
  close(socket);
  printf("Conexão encerrada!\n");
}


void receive_message(int *descriptor, char *buffer) {
  int string_len;  // Armazena o tamanho da string de buffer

  // Receber a mensagem do servidor.
  if((string_len = recv(*descriptor, buffer, MSG_LEN, 0)) > 0) {
    // Insere o valor nulo no final e tira a quebra de linha
    buffer[string_len - 1] = '\0';
    printf("Mensagem recebida: %s\n", buffer);
  }
}
