#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>


int ID = 1;

typedef struct 
{	
	int id;
    char nome[50];
    int urgencia;
    
} Pessoa;

char filaVazia(int ini){
    if (ini==-1)
        return 'S';
    else return 'N';
}

char filaCheia(int tam, int fim){
     if (fim==tam)
            return 'S';
        else return 'N';
}

void criaFila(int *ini, int *fim){
    (*ini) = -1;
    (*fim) = 0;
}

void carregaDados(Pessoa p[], int *fim){
    p[0].id = 1;
    strcpy(p[0].nome,"Aldo");
    p[0].urgencia = 2;
    p[1].id = 2;
    strcpy(p[1].nome,"Anna");
    p[1].urgencia = 1;
    p[2].id = 3;
    strcpy(p[2].nome,"Alpo");
    p[2].urgencia = 1;
    p[3].id = 4;
    strcpy(p[3].nome,"Anita");
    p[3].urgencia = 2;
    p[4].id = 5;
    strcpy(p[4].nome,"Andre");
    p[4].urgencia = 1;
    p[5].id = 6;
    strcpy(p[5].nome,"Amanda");
    p[5].urgencia = 1;
    p[6].id = 7;
    strcpy(p[6].nome,"Alberto");
    p[6].urgencia = 2;
    p[7].id = 8;
    strcpy(p[7].nome,"Adalberto");
    p[7].urgencia = 1;
    ID = 9;
    *fim = 8;
}

void exibeFilaCompleta(Pessoa p[], int fim){
    int i;
    for (i=0;i<fim;i++){
        printf("Paciente %d (id:%d): %s, urgencia ", i, p[i].id, p[i].nome);
        switch(p[i].urgencia){
        	case 1:
        		printf("A\n");
        		break;
        	case 2:
        		printf("V\n");
        		break;
		}
    }
    printf("\n");
}

void pesquisaNomePaciente(Pessoa p[], int **fim){
	char nome[20];
	bool achou = false;
	int indice;
	
	printf("\n");
	printf("Digite o nome do paciente\n");
	scanf("%s", &nome);
	
	for(int i=0;i<**fim;i++){
		
		if(strcmp(p[i].nome, nome) == 0){
			achou = true;
			indice = i;	
		}
	}
	if(achou){
		printf("Paciente %d (id:%d): %s, urgencia ", indice, p[indice].id, p[indice].nome);
        switch(p[indice].urgencia){
        	case 1:
        		printf("A\n");
        		break;
        	case 2:
        		printf("V\n");
        		break;
		}
	}else{
			printf("Nome não encontrado.\n");
		}	
}

void pesquisaFilaUrgencia(Pessoa p[], int **fim){
	int op;
	bool opC = false;
	
	printf("Digite a classificação que deseja visualizar\n");
	printf("1-Amarela 2 - Verde\n");
	
	do{
		scanf("%d", &op);
		switch(op){
			case 1:
				for(int i=0;i<**fim;i++){
					if(p[i].urgencia == 1){
						printf("Paciente %d (id:%d): %s, urgencia ", i, p[i].id, p[i].nome);
				        switch(p[i].urgencia){
				        	case 1:
				        		printf("A\n");
				        		break;
				        	case 2:
				        		printf("V\n");
				        		break;
						}
					}
				}
				opC = true;
				break;
			case 2:
				for(int i=0;i<**fim;i++){
					if(p[i].urgencia == 2){
						printf("Paciente %d (id:%d): %s, urgencia ", i, p[i].id, p[i].nome);
				        switch(p[i].urgencia){
				        	case 1:
				        		printf("A\n");
				        		break;
				        	case 2:
				        		printf("V\n");
				        		break;
						}
					}
				}
				opC = true;
				break;
			default:
				printf("Dado invalido, insirá novamente\n");
				break;
		}
	}while(!opC);
}

void exibeFila(Pessoa p[], int *fim){
	int op;
	bool opC = false;
	
	printf("1-Visualizar a fila por nome de paciente\n");
	printf("2-Visualizar a fila por urgencia\n");
	scanf("%d", &op);
	
	do{
		switch(op){
			case 1:
				pesquisaNomePaciente(p, &fim);
				opC = true;
				break;
			case 2:
				pesquisaFilaUrgencia(p, &fim);
				opC = true;
				break;
			default:
				printf("Dado invalido, insirá novamente\n");
				break;
		}
	}while(!opC);
}

void ordenaFila(Pessoa p[], int *ini, int *fim, int tam){
	Pessoa pAju;
	for(int i=0;i<*fim;i++){
		
		for(int j=0;j<*fim;j++){
			if(i > j && p[j].urgencia > p[i].urgencia){
			pAju = p[i];
			p[i] = p[j];
			p[j] = pAju;
			}
		}
	}
	for(int i=0;i<*fim;i++){
		
		for(int j=0;j<*fim;j++){
			
			if(i > j && p[i].urgencia == 1 && p[j].urgencia == 1){
				
				if(p[j].id > p[i].id){
					pAju = p[i];
					p[i] = p[j];
					p[j] = pAju;
				}
			}
		}
	}
	for(int i=0;i<*fim;i++){
		
		for(int j=0;j<*fim;j++){
			
			if(i > j && p[i].urgencia == 2 && p[j].urgencia == 2){
				
				if(p[j].id > p[i].id){
					pAju = p[i];
					p[i] = p[j];
					p[j] = pAju;
				}
			}
		}
	}
}


void insereFila(Pessoa p[], int *ini, int *fim, int tam){
    if (filaVazia((*ini)) == 'S'){
        (*ini)++;
    }
    if (filaCheia(tam,(*fim)) == 'N'){
        int op;
        bool opC = false;
        
        printf("Digite o nome do paciente:\n");
		scanf("%s", p[(*fim)].nome);
		
		printf("Grau de urgengecia: 1-Amarela 2-Verde\n");
		do{
			scanf("%d", &op);
			if(op == 1 || op == 2){
				p[(*fim)].urgencia = op;
				opC = true;
			}else{
				printf("Dado invalido, insira novamente\n");
			}
		}while(!opC);
		
		p[(*fim)].id = ID;
		ID++;
        (*fim)++;
        printf("Paciente inserido\n\n");
    }else{
        printf("Fila cheia!\n");
    }
}

void removeFila(Pessoa p[], int *ini, int *fim){
    int i;
    if (filaVazia((*ini)) == 'S'){
        printf("Fila vazia!\n");
    }else{
        (*fim)--;
        if((*fim) == 0){
            (*ini) = -1;
        }else{
            for (i=0;i<(*fim);i++){
                p[i] = p[i+1];
            }
        }
    }
}

int main(){
    int tam = 50;
    int ini, fim;
    int valor, op;
    Pessoa pes[tam];

    criaFila(&ini,&fim);
    carregaDados(pes, &fim);
    
    
    
    do{
    	printf("\n");
        printf("1 - Inserir na Fila\n");
        printf("2 - Remover da Fila\n");
        printf("3 - Buscar na Fila\n");
        printf("4 - Busca a Fila completa\n");
        printf("5 - Consultar situacao da Fila\n");
        printf("0 - Sair\n");
        printf("Informe a opcao: ");
        printf("\n");
        scanf("%d",&op);
        switch(op){
            case 1: insereFila(pes,&ini,&fim,tam);
            		ordenaFila(pes,&ini,&fim,tam);
                    break;
            case 2: removeFila(pes,&ini,&fim);
                    break;
            case 3: exibeFila(pes, &fim);
            		break;
            case 4: exibeFilaCompleta(pes,fim);
        			break;
        	case 5: printf("\nTamanho total da fila: %d\n", tam);
        			printf("Qtd posicoes ocupadas na fila: %d\n", fim);
        			printf("Qtd posicoes livres na fila: %d\n", tam - fim);
        			break;
            case 0: printf("Saindo... \n");
                    printf("\n");
                    break;
            default: printf("Opcao invalida!\n");
        }


    }while (op!=0);

    return 0;
}
