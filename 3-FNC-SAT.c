#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void semPreconceito()
{
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif

	#ifdef _WIN32
		getch();
	#elif __linux__
		getchar();
	#endif
}

void geraclauses(int (*mat)[50],int N){
			int C;
			int randomic1,randomic2,randomic3,test1,test2,test3;
			int i,j;
			C = (N/3)*2;

   			for(i=0; i<C; i++){
				for(j=0; j<N; j++)
					mat[i][j] = 0;
			}

			srand(time(0));
			for(i=0; i<C; i++){
				int test1 = 0;
				int test2 = 0;
				int test3 = 0;


				randomic1 = rand()%N;
				test1 = rand()%3 ;
				if(test1 == 0){
				 	test1++;
				}
				mat[i][randomic1] = test1;
				
				
				
				randomic2 = rand()%N;
				
				test2 = rand()%3 ;
				
				if(test2 == 0){
				 	test2++;
				}
				while(randomic2 == randomic1){
					randomic2 = rand()%N;
				}

				mat[i][randomic2] = test2;
			
				
				
				randomic3 = rand()%N;
				
				test3 = rand()%3 ;
				if(test3 == 0){
				 	test3++;
				}

				while(randomic3 == randomic2 || randomic3 == randomic1){
					randomic3 = rand()%N;
				}
				mat[i][randomic3] = test3;
				
			}
			percorrer(mat,N,2,N,C);
			//printa tabela geral
			// for(i=0; i<C; i++){
			// 	for(j=0; j<N; j++){
			// 		printf("%d",mat[i][j]);
					
			// 	}printf("\n");
			// }
			
}

void proximo(char *v, int VAR, int VL) {
    int i;
    v[0]++;
    for(i=0; i<VAR; i++) {
        if(v[i] == VL) {
            v[i] = 0;
            v[i+1]++;
        }
    }
}

void printalinha(int* v, int colums){

	int i,j;
	int coluna1, coluna2, coluna3;
	
	for(i = 0; i<colums ; i++){
		printf("%d",v[i]);
	}
}

int verifica(char** mat, int linha, int col, char* clause){
	int i, j, aux = 0;
    int flag = 0;
    for (i = 0; i < linha; i++)
    {
        for (j = 0; j < col; j++)
        {    
            if (mat[i][j] != 0)
            {
                clause[aux] = mat[i][j];
                aux++;
            }
        }
    }
    for (i = 0; i < aux; i++)
    {
        if (clause[i] == 2)
        {
            flag = 1;
        }
    }
    return flag;
}

int percorrer(int (*mat)[50], int VAR, int VL, int N, int C) {
    char v[101];
    for(int i=0; i<VAR; i++) v[i] = 0;
    int i, j, k, l, comb=1;
    for(int i=0; i<VAR; i++) comb *= VL;
	int col;

	// printf(" TABELA ORIGINAL: \n");
	// for(i=0; i<C; i++){
	// 	printf("(");
	// 	col = 0;
	// 	for(j=0; j<N; j++){
	// 		if(mat[i][j] != 0){
	// 			printf(" %sx%d %s", (mat[i][j] == 1 ? "!" : ""),(j+1),(col < 2 ? "|" : ")"));
	// 			col++;
	// 		}	
	// 	}
	// 	printf("\n");
	// }


	printf("TABELA DAS COMBINACOES:\n");
    for(i=0; i<comb; i++) {
		for(k = 0; k<C; k++){
			for(j=VAR-1; j>=0; j--) {
				if(mat[k][j] != 0){
					if(v[j]==0){
						printf("%s %sx%d %s",(col == 0 ? "(" : ""),(mat[k][j] == 2 ? "!" : ""),(j+1),(col < 2 ? "|" : ")"));
						col++;
					}else{
						printf(" %sx%d %s", (mat[k][j] == 2 ? "!" : ""),(j+1),(col < 2 ? "|" : ")"));
						col++;
					}
				}
        	}
         
        	printf("\n");
        	proximo(v, VAR, VL);
		}
	}

	// for(k=0; k<C; k++){
	// 			printf("(");
	// 			col = 0;
	// 			for(l=0; l<N; l++){
	// 				if(mat[k][l] != 0){
	// 					if(v[j]==0){
	// 						printf(" %sx%d %s", (mat[k][l] == 2 ? "!" : ""),(l+1),(col < 2 ? "|" : ")"));
	// 						col++;
	// 					}else{
	// 						printf(" %sx%d %s", (mat[k][l] == 2 ? "!" : ""),(l+1),(col < 2 ? "|" : ")"));
	// 						col++;
	// 					}
	// 				}	
	// 			}printf("\n");
	// 		}

}

void escolhaMenu(){
	int a;
	while(1){
		printf("----------------------------------------------------------\n");
		printf("----------------------------------------------------------\n");
		printf("                                                          \n");
		printf("            Escolha o tipo de entrada desejado:           \n");
		printf("            1 - Manual        2 - Automatico              \n");
		printf("                                                          \n");
		printf("----------------------------------------------------------\n");
		printf("----------------------------------------------------------\n");

		a = getch();
		//a = getchar();

			if(a == 27){
				semPreconceito();
				break;
			}else if(a == 49){
				semPreconceito();	
								      
			}else if(a == 50){
				semPreconceito();
				menuAutomatic();
				break;
			}
	}

}

void menuManual(){

    

}


void menuAutomatic(){
		int VAR, VL = 2;
		int clause[101][3];

		printf("----------------------------------------------------------\n");
		printf("----------------------------------------------------------\n");
		printf("                                                          \n");
		printf("            Escolha qual valor para N deseja  :           \n");
		printf("     1 - 15        2 - 20        3 - 30        4 - 40     \n");
		printf("                                                          \n");
		printf("----------------------------------------------------------\n");
		printf("----------------------------------------------------------\n");

		int escolha;
		//scanf("%d", &escolha);
		escolha = getch();
		//semPreconceito();

		if (escolha == 49 || escolha == 1){
			int mat[100][50];
            int N,C;
            N = 15;
            C = (N/3)*2;
            geraclauses(mat, N);
		} 
		if (escolha == 50 || escolha == 2){
			int mat[100][50];
            int N,C;
            N = 20;
            C = (N/3)*2;
            geraclauses(mat, N);
		}
		

}

int main(){
	
	escolhaMenu();
	return 0;

}