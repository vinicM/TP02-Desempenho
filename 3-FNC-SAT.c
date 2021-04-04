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
}

void geraclauses(int N){
         printf("entrei na geraclauses\n");
			int C;
			int randomic1,randomic2,randomic3,test1,test2,test3,counter = 1 ;
			int i,j;
			C = (N/3)*2;
			int mat[101][50];

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
			//printa tabela geral
			// for(i=0; i<C; i++){
			// 	for(j=0; j<N; j++){
			// 		printf("%d",mat[i][j]);
					
			// 	}printf("\n");
			// }
			
}

void proximo(char *v, int N) {
    int i;
    v[0]++;
    for(i=0; i<N; i++) {
        if(v[i] == 2) {
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
    for (i = 0; i < (aux-1); i++)
    {
        if (clause[i] == 2)
        {
            flag = 1;
        }
    }
    return flag;
}

void percorrer(int* mat, int linhas, int colums) {
    
    char v[101];
    for(int i=0; i<colums; i++) v[i] = 0;
    int i, j;
    long long int linhasdacomb = 1;
    for(int i=0; i<colums; i++) linhasdacomb *= 2;

	
    for(i=0; i<linhasdacomb; i++) {
		printf("...");
        // adicionar o resto das verificações
		//verifica se clausula da 1
        if(verifica(mat,linhas,colums,v) == 1){ 
			
            printalinha(v,colums);
        }
        //printf("\n");
        proximo(v, colums);
    }
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
				system("cls");
				break;
			}else if(a == 49){
				system("cls");	
								      
			}else if(a == 50){
				system("cls");
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
		printf("     1 - 15        2 - 30        3 - 36        4 - 45     \n");
		printf("                                                          \n");
		printf("----------------------------------------------------------\n");
		printf("----------------------------------------------------------\n");

		int escolha;
		//scanf("%d", &escolha);
		escolha = getch();
		system("cls");

		if (escolha == 49){
			int mat[101][50];
            int N,C;
            N = 15;
            C = (N/3)*2;
            geraclauses(N);
			percorrer(mat,C,N);
			
		} 
		if (escolha == 50 || escolha == 2){
			
			// 'a'+ rand%N

		}
		

}

int main(){
	
	escolhaMenu();
	return 0;

}