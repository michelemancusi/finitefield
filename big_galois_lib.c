bool *big_galois_mul(bool *a, bool *b, int l, bool *poly_irr){
	
	bool **Q;
	bool *W;
	bool *T;
	int i=0,j=0, k=0, c=0, d=0,e=0,r=0;
	
	
	Q=malloc(l*sizeof(bool*)); 		
	for(i=0;i<l;i++){
		Q[i]=malloc((2*l-1)*sizeof(bool));	
	}
	
	W=malloc((2*l-1)*sizeof(bool));
	T=malloc(l*sizeof(bool));

	for(i=0;i<l;i++){
		T[i]=0;
	}

	for(i=0;i<l;i++){
		for(j=0;j<(2*l-1);j++){
			Q[i][j]=0;
		}
	}	
	
	for(i=0;i<(2*l-1);i++){
		W[i]=0;
	}
	
	for(i=0;i<l;i++){
		for(j=0;j<l;j++){
			Q[i][2*l-2-j-i]=a[l-1-i]&b[l-1-j];
		}
	}	
	
	for(j=0; j<(2*l-1); j++){
		c=0;
		for(i=0; i<l ;i++){
			c=c^Q[i][j];
		}
		W[j]=c;
	}
	
	d=0;
	e=0;
	r=0;
	
	do{
		d=0;
		e=0;	
		for(j=0; j<(2*l-1-r); j++){
			
			W[j+r]=W[j+r]^poly_irr[j];
						
			if(d==0){  							//DA MIGLIORARE
				if(W[j]==0){
					e++;
				}else{
					d++;
				}
			}else{
				}	
		}
		r=e;
	}while((2*l-1-e)>=(l+1));
	
	
	for(i=0;i<l;i++){				//CICLO DA TOGLIERE SE POSSIBILE, QUELLO CHE FA è PRENDERE L'ARRAY W CHE è LUNGO 2*l-1 E "RIMPICCIOLIRLO" FACENDOLO DIVENRTARE LUNGO l PERCHè L'ARRAY CHE RESTITUISCE LA FUNZIONE DEVE ESSERE DELLA STESSA LUNGHEZZA DEI VETTORI IN INGRESSO POICHè STIAMO IN CAMPO FINITO.
		T[l-i-1]=W[2*l-1-i-1];
	}

	
	for(i=0;i<l;i++){
		free(Q[i]);	
	}
	free(Q);
	free(W);
	
	return T;
}

bool *big_galois_pow(bool *x, int n, int l, bool *poly_irr){
    
    int i=0,k=0, j=0;
    bool *y;
   
   	y=malloc(l*sizeof(bool));
    
    for(i=0;i<(l-1);i++){
		y[i]=0;
	}
	y[l-1]=1;
	
	for(i=0;i<l;i++){
		if(x[i]!=0){
    		j++;
		}
	}
	
	if(n==0){
		return y;
	}else{
		if(n==1){
			return x;
		}else{
		
		do{
			if(n%2==0){
				x=big_galois_mul(x,x,l, poly_irr);
				n=n/2;
			}else{
				y=big_galois_mul(x,y,l, poly_irr);
				x=big_galois_mul(x,x,l, poly_irr);
				n=(n-1)/2;
			}
		}while(n>1);
		}
		
		return big_galois_mul(x,y,l, poly_irr);
	}
	
}


