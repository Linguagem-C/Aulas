#include "queue.h"

int main() {

  struct msgbuffer buffer;
  int queue;
  key_t key;

  // Cria a chave para criar a fila de mensagem
  create_key(&key, "queue-send.c", 'B');

  // Cria a fila de mensagem (IPC_CREAT)
  get_queue(&queue, key, 0644 | IPC_CREAT);

  // Insere a mensagem
  printf("Entre com o texto: ");
  fgets(buffer.message, 200, stdin);
  remove_line_break(buffer.message);

  // Manda a mensagem para a fila
  send_message_to_queue(&queue, buffer);

  return 0;
}
