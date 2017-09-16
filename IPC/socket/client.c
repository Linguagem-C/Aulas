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
#define MSG_LEN 4096

// Placa de rede do servidor remoto
struct sockaddr_in remoto;

int main() {

  int descritor;            // Usado para escrever e ler dados no socket
  int len = sizeof(remoto); // Armazena o tamanho da placa de rede do servidor
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
  remoto.sin_family = AF_INET;
  // Transforma a porta em números de rede
  remoto.sin_port = htons(PORTA);
  // Insere o ip do servidor, transforma o IP em IP de rede.
  remoto.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Zera a memória da estrutura de dados local
  memset(remoto.sin_zero, 0x0, 8);

  // Se conecta com o servidor
  if(connect(descritor, (struct sockaddr*) &remoto, len) == ERROR) {
    perror("connect");
    exit(1);
  } else {
    printf("Conexão estabelecida com sucesso!\n");
  }

  // Aguarda resposta do servidor
  while(TRUE) {
    // Receber a mensagem do servidor.
    if((string_len = recv(descritor, buffer, MSG_LEN, 0)) > 0) {
      // Insere o valor nulo no final e tira a quebra de linha
      buffer[string_len - 1] = '\0';
      printf("Mensagem recebida: %s\n", buffer);
    }

    memset(buffer, 0x0, MSG_LEN); // Limpar o buffer
    fgets(buffer, MSG_LEN, stdin);
    send(descritor, buffer, strlen(buffer), 0);
    break;
  }

  // Encerrar a conexão do servidor
  close(descritor);
  printf("Cliente encerrado!\n");

  return 0;
}
