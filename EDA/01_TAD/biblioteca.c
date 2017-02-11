#include "lib/biblioteca.h"

struct ponto {
	float x;
	float y;
};

Ponto *criar_ponto(float x, float y){
	Ponto *p = (Ponto*) malloc(sizeof(Ponto));
	if(p != NULL){
		p->x = x;
		p->y = y;
	}
	return p;
}

void liberar_ponto(Ponto *p){
	free(p);
}

void acessar_ponto(Ponto *p, float *x, float *y){
	*x = p->x;
	*y = p->y;
}

void atribuir_valores(Ponto *p, float x, float y){
	p->x = x;
	p->y = y;
}

float distancia_pontos(Ponto *p1, Ponto *p2){
	float dx = p1->x - p2->x;
	float dy = p1->y - p2->y;
	return sqrt((dx*dx) + (dy*dy));
}
