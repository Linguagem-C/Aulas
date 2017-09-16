#include "shm.h"

int main() {
  int segment_id; // Identificador do segmento
  char *shared_memory; // Endereço da memória compartilhada
  key_t key = 1234; // Chado do segmento

  // IPC_CREATE cria um novo segmento
  // 0666 são as permissões de escrita e leitura para qualquer usuário
  segment_id = get_shared_memory(key, IPC_CREAT | 0666);

  // Realoca a memória compartilhada com um endereço diferente.
  shared_memory = attach_shared_memory(&segment_id, (void*) 0x5000000);

  // Imprime a string que está armazenada na memória compartilhada.
  printf("%s\n", shared_memory);

  // Desaloca a memória compartilhada
  detach_shared_memory(shared_memory);

  // Remove a memória compartilhada
  remove_shared_memory(&segment_id);

  return 0;
}
