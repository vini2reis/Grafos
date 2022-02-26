#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int mat[5][5], vet[5], i=0, j=0, k=0, cont=0, imenor=0, soma=0, p=0, x=10000;
	
	for (i=0; i<5; i++){
		for (j=0; j<5; j++){
			mat[ i ][ j ] = 0;
			vet[ i ] = 0;
		}	
	}
	mat[0][1] = -30;
	mat[0][2] = 15;
	mat[0][4] = -20;
	mat[1][0] = 30;
	mat[1][2] = -10;
	mat[1][3] = 50;
	mat[2][0] = -15;
	mat[2][1] = -10;
	mat[2][3] = -5;
	mat[2][4] = 10;
	mat[3][1] = 50;
	mat[3][2] = 5;
	mat[3][4] = 30;
	mat[4][0] = 20;
	mat[4][2] = -10;
	mat[4][3] = -30;
	
	j=0;
	vet[ 0 ] = 1;
	
	do{
		for (i=0; i<5; i++){
			if (mat[ i ][ j ] > 0 && mat[ i ][ j ] != p){
				if (mat[ i ][ j ] < x){
					x = mat[ i ][ j ];
					p = mat[ i ][ j ];
					imenor = i;
				}
			}
		}
		j = imenor;
		soma += p;
		x = 10000;
		vet[ k+1 ] = j+1;
		k++;
		cont++;
	}while (cont != 4);
	printf ("Soma: %d  ", soma);
	printf ("Caminho: ");
	for (j=0; j<5; j++){
			printf ("%d ", vet[ j ]);
	}
}