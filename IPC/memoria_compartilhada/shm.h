// Para verificar a memórias no terminal use ipcs -m e para remover ipcrm -m <shmid>
#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include <sys/stat.h>


int get_shared_memory(key_t key, int permissions) {
  int segment_id;                         // Identificador do segmento
  const int shared_segment_size = 0x6400; // Número de bytes do segmento

  // Aloca o segmento de memória compartilhada (shm=shared memory get)
  // key cria a chave que especifica o segmento a ser criado,
  // outros processos para acessar essa memoria compartilhada precisa dessa chave.
  if ((segment_id = shmget(key, shared_segment_size, permissions)) < 0) {
    perror("shmget");
    exit(1);
  }
  printf("Identificador da memória compartilhada: %d\n", segment_id);

  return segment_id;
}


char *attach_shared_memory(int *segment_id, const void *address) {
  char *shared_memory; // Endereço da memória compartilhada

  // Deixar a memória compartilhada acessível (shmat = shared memory attach)
  // Filhos criados com fork herdam segmentos de memoria compartilhada anexados(attached)
  if((shared_memory = (char*) shmat(*segment_id, address, 0)) == (char*) -1) {
    perror("shmat");
    exit(1);
  }
  printf("Endereço de memória compartilhada realocado: %p\n", shared_memory);

  return shared_memory;
}


void detach_shared_memory(char *shared_memory) {
  // Quando você terminar de usar um segmento de memória compartilhada,
  // o segmento deve ser separado (detached - não acessivel) usando
  // shmdt (shared memory detach) e passando seu endereço.
  shmdt(shared_memory);
}


void remove_shared_memory(int *segment_id) {
  // A função shmctl (shared memory control) retorna informações sobre a memória
  // compartilhada e pode ser modificado.
  // O primeiro parametro é o identificador da memória
  // Para remover o segmento de memória compartilhada usamos no segundo paramentro o IPC_RMID
  // e NULL como terceiro argumento.
  // Finaliza quando o ultimo processo que utiliza a memoria for desalocado.
  shmctl(*segment_id, IPC_RMID, NULL);
}


void get_shared_memory_information(int segment_id) {
  struct shmid_ds shmbuffer; // Dados da memória compartilhada

  // A função shmctl (shared memory control) retorna informações sobre a memória
  // compartilhada e pode ser modificado.
  // O primeiro parametro é o identificador da memória
  // Para pegar as informações da memória no segundo parametro usamos o IPC_STAT
  // e no terceiro um ponteiro para a struct shmid_ds
  // shm_segsz determina o tamanho do segmento
  shmctl(segment_id, IPC_STAT, &shmbuffer);
  int segment_size = shmbuffer.shm_segsz;
  printf("Tamanho do segmento: %d\n", segment_size);
}
