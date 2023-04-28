#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node{ // cria uma struct chamada Node
	int dado; // cria uma variável inteira chamada dado
	struct Node* next; // liga a struct Node o proximo elemento 
};

void insere_inicio (struct Node** inicio_ref, int new_dado){//cria a função insere_inicio da struct Node com a criação do ponteiro *inicio_ref e da variável new_dado 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // cria a variavel new_node e aloca memoria para a inserção de dados na variável new_node
	new_node->dado = new_dado; // a variável new_node aponta para a variável dado e recebe o valor de new_dado
	new_node->next = (*inicio_ref); //a variável new_node aponta para o proximo elemento e recebe o ponteiro *inicio_ref, que é um valor de memória
	(*inicio_ref) = new_node; // o ponteiro *inicio_ref recebe a variavel new_node (o ponteiro que no main aponta pata o NULL agora aponta para esse novo nó)
}

void insere_fim (struct Node** inicio_ref, int new_dado){//cria a função insere_fim da struct Node com a criação do ponteiro *inicio_ref e da variável new_dado 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // cria a variavel new_node e aloca memoria para a inserção de dados na variável new_node
	struct Node *ultimo = *inicio_ref; //cria o ponteiro *ultimo que recebe a variavel inicio_ref (que aponta para o valor inicial da lista)
	new_node->dado = new_dado; //a variável new_node aponta para o proximo elemento e recebe o ponteiro *inicio_ref, que é um valor de memória
	new_node->next = NULL; //a variável new_node aponta para NULL (pois é o fim da lista)
	if(*inicio_ref == NULL){ // se o dado que entrar já for o fim da lista
		*inicio_ref = new_node; // o dado que entrou passa a ser o novo nó da lista acima do fim da lista (NULL)
		return;
	}
	while(ultimo->next != NULL){ //enquanto o dado que entrou não for o nó de fim da lista (ou seja ele vai percorrer a lista até chegar em NULL)
		ultimo=ultimo->next; //o dado passa para o próximo nó até chegar ao fim da lista
		ultimo->next = new_node; // o nó passa a ser o novo nó acima do fim da lista
		return;
	}
}

void printList(struct Node *node){ // cria a função printList da struct Node com a criação do ponteiro *node
	while(node != NULL){ //percorre a lista que foi passada pelo parametro enquanto ela não for igual a NULL
		printf("%d ", node->dado); // o nó esta apontando para dado
		node = node->next; // percorre a lista caminhando pelo proximo elemento
	}
}






int main (){
	struct Node* inicio = NULL; //a struct Node é chamada de inicio e recebe NULL
	insere_fim(&inicio, 6); //inicia a função insere_fim e insere para a estrutura inicio o valor 6 no fim da lista
	insere_inicio(&inicio, 7); //inicia a função insere_inicio e insere para a estrutura inicio com o valor 7 para o começo da lista
	insere_inicio(&inicio, 1); //inicia a função insere_inicio e insere para a estrutura inicio com o valor 1 para o começo da lista
	insere_fim(&inicio, 4); //inicia a função insere_fim e insere para a estrutura inicio o valor 4 no fim da lista
	printf("\n Lista Criada: ");
	printList(inicio); // inicia a função printList da estrutura inicio
	return 0;
}
