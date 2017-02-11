# Lista dinamica duplamente encadeada

## Definição

* Tipo de lista onde cada elemento aponta para o seu sucessor e antecessor na lista

* Usa um ponteiro especial para o primeiro elemento da lista e uma indicação de final de lista, nos dois sentidos

* Cada elemento é tratado como um ponteiro que é alocado dinamicamente, a medida que os dados são inseridos.

* Para guardar o primeiro elemento, utilizamos um ponteiro para ponteiro

* Um ponteiro para ponteiro pode guarda um endereço de um ponteiro

* Assim, fica fácil mudar quem está no inicio da lista mudando o conteúdo do ponteiro para ponteiro

## Vantagens

* Melhor utilização dos recursos de memoria

* Não precisa movimentar os elementos nas operações de inserção e remoção

## Desvantagens

* Acesso indireto aos elementos

* Necessidade de percorrer a lista para acessar um elemento

## Quando utilizar a lista

* Não há necessidade de garantir um espaço mínimo de execução do aplicativo

* Inserção/Remoção em lista ordenada são as operações mais frequentes.

* Necessita de acessar informações de um elemento antecessor.
