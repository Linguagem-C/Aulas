#include <stdio.h>

int mdc(int p, int q) {
	if(q == 0)
		return p;
	else
		return mdc(q, p%q);
}

int main() {
	int p,q;

	printf("Insira o valor de x: ");
	scanf("%d", &p);

	printf("Insira o valor de y: ");
	scanf("%d", &q);

	printf("%d\n", mdc(p, q));

	return 0;
}
