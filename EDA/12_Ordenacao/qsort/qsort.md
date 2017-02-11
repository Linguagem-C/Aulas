# A função qsort() da biblioteca <stdlib.h>

## QuickSort

* Alogoritmo rapido de ordenação

* Complexidade: N log(N)

* Implementado na biblioteca <stdlib.h>

## Protótipo

```C
  void qsort(void *base, size_t num, size_t size, int (*compar)(const void*, const void*));
```
## Parametros

* **Base** = endereço do array a ser ordenado, de qualquer tipo

* **num** = Tamanho do array

* **size** = Tamanho em bytes, de cada posição do array, normalmente se usa **sizeof(tipo do array)**

* **compar** = Ponteiro para a função de comparação

* **size_of** é apenas um inteiro sem sinal

## Segredo da função

* Criar e especificar corretamente a função de comparação

## Função de comparação

* Função que define como dois valores (p1 e p2) do array serão comparados

* Deve seguir o seguinte prototipo

```C
  int compar(const void* p1, const void* p2);
```

* **Retorno da função**

```
  == 0: p1 é igual a p2
   < 0: p1 vem antes de p2
   > 0: p1 vem depois de p2
```
