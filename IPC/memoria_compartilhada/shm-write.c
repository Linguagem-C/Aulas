#include "shm.h"

int main() {
  int segment_id; // Identificador do segmento
  char *shared_memory; // Endereço da memória compartilhada
  key_t key = 1234; // Chado do segmento

  // Cria um novo segmento (IPC_CREAT) e verifica se ele foi realmente criado e é único (IPC_EXCL)
  // 0666 - Permissão de escrita e leitura para todos os tipos de usuário
  segment_id = get_shared_memory(key, IPC_CREAT | IPC_EXCL | 0666);

  // Deixar a memória compartilhada acessível
  // NULL (linux vai escolher o endereço disponivel)
  shared_memory = attach_shared_memory(&segment_id, NULL);

  // Insere uma string na memória compartilhada
  sprintf(shared_memory, "Ola mundo");

  // Desaloca o segmento da memória compartilhada
  detach_shared_memory(shared_memory);

  // Pega a informação do tamanho da memória compartilhada
  get_shared_memory_information(segment_id);

  return 0;
}
