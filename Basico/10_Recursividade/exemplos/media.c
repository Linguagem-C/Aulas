#include <stdio.h>

float media(int *vetor, int numeroDeElementos, int tam) {
	if(numeroDeElementos <= 0)
		return 0;
	else
		return vetor[numeroDeElementos-1]/(float)tam + media(vetor, numeroDeElementos-1, tam);
}

int main() {
	
	int v[5] = {1, 2, 3, 4, 5};

	printf("Media = %f\n", media(v, 5, 5));

	return 0;
}