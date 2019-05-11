#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include <string.h>
#include "big_galois_lib.c"

int main(){
FILE *file3;
	file3 = fopen("polinomi_irriducibili.txt", "r");
	int i;
	int j;
	int l;
	bool **poly_irr;
	
	poly_irr=(bool**)malloc(100*sizeof(bool*));
	for(i=0;i<100;i++){
		poly_irr[i]=malloc(100*sizeof(bool));	
	}
	
	for(i=0; i<100;i++){
		for(j=0;j<100;j++){
			 fscanf(file3, "%1d", &poly_irr[i][j]);
		}
	}
	
bool * a; 
bool  *b; 
bool * c; 
a = malloc(l * sizeof(bool));
a = big_galois_mul(b,c, l, poly_irr[l]);
}
