#include <stdlib.h>
#include <stdio.h>
#define TAM 3
 
//Limpa o buffer do teclado após scanf
void flush_in(){ 
    int ch;
    do{
        ch = fgetc(stdin);
    }while (ch != EOF && ch != '\n');
}

struct Aluno{
    char Matricula[20];
    float prova1;
    float prova2;
    float trabalho;
};
 
typedef struct Aluno aluno;
 
float somaNotas(struct Aluno X){
      float soma = 0.0;
      soma += X.prova1;
      soma += X.prova2;
      soma += X.trabalho;
	return soma;
}
 
int main(){
   aluno V[TAM];
   int i;
   float Somatorio = 0.0;
   float Media;
 
   for(i=0;i<TAM;i++){
     printf("Aluno #%d\n",i+1);
 
     printf("Digite o numero de matricula do Aluno: ");
     fgets(V[i].Matricula, 20, stdin);
 
     printf("Digite a nota da primeira prova: ");
     scanf("%f", &V[i].prova1);
 
     printf("Digite a nota da segunda prova: ");
     scanf("%f", &V[i].prova2);
 
     printf("Digite a nota do Trabalho: ");
     scanf("%f", &V[i].trabalho);
     flush_in();
 
     Somatorio += somaNotas(V[i]);
   }
 
	Media = Somatorio/TAM;
	 
	printf("A Media da sala foi de %.2f pontos. \n", Media);
	 
	return 0;
}

/* --------------------------------- RESUMO DO CÓDIGO -----------------------------------

DEFINIÇÃO:

	- O corpo da função é onde vamos processar as entradas (parametros), e gerar as saídas
	(return), é formada por declarações e comandos

	- No exemplo acima, criamos um programa que lê o número de matricula e as notas dos alunos 
	de uma turma, soma as notas individuais por meio de uma função somaNotas e por fim imprime a 
	média das notas da turma. 

	- Podemos notar que a soma das notas individuais é feita por meio de uma função criada pelo 
	usuario, não necessitando assim usar seus passos no corpo da função main.

	
---------------------------------------------------------------------------------------- */