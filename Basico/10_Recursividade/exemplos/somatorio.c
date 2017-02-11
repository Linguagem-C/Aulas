#include <stdio.h>
#include <stdlib.h>

/* S(i=1->i=n) i */
int Somatorio1(int n){
  if (n==0)
    return 0;
  else
    return n + Somatorio1(n-1);
}

/* S(i=1->i=n) (n^2+1)/(n+3) */
float Somatorio2(int n) {
	if(n <= 0) return 0;

	return (n*n+1)/(float)(n+3) + Somatorio2(n-1);
}

int main() {
	int n;

	printf("Insira a quantidade de termos do somatorio: ");
	scanf("%d", &n);

	printf("S1 = %d\n", Somatorio1(n));

	printf("S2 = %f\n", Somatorio2(n));

	return 0;
}