/*
Estudo Dirigido Estrutura de Dados
Nomes: Marcelo dos Santos Abbi , Filipe Rodrigues
*/



#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>

struct CursoEstatistica{
    char nome[10]; //guarda o nome do curso
    int maiorAltura;    //guarda a maior altura entre os pesquisados do curso
    int menorAltura;    //guarda a menor altura entre os pesquisados do curso
    float mediaAlturas; //guarda a media das alturas entre os pesquisados do curso
    int totPesquisados; //guarda o total de pesquisados no curso

};

typedef struct CursoEstatistica Curso;

void inicializaCursos(Curso curso[]){
    int i;
    strcpy(curso[0].nome,"ADS");
    strcpy(curso[1].nome,"CICO");
    strcpy(curso[2].nome,"SI");
    strcpy(curso[3].nome,"JOGOS");
    for(i=0;i<4;i++){
        curso[i].maiorAltura = 0;
        curso[i].menorAltura = 0;
        curso[i].mediaAlturas = 0.0;
        curso[i].totPesquisados = 0;
    }
}

void menu(Curso curso[],int vetAlturas1[],int vetAlturas2[],int vetAlturas3[],int vetAlturas4[],int vetPos1,int vetPos2,int vetPos3,int vetPos4){
    //declaracoes das variaveis utilizadas na function
    int op = 0;
    bool sair = false;

    do{
        system("cls");
        printf("-----------------PROG_PESQ_ALT-----------------\n");
        printf("1 - Realizar uma pesquisa\n");
        printf("2 - Ver estatisticas atuais da pesquisa\n");
        printf("0 - Sair do programa\n");
        scanf("%d",&op);
        switch(op){
            case 0: system("cls");
                    sair = true;
                    break;
            case 1: system("cls");
                    realizaPesquisa(curso,vetAlturas1,vetAlturas2,vetAlturas3,vetAlturas4,&vetPos1,&vetPos2,&vetPos3,&vetPos4);
                    break;
            case 2: system("cls");
                    exibeEstatisticas(curso);
                    break;
            default: printf("Opcao invalida\n");
        }
    }while(!sair);
    printf("Saindo...");
}

