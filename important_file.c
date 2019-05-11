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
	
