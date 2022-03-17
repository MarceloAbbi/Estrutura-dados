/*Faça um programa em C que leia dois vetores, denominados A e B, de 5 elementos cada um, respeitando as seguintes regras:
Vetor A deve conter apenas valores positivos entre 10 e 30, incluindo os limites
Vetor B deve conter apenas valores negativos entre -5 e 5, incluindo os limites
A partir dos dois vetores, crie uma matriz que:
Na primeira linha armazene o vetor A;
Na segunda linha armazene o vetor B;
Na terceira linha, contenha para cada coluna o dobro da soma dos elementos da primeira e da segunda linha correspondentes à mesma coluna;
Exiba a matriz resultante organizada em linhas e colunas.
*/


#include <stdio.h>
#include <stdlib.h>

int A[5], i, j, B[5], mat[3][5];
int main(){
 	printf("Informe valores para o conjunto A:\n");
  	for(i=0;i<=4;i++){
	    do{
	      printf("informe um valor da posicao %d entre 10 e 30: ", i+1);
	      scanf("%d", &A[i]);
	    }while((A[i]<10)||(A[i]>30));
	}
    printf("Informe valores para o conjunto B:\n");
	for(i=0;i<=4;i++){
	    do{
	      printf("Informe um valor negativo para a posicao %d entre -5 e 5: ", i+1);
	      scanf("%d", &B[i]);
	    }while((B[i]<-5)||(B[i]>=0));
	}

//armazenando A e B na Matriz...
	
	for(i=0;i<=4;i++){
		mat[0][i] = A[i];
		mat[0][i] = B[i];
	}
	
//criando os valores da terceira coluna
	for(i=0;i<=4;i++){
		mat[2][i] = 2 * (A[i] + B[i]); // 2 * (mat[0][i] + mat[1][i]);
	}
//exibir
	for(i=0;i<=2;i++){ //Linha
		for(j=0;j<=4;j++){//coluna
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
  return 0;
}

