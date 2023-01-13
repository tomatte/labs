
# Documentação do labs
Criação de dois programas: encoder e decoder, o primeiro irá comprimir um texto e o segundo irá descomprimir, ambos usarão o algorítmo de Huffman

## Encoder

### Passo 1: Ler e juntar textos a serem comprimidos
Com a função `char	*get_text(int argc, char **argv)` o encoder usa os argumentos passados pra tentar ler o texto de um arquivo, caso ele não consiga então o argumento será considerado um texto. Multiplos textos são combinados em uma string pra serem comprimidos juntos.

### Passo 2: gerar lista de frequência
A função `t_lst	*get_frequency(char *text)` irá contar e armazenar a frequência de cada caracter presente no texto.

### Passo 3: gerar lista de nós
Nesse caso um nó é um membro de uma árvore.
Cada nó aponta pra dois filhos, mas nesse caso vamos criar um vetor simples de nós que não possuem filhos.
Essa é a estrutura de um nó:
```C
typedef struct	s_tree
{
	char			c;
	int				times;
	struct s_tree	*left;
	struct s_tree	*right;
}	t_tree;
```

### Passo 4: criar árvore
A ávore é uma estrutura de dados não linear baseada em uma hierarquia de cima pra baixo. Ela é composta por nós. Cada nó pode apontar para dois filhos, um à esquerda e outro à direita. Nesse caso nós vamos criar a "árvore de Huffman" que será usada pra gerar o "código de Huffman".

Para gerar a árvore será usado o vetor de nós criado anteriormente executando o seguinte processo:
1.  Ordenar o vetor de nós pela frência e em ordem crescente.
2.  Combinar os dois primeiros nós como filhos de um novo nó que terá a frequência igual a soma da frequência de seus filhos.
3.  Adicionar o novo nó no vetor de nós e remover os seus filhos.
4.  Repetir até existir apenas um nó dentro do vetor.

Ao final desse loop sobrará apenas um nó no vetor que será o topo da nossa árvore e a partir dele é possível encontrar todos os outros nós.
