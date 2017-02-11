# Pilha Estatica e Dinamica

## Definição

* Uma estrutura do tipo Pilha é uma sequência de elementos do mesmo tipo, como as Listas e Filas.

* Seus elementos possuem estruturas internas abstraídas, ou seja, sua complexidade é arbitrária e não afeta o seu funcionamento.

* Pilha é um tipo especial de lista:

  * Inserção e exclusões de elementos ocorrem apenas no inico da pilha

## Aplicações

* Análise de uma expressão matemática

* Avaliação de expressão pós-fixa

* Converter uma expressão in-fixa para pós-fixa

* Converter um número decimal para binário

* etc..

## Operações

* Criação da pilha

* Inserção de um elemento no início da pilha

* Remoção de um elemento do início da pilha

* Acesso a um elemento do início da pilha

* Destruição da pilha

* Essas operações depende do tipo de alocação usada (estatica ou dinamica)

## Alocação Estatica

* O espaço de memória é alocado no momento da compilação

* Exige a definição do número máximo de elementos da pilha

* Acesso sequencial: elementos consecutivos na memória

* É um tipo de pilha onde o sucessor de um elemento ocupa a posição física seguinte do mesmo

* uso de arrays

* O campo quantidade nos diz o campo vago da pilha e a quantidade de elementos nela

## Alocação Dinamica

* O espaço de memória é alocado em tempo de execução

* A pilha cresce a medida que novos elementos são armazenados, e diminui a medida que elementos são removidos

* Acesso encadeado: cada elemento pode estar em uma área distinta da memória.

* Para acessar um elementos, é preciso percorrer todos os seus antecessores na pilha.

* Tipo de pilha onde cada elemento aponta para o seu sucessor na pilha

* Usa um ponteiro especial (ponteiro para ponteiro) para o primeiro elemento da pilha e uma indicação de final de pilha