void realizaPesquisa(Curso curso[],int alt1[],int alt2[],int alt3[],int alt4[],int *vetPos1,int *vetPos2,int *vetPos3,int *vetPos4){
    //declaracoes das variaveis utilizadas na function
    int op = 0;
    int altura = 0;
    int altMax = 0;
    int altMin = 0;
    float somaAlt = 0;

    printf("Digite o codigo do seu curso\n");

    //exibe todos os cursos e incrementa o id do curso com +1 para uma melhor visualizacao
    for(int i = 0;i<4;i++){
        printf("%d",i+1);
        printf(" - ");
        printf("%s", curso[i].nome);
        printf("\n");
    }

    //while para somente se o numero digitado for dentro do range valido
    do{
        scanf("%d",&op);
        if(op>=1 && op <= 4){
            break;
        }else{
            printf("\nCodigo digitado eh invalido, favor inserir novamente\n");
        }
    }while(true);

    //decremenda o numero da variavel op(opcao) para bater com o id do curso que havia sido incrementado
    op = op-1;

    system("cls");

    //realiza a pesquisa com o curso escolhido
    printf("A pesquisa será realizada com o curso: ");
    printf("%s",curso[op].nome);
    printf("\n\n\n");
    printf("As medidas devem ser digitadas em cm!!");
    printf("\n");
    printf("Qual sua altura?\n");

    scanf("%d",&altura);

    switch(op)
    {
    case 0:
        alt1[*vetPos1] = altura;

        curso[op].totPesquisados = curso[op].totPesquisados + 1;

        altMax = curso[op].maiorAltura;
        altMin = curso[op].menorAltura;

        if(curso[op].maiorAltura == 0 || curso[op].menorAltura == 0){
            curso[op].maiorAltura = altura;
            curso[op].menorAltura = altura;
        }else{
           if(altura > altMax){
                curso[op].maiorAltura = altura;
            }
            if(altura < altMin){
                curso[op].menorAltura = altura;
            }
        }

        for(int i=0;i<=*vetPos1;i++){
            somaAlt = somaAlt + alt1[i];
        }

        curso[op].mediaAlturas = (float)(somaAlt / curso[op].totPesquisados);

        *vetPos1 = *vetPos1 + 1;
        break;
    case 1:
        alt2[*vetPos2] = altura;

        curso[op].totPesquisados = curso[op].totPesquisados + 1;

        altMax = curso[op].maiorAltura;
        altMin = curso[op].menorAltura;

        if(curso[op].maiorAltura == 0 || curso[op].menorAltura == 0){
            curso[op].maiorAltura = altura;
            curso[op].menorAltura = altura;
        }else{
           if(altura > altMax){
                curso[op].maiorAltura = altura;
            }
            if(altura < altMin){
                curso[op].menorAltura = altura;
            }
        }

        for(int i=0;i<=*vetPos2;i++){
            somaAlt = somaAlt + alt2[i];
        }

        curso[op].mediaAlturas = (float)(somaAlt / curso[op].totPesquisados);

        *vetPos2 = *vetPos2 + 1;
        break;
    case 2:
        alt3[*vetPos3] = altura;

        curso[op].totPesquisados = curso[op].totPesquisados + 1;

        altMax = curso[op].maiorAltura;
        altMin = curso[op].menorAltura;

        if(curso[op].maiorAltura == 0 || curso[op].menorAltura == 0){
            curso[op].maiorAltura = altura;
            curso[op].menorAltura = altura;
        }else{
           if(altura > altMax){
                curso[op].maiorAltura = altura;
            }
            if(altura < altMin){
                curso[op].menorAltura = altura;
            }
        }

        for(int i=0;i<=*vetPos3;i++){
            somaAlt = somaAlt + alt3[i];
        }

        curso[op].mediaAlturas = (float)(somaAlt / curso[op].totPesquisados);

        *vetPos3 = *vetPos3 + 1;
        break;
    case 3:
        alt4[*vetPos4] = altura;

        curso[op].totPesquisados = curso[op].totPesquisados + 1;

        altMax = curso[op].maiorAltura;
        altMin = curso[op].menorAltura;

        if(curso[op].maiorAltura == 0 || curso[op].menorAltura == 0){
            curso[op].maiorAltura = altura;
            curso[op].menorAltura = altura;
        }else{
           if(altura > altMax){
                curso[op].maiorAltura = altura;
            }
            if(altura < altMin){
                curso[op].menorAltura = altura;
            }
        }

        for(int i=0;i<=*vetPos4;i++){
            somaAlt = somaAlt + alt4[i];
        }

        curso[op].mediaAlturas = (float)(somaAlt / curso[op].totPesquisados);

        *vetPos4 = *vetPos4 + 1;
        break;
    }
}


void exibeEstatisticas(Curso curso[]){
    int op = 0;
    bool sair;
    int i;
    printf("\t\t");
    for (i=0;i<4;i++){
            printf("%s\t",curso[i].nome);
    }
    printf("\n");
    printf("\t\t");
    for (i=0;i<4;i++){
            printf("%d\t",curso[i].maiorAltura);
    }
     printf("\t-> Maior Altura\n");
    printf("\t\t");
    for (i=0;i<4;i++){
            printf("%d\t",curso[i].menorAltura);
    }
    printf("\t-> Menor Altura\n");
    printf("\t\t");
    for (i=0;i<4;i++){
            printf("%.2f\t",curso[i].mediaAlturas);
    }
    printf("\t-> Media das Alturas\n");
    printf("\t\t");
    for (i=0;i<4;i++){
            printf("%d\t",curso[i].totPesquisados);
    }
    printf("\t-> Total Pesquisados\n");

    printf("\n\n\n");
    printf("1 - Voltar para o menu\n");

    do{
        scanf("%d",&op);
        printf("\n");
        switch(op){
        case 1: sair = true;
        break;
        default:printf("Opcao invalida, tente novamente\n");
        break;
        }
    }while(!sair);
}
int main(){
    int vetAlturas1[20];
    int vetAlturas2[20];
    int vetAlturas3[20];
    int vetAlturas4[20];
    int vetPos1 = 0;
    int vetPos2 = 0;
    int vetPos3 = 0;
    int vetPos4 = 0;

    Curso curso[4];
    inicializaCursos(curso);
    menu(curso,vetAlturas1,vetAlturas2,vetAlturas3,vetAlturas4,vetPos1,vetPos2,vetPos3,vetPos4);
    return 0;
}
