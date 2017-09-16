#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
// Headers para socket
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

// Constantes
#define ERROR  -1
#define TRUE  1
#define FALSE  0
#define PORTA 2000
#define NUMBER_OF_CONNECTION 1
#define MSG_LEN 4096

// Placa de rede local - 127.0.0.1 ou localhost
struct sockaddr_in local;
// Placa de rede do cliente remoto
struct sockaddr_in remoto;


int main() {

  int descritor;            // Usado para escrever e ler dados no socket
  int cliente;              // Armazena o descritor do cliente.
  int len = sizeof(remoto); // Armazena o tamanho da placa de rede do cliente
  int string_len;           // Armazena o tamanho da string de buffer
  char buffer[MSG_LEN];     // Cria a string de buffer da mensagem

  // Cria a comunicação (endpoint) via protocolo IPv4 da camada de redes (dominio) e protocolo TCP da camada de transporte (tipo)
  descritor = socket(AF_INET, SOCK_STREAM, 0);

  // Caso ocorra algum erro
  if (descritor == ERROR) {
    perror("socket");
    exit(1);
  } else {
    printf("Socket criado com sucesso!\n");
  }

  // Pega o protocolo IPv4
  local.sin_family = AF_INET;
  // Transforma a porta em números de rede
  local.sin_port = htons(PORTA);

  // Zera a memória da estrutura de dados local
  memset(local.sin_zero, 0x0, 8);

  // Atribui o endereço local ao socket descritor. Ou seja atribui um nome ao socket
  if(bind(descritor, (struct sockaddr*) &local, sizeof(local)) == ERROR) {
    perror("bind");
    exit(1);
  }

  // Colocar a porta em escuta para alguma conexão de um socket.
  listen(descritor, NUMBER_OF_CONNECTION);

  // Receber e aceitar as conexões dos clientes
  if((cliente = accept(descritor, (struct sockaddr*) &remoto, &len)) == ERROR) {
    perror("accept");
    exit(1);
  } else {
    printf("Conexão estabelecida com sucesso!\n");
  }

  strcpy(buffer, "Bem vindo ao servidor!\n\0");

  // Enviar a mensagem de bem vindo para o cliente
  if(send(cliente, buffer, strlen(buffer), 0)) {
    // Aguarda resposta do cliente
    printf("Aguardando resposta do cliente!\n");
    while(TRUE) {
      memset(buffer, 0x0, MSG_LEN); // Limpar o buffer
      // Receber a mensagem do cliente.
      if((string_len = recv(cliente, buffer, MSG_LEN, 0)) > 0) {
        // Insere o valor nulo no final e tira a quebra de linha
        buffer[string_len - 1] = '\0';
        printf("Mensagem recebida: %s\n", buffer);
        // Encerrar a conexão com o cliente
        close(cliente);
        break;
      }
    }
  }

  // Encerrar a conexão do servidor
  close(descritor);
  printf("Servidor encerrado!\n");

  return 0;
}
