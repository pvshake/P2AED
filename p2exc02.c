#include <stdio.h>
#include <stdlib.h>

typedef struct numero Numero;
struct numero{
	int num;
	Numero *prox;
	Numero *ant;
};

Numero *prim;
Numero *ult;
int tam;

void inicializa(){
	prim = NULL;
	ult = NULL;
	tam = 0;
}

Numero *pv(int num){
	Numero *new = (Numero*) malloc(sizeof(Numero));
	new->num = num;
	new->ant = NULL;
	new->prox = NULL;

	return new;
}

void insertRight(int num){
	Numero *new = pv(num);
	
	if(prim == NULL){
		prim = new;
		ult = new;
	}	
	else{
		Numero *current;
		current = ult;
		new->ant = current;
		current->prox = new;
		ult = new;
	}
	tam++;
}

void printList(){
	Numero *current;
	current = prim;
	while(current){
		printf("%d ",current->num);
		current = current->prox;
	}
}

void crescente(){
    Numero *celula = NULL, *aux = NULL;
    int variavelaux;
    celula = prim;
    
    while(celula != NULL){
        aux=celula; 
        while (aux->prox != NULL){
           if(aux->num > aux->prox->num){
              variavelaux = aux->num;
              aux->num = aux->prox->num;
              aux->prox->num = variavelaux;
            }
         aux = aux->prox;
        }
        celula = celula->prox;
    }
}

void maiorNum(){
	Numero *current;
	current = prim;
	
	int maior = 0;
	
	while(current){
		if(maior < current->num)
			maior = current->num;
	    
	    current = current->prox;
	}
	printf("%d\n",maior);
}

void menorNum(){
	Numero *current;
	current = prim;
	
	int menor = 999999;
	
	while(current){
		if(menor > current->num)
			menor = current->num;
	    
	    current = current->prox;
	}
	printf("%d\n",menor);
}

void printInvertido(){
	Numero *current;
	current = ult;
	while(current){
		printf("%d ",current->num);
		current = current->ant;
	}
}

int main(){
	inicializa();
	int i=0;
	char op;
	
	while(i != -1){
	    scanf("%d", &i);

	    if(i == -1)
	        break;
	    
	    insertRight(i);
	}
	
	scanf(" %c", &op);
	
	if(op == 'C' || op == 'c'){
	    crescente();
	    printList();   
	}
	else if(op == 'D' || op == 'd'){
	    crescente();
	    printInvertido();
	}
	else if(op == 'M')
	    maiorNum();
	    
	else if(op == 'm')
	    menorNum();
}