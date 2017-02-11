/* S = 2 + 5/2 + 10/3 + ... + (1+n^2)/n */
#include <stdio.h>
#include <stdlib.h>

float serie(int n) {
	if (n > 0)
		return (1+n*n)/(float)(n) + serie(n-1);
	else
		return 0;
}

int main() {
	int n;

	printf("Insira o valor n da serie: ");
	scanf("%d", &n);

	printf("S = %f\n", serie(n));

	return 0;
}

