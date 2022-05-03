#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char cartao[1];

struct fila {
	int numero;
	char cor;
	struct fila* prox;
};

void exibeFila(int fila[], int fim){
    int i;
    printf("Ini -> ");
    for(i=0;i<fim;i++){
        printf(" %d ",fila[i]);
    }
}

void addFila(int fila[], int tam, int *ini, int *fim, int valor){
	fila[(*fim)] = valor;
	(*fim)++;
    if ((*ini)==-1){
        (*ini)++;
    }

}

void remFila(int fila[], int tam, int ini, int *fim){
    if ((*fim) == 0){
        printf("Fila vazia!\n");
    }else{
    	for(int i = 0; i < *fim; i++){
    		fila[i] = fila[i+1];
		}
		*fim = *fim - 1;
    }
}

typedef struct fila Fila;
	Fila* inserir_fim(Fila* l, Fila* no) {
	Fila* aux;
	no->prox = NULL;
	aux = l;
	while (aux->prox != NULL)
	aux = aux->prox;
	aux->prox = no;
	return l;
}

Fila* inserir_prioridade(Fila* l, Fila* no){
	if (l->cartao == 'V'){
		no->prox = l;
		l = no;
	}else{
		Fila* ant = l;
		Fila* aux = ant->prox;
		while (aux != NULL && aux->cartao == 'A'){
			ant = aux;
			aux = aux->prox;
		}
		ant->prox = no;
		no->prox = aux;
	}
}*/

Fila* inserir(Fila* l, int numero, char cor) {
	Fila* no = (Fila*) malloc(sizeof(Fila));
	no->numero = numero;
	no->cor = cor;
	if (l == NULL) {
	no->prox = l;
	l = no;
	}else{
		if (no->cor == 'V'){
		l = inserir_fim(l, no);
		}else{
			l = inserir_prioridade(l, no);
		}
	}
		return l;
}
*/
int main(){
    int tam = 50;
    int fila[50]; 
    int ini = -1;
    int fim = 0;
    int op, valor;
    
    do{
    	printf("---- Digite a opcao desejada ----\n\n");
    	printf("1- Cadastrar paciente na fila\n");
    	printf("2- Remover paciente da fila\n");
    	printf("3- Pesquisar posicao paciente da fila\n");
    	printf("4- Visualizar fila completa\n");
    	printf("5- Visualizar fila por urgencia\n");
		printf("9-Sair\n");
		printf("Informe uma das opcoes\n");
		scanf("%d",&op);   
		
		switch(op){
		case 1:
			if(tam == fim){
				printf("Fila cheia");
			}else{
				printf("Digite o valor a ser adicionado a fila:\n");
				scanf("%d",&valor);
				addFila(fila, tam, &ini, &fim, valor);
				exibeFila(fila,fim);
			}
			break;
		case 2:
			remFila(fila,tam,ini,&fim);
			exibeFila(fila,fim);
			break;
		case 3:
			break;
		case 4: 
			break;
		case 5:
			break;
		case 9:
			printf("Saindo\n");
			break;
		default: printf("Opcao incorreta!\n");
		}	
	}while(op != 9);
    
    return 0;
}
