#include <iostream>
#include <stdio.h>
#include <stdlib.h>

struct Node{ // cria uma struct chamada Node
	int dado; // cria uma vari�vel inteira chamada dado
	struct Node* next; // liga a struct Node o proximo elemento 
};

void insere_inicio (struct Node** inicio_ref, int new_dado){//cria a fun��o insere_inicio da struct Node com a cria��o do ponteiro *inicio_ref e da vari�vel new_dado 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // cria a variavel new_node e aloca memoria para a inser��o de dados na vari�vel new_node
	new_node->dado = new_dado; // a vari�vel new_node aponta para a vari�vel dado e recebe o valor de new_dado
	new_node->next = (*inicio_ref); //a vari�vel new_node aponta para o proximo elemento e recebe o ponteiro *inicio_ref, que � um valor de mem�ria
	(*inicio_ref) = new_node; // o ponteiro *inicio_ref recebe a variavel new_node (o ponteiro que no main aponta pata o NULL agora aponta para esse novo n�)
}

void insere_fim (struct Node** inicio_ref, int new_dado){//cria a fun��o insere_fim da struct Node com a cria��o do ponteiro *inicio_ref e da vari�vel new_dado 
	struct Node* new_node = (struct Node*)malloc(sizeof(struct Node)); // cria a variavel new_node e aloca memoria para a inser��o de dados na vari�vel new_node
	struct Node *ultimo = *inicio_ref; //cria o ponteiro *ultimo que recebe a variavel inicio_ref (que aponta para o valor inicial da lista)
	new_node->dado = new_dado; //a vari�vel new_node aponta para o proximo elemento e recebe o ponteiro *inicio_ref, que � um valor de mem�ria
	new_node->next = NULL; //a vari�vel new_node aponta para NULL (pois � o fim da lista)
	if(*inicio_ref == NULL){ // se o dado que entrar j� for o fim da lista
		*inicio_ref = new_node; // o dado que entrou passa a ser o novo n� da lista acima do fim da lista (NULL)
		return;
	}
	while(ultimo->next != NULL){ //enquanto o dado que entrou n�o for o n� de fim da lista (ou seja ele vai percorrer a lista at� chegar em NULL)
		ultimo=ultimo->next; //o dado passa para o pr�ximo n� at� chegar ao fim da lista
		ultimo->next = new_node; // o n� passa a ser o novo n� acima do fim da lista
		return;
	}
}

void printList(struct Node *node){ // cria a fun��o printList da struct Node com a cria��o do ponteiro *node
	while(node != NULL){ //percorre a lista que foi passada pelo parametro enquanto ela n�o for igual a NULL
		printf("%d ", node->dado); // o n� esta apontando para dado
		node = node->next; // percorre a lista caminhando pelo proximo elemento
	}
}






int main (){
	struct Node* inicio = NULL; //a struct Node � chamada de inicio e recebe NULL
	insere_fim(&inicio, 6); //inicia a fun��o insere_fim e insere para a estrutura inicio o valor 6 no fim da lista
	insere_inicio(&inicio, 7); //inicia a fun��o insere_inicio e insere para a estrutura inicio com o valor 7 para o come�o da lista
	insere_inicio(&inicio, 1); //inicia a fun��o insere_inicio e insere para a estrutura inicio com o valor 1 para o come�o da lista
	insere_fim(&inicio, 4); //inicia a fun��o insere_fim e insere para a estrutura inicio o valor 4 no fim da lista
	printf("\n Lista Criada: ");
	printList(inicio); // inicia a fun��o printList da estrutura inicio
	return 0;
}
