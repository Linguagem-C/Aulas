// Para ver a fila de mensagem use ipcs -q e para remover use ipcrm -q id
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

struct msgbuffer {
  long message_type;
  char message[1024];
};

void remove_line_break(char *string) {
  size_t size;
  size = strlen(string);
  if (string[size - 1] == '\n'){
    string[--size] = 0;
  }
}

void create_key(key_t *key, char *file, char letter) {
  // Cria uma chave aleatória através do nome de algum arquivo e um caracter qualquer (B)
  // ftok usa informações sobre algum arquivo e o caractere para gerar a chave provavelmente única
  if((*key = ftok(file, letter)) == -1) {
    perror("ftok");
    exit(1);
  }
}

void get_queue(int *queue, key_t key, int permissions) {
  // Cria (IPC_CREAT) a fila no modo leitura (0644) e retorna seu ID utilizando um chave (key)
  if ((*queue = msgget(key, permissions)) == -1) {
    perror("msgget");
    exit(1);
  }
}

void destroy_queue(int *queue) {
  // Destroi a fila de mensagem (IPC_RMID)
  if(msgctl(*queue, IPC_RMID, NULL) == -1) {
    perror("msgctl");
    exit(1);
  }
}

void send_message_to_queue(int *queue, struct msgbuffer buffer) {
  // Usado para recupera a próxima mensagem da fila
  buffer.message_type = 1;

  // Envia a mensagem para a fila.
  if(msgsnd(*queue, &buffer, sizeof(buffer), 0) == -1) {
    perror("msgsnd");
    exit(1);
  }
}

struct msgbuffer receive_message_from_queue(int *queue, struct msgbuffer buffer) {

    // Recebe as mensagem que estão armazenadas na fila de mensagens
    // 0: Recupera a próxima mensagem da fila, independente de seu mtype (message_type)
    // > 0: Pega a próxima mensagem com mtype igual ao msgtyp especificado.
    // < 0: Recupera a primeira mensagem na fica cujo mtype é menor ou igual ao valor absoluto de msgtyp.
    if(msgrcv(*queue, &buffer, sizeof(buffer), 0, 0) == -1) {
      perror("msgrcv");
      exit(1);
    }

    return buffer;
}
