#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int mat[7][7], vet[7], i=0, j=0, k=0, imenor=0, soma=0, p=0, x=10000;
	
	for (i=0; i<7; i++){
		for (j=0; j<7; j++){
			mat[ i ][ j ] = 0;
			vet[ i ] = 0;
		}	
	}
	mat[0][1] = -2;
	mat[0][3] = -6;
	mat[0][4] = -12;
	mat[1][0] = 2;
	mat[1][2] = -1;
	mat[1][5] = -5;
	mat[2][1] = 1;
	mat[2][6] = -40;
	mat[3][0] = 6;
	mat[3][5] = -4;
	mat[4][0] = 12;
	mat[4][6] = -30;
	mat[5][1] = 5;
	mat[5][3] = 4;
	mat[5][6] = -8;
	mat[6][2] = 40;
	mat[6][4] = 30;
	mat[6][5] = 8;
	
	j=0;
	vet[ 0 ] = 1;
	
	do{
		for (i=0; i<7; i++){
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
	}while (j < 6);
	printf ("Soma: %d  ", soma);
	printf ("Caminho: ");
	for (j=0; j<7; j++){
			printf ("%d ", vet[ j ]);
	}
}