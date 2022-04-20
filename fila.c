#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


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

int main(){
    int tam = 3;
    int fila[10]; 
    int ini = -1;
    int fim = 0;
    int op, valor;
    
    
    do{
    	printf("\n\n");
    	printf("----------------------------------------------\n");
    	printf("1-Adicionar valor a fila\n");
    	printf("2-Remover valor da fila\n");
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
		case 9:
			printf("Saindo\n");
			break;
		default: printf("Opcao incorreta!\n");
		}	
	}while(op != 9);
    
    return 0;
}
