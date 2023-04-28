#include <iostream>

void inserir(int a[]){	
	int i;
	for(i=0; i<3; i++){
		printf("\n Digite o valor %d \t", i);
		scanf("%d", &a[i]);
	}
}

void imprimir (int b[]){
	int i;
	for(i=0; i<3; i++){
		printf("\n numeros[%d] = %d", i, (2*b[i]));
	}
}

int main(int argc, char** argv) {	
	int numero[3];
	printf("\n Preenchendo o vetor: ");
	inserir(numero);
	printf("\n valor final: ");
	imprimir(numero);
	return 0;
}
