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
#define MSG_LEN 4096

// Placa de rede do servidor remoto (CLIENTE)
struct sockaddr_in client;
// Armazena o tamanho da placa de rede do cliente
int len = sizeof(client);

// Placa de rede do servidor local - 127.0.0.1 ou localhost (SERVIDOR)
struct sockaddr_in server;


int create_socket_tcp() {
  int descriptor;  // Usado para escrever e ler dados no socket

  // Cria a comunicação (endpoint) via protocolo IPv4 da camada de redes (dominio)
  // e protocolo TCP da camada de transporte (tipo)
  descriptor = socket(AF_INET, SOCK_STREAM, 0);

  // Caso ocorra algum erro
  if (descriptor == ERROR) {
    perror("socket");
    exit(1);
  } else {
    printf("Socket criado com sucesso!\n");
  }

  return descriptor;
}


void configure_tcp_server(int *descriptor) {
  // Pega o protocolo IPv4
  server.sin_family = AF_INET;
  // Transforma a porta em números de rede
  server.sin_port = htons(PORTA);

  // Zera a memória da estrutura de dados local
  memset(server.sin_zero, 0x0, 8);

  // Atribui o endereço local ao socket descritor. Ou seja atribui um nome ao socket
  if(bind(*descriptor, (struct sockaddr*) &server, sizeof(server)) == ERROR) {
    perror("bind");
    exit(1);
  }

  // Colocar a porta em escuta para alguma conexão de um socket.
  listen(*descriptor, NUMBER_OF_CONNECTION);
}


void configure_tcp_client() {
  // Pega o protocolo IPv4
  client.sin_family = AF_INET;
  // Transforma a porta em números de rede
  client.sin_port = htons(PORTA);
  // Insere o ip do servidor, transforma o IP em IP de rede.
  client.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Zera a memória da estrutura de dados local
  memset(client.sin_zero, 0x0, 8);
}


void connect_to_server(int *descriptor) {
  // Se conecta com o servidor
  if(connect(*descriptor, (struct sockaddr*) &client, len) == ERROR) {
    perror("connect");
    exit(1);
  } else {
    printf("Conexão estabelecida com sucesso!\n");
  }
}


void accept_client_connection(int *client, int *descriptor) {
  // Receber e aceitar as conexões dos clientes
  if((*client = accept(*descriptor, (struct sockaddr*) &client, &len)) == ERROR) {
    perror("accept");
    exit(1);
  } else {
    printf("Conexão estabelecida com sucesso!\n");
  }
}
