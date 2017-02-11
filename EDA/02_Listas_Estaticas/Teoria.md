# LISTA ESTATICA

## DEFINIÇÃO:

  * Uma estrutura do tipo "Lista" é uma sequência de elementos do mesmo tipo.

  * Seus elementos possuem estrutura interna abstraída, ou seja, sua complexidade
	é arbitrária, e não afeta o seu funcionamento.

  * Uma lista possui N (N>=0) elementos, se N = 0 dizemos que a lista está vazia.

  * Lista estática sequência ou Lista linear estática.

  * Tipo de lista onde o sucessor de um elemento ocupa a posição física seguinte
	do mesmo.

  * uso de array.


## APLICAÇÕES:

  * Cadastro de funcionarios.
  * Itens em estoque.
  * Cartas de baralho.
  * etc...

OPERAÇÕES BASICAS EM UMA LISTA:

  * Criação da lista.
  * Inserção de elementos.
  * Exclusão de elementos.
  * Acesso a um elemento.
  * Destruição da lista.

  * Essas operações depende do tipo de alocação de memória usada

    * Estática ou Dinâmica

## ALOCAÇÃO:

  * Estática:

    * O espaço de memória é alocado no momento da compilação

    * Exige a definição do número máximo de elementos da lista, MAX-1

    * Acesso sequêncial: elementos consecultivos na memória.

  * Dinâmica:

    * O espaço de memória é alocado em tempo de execução.

    * A lista cresce à medida que novos elementos são armazenados, e diminui a
    medida que são removidos.

    * Acesso encadeado: cada elemento pode está em uma área distinta da memória,
    para acessar um elemento tem que percorrer todos os seus antecessores na lista
    o ultimo elemento aponte para NULL.

    * A lista é formada por 2 campos em cada elemento temos o campo de dado onde
    é guardado os valores e o campo próximo que vai ser um ponteiro para o próximo
    nó da minha lista

## VANTAGENS DO USO DE ARRAY:

  * Acesso rápido e direto aos elementos(índices).

  * Tempo constante para acessar um elemento.

  * Facilidade em modificar informações

## DESVANTAGENS DO USO DE ARRAY:

  * Definição prévia do tamanho do array.

  * Dificuldade de inserir e remover um elemento entre outros dois sendo
	necessário deslocar os elementos.

## QUANDO UTILIZAR ESSA LISTA:

  * Listas pequenas.

  * Inserção e remoção apenas no final da lista.

  * Tamanho maximo bem definido.

  * A busca é a operação mais frequente.

## TIPOS DE INSERÇÃO/REMOÇÃO:

  * Podemos inserir/remover dados no inicio da lista

  * Podemos inserir/remover dados no final da lista

  * Podemos inserir/remover dados no meio da lista

  * Não se pode remover um dados de uma lista vazia
