#include "queue.h"

int main() {

  struct msgbuffer buffer;
  int queue;
  key_t key;

  // Cria a chave para a fila de mensagem
  create_key(&key, "queue-send.c", 'B');

  // Abre a fila de mensagem se existir
  get_queue(&queue, key, 0644);

  printf("Pronto para receber mensagens.\n");

  // Recebe as mensagens que estão na fila
  while(1) {
    buffer = receive_message_from_queue(&queue, buffer);

    printf("Mensagem: %s\n", buffer.message);
  }
}
