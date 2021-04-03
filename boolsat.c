#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int numVar,numLine;

void comb(int *arr, size_t n, size_t index) {
    size_t k;
    if (index == n) {
        /* array vazio, imprime o que está "para trás" */
        printf("%d", arr[0]);
        for (k = 1; k < n; k++) printf(" %d", arr[k]);
        puts("");
        return;
    }
    for (k = index; k < n; k++) {
        int tmp;
        /* mete cada um dos elementos ao principio */
        tmp = arr[k];
        arr[k] = arr[index];
        arr[index] = tmp;

        /* recursividade! */
        comb(arr, n, index + 1);

        /* repoe posicao inicial */
        tmp = arr[k];
        arr[k] = arr[index];
        arr[index] = tmp;
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

	// int i,j,flag=0;
	// int numRandom;
	// scanf("%d",&numVar);
	// scanf("%d",&numLine);
	// int truthVal[101];
	// int clause[101][3];

	// for(i=0;i<numLine;i++){
	// 	for(j=0;j<3;j++){
	// 		srand(time(NULL));
	// 		numRandom = 1 + rand() % (2-1);
	// 		printf("%d\n", numRandom);
	// 		clause[i][j] = numRandom;
	// 	}
	// }

	// flag = genCombination(truthVal,numVar,truthVal,numVar,clause);

	// if(flag==0){
	// 	printf("not satisfiable\n");
	// }else{
	// 	for(i=0;i<numVar;i++){
	// 		printf("%d ",truthVal[i]);
	// 	}
	// 	printf("\n");
	// }

	// return 0;

}


void menuAutomatic(){
		int VAR, VL = 2;
		int clause[10][3];

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
			int N = 15 ;
			int C;
			int randomic1,randomic2,randomic3,test1,test2,test3,counter = 1 ;
			int i,j;
			VAR = N;
			C = (N/3)*2;
			int mat[10][15];

   			for(i=0; i<C; i++){
				for(j=0; j<N; j++)
					mat[i][j] = 0;
			}

			srand(time(0));
			for(i=0; i<C; i++){
				int colum1 = 0;
				int colum2 = 0;
				int colum3 = 0;
				int test1 = 0;
				int test2 = 0;
				int test3 = 0;


				randomic1 = rand()%N;
				test1 = rand()%3 ;
				if(test1 == 0){
				 	test1++;
				}
				mat[i][randomic1] = test1;
				
				colum1 = randomic1;
				
				randomic2 = rand()%N;
				
				test2 = rand()%3 ;
				
				if(test2 == 0){
				 	test2++;
				}
				while(randomic2 == randomic1){
					randomic2 = rand()%N;
				}

				mat[i][randomic2] = test2;
				colum2 = randomic2;
				
				
				randomic3 = rand()%N;
				
				test3 = rand()%3 ;
				if(test3 == 0){
				 	test3++;
				}

				while(randomic3 == randomic2 || randomic3 == randomic1){
					randomic3 = rand()%N;
				}
				mat[i][randomic3] = test3;
				colum3 = randomic3;
				
				if(colum1<colum2 && colum2<colum3){
					clause[i][0] = test1;
					clause[i][1] = test2;
					clause[i][2] = test3;
				}if(colum1<colum3 && colum3<colum2){
					clause[i][0] = test1;
					clause[i][1] = test3;
					clause[i][2] = test2;
				}if(colum2<colum1 && colum1<colum3){
					clause[i][0] = test2;
					clause[i][1] = test1;
					clause[i][2] = test3;
				}if(colum2<colum3 && colum3<colum1){
					clause[i][0] = test2;
					clause[i][1] = test3;
					clause[i][2] = test1;
				}if(colum3<colum2 && colum2<colum1){
					clause[i][0] = test3;
					clause[i][1] = test2;
					clause[i][2] = test1;
				}if(colum3<colum1 && colum1<colum2){
					clause[i][0] = test3;
					clause[i][1] = test1;
					clause[i][2] = test2;
				}
				
			}
			//printa tabela geral
			// for(i=0; i<C; i++){
			// 	for(j=0; j<N; j++){
			// 		printf("%d",mat[i][j]);
					
			// 	}printf("\n");
			// }		
			

			//printa tabela de clauses
			// for(i=0; i<C; i++){
			// 	for(j=0; j<3; j++){
					
			// 		printf("%d",clause[i][j]);
					
			// 	}printf("\n");
			// }	
			for(i=0; i<C; i++){
				for(j=0; j<3; j++){
					
					if(j==0){
						printf("( %sa | ",(clause[i][j] == 1 ? "!" : ""));
					}if(j==1){
						printf("%sb | ",(clause[i][j] == 1 ? "!" : ""));
					}if(j==2){
						printf("%sc )",(clause[i][j] == 1 ? "!" : ""));
					}
					
				}if(i!=(C-1))
					printf(" & ");
			}
			
			// for(int i=0; i<C; i++){
        	// 	comb(clause[i], sizeof clause[i] / sizeof *clause[i], 0);
				
			// }


		} 
		if (escolha == 50){
			int N = 30 ;
			int C;
			int randomic1,randomic2,randomic3,test1,test2,test3,counter = 1 ;
			int i,j;
			VAR = N;
			C = (N/3)*2;
			
			int mat[20][30];

   			for(i=0; i<C; i++){
				for(j=0; j<N; j++)
					mat[i][j] = 0;
			}

			//printa tabela geral
			// for(i=0; i<C; i++){
			// 	for(j=0; j<N; j++){
			// 		printf("%d",mat[i][j]);
								
			// 	}printf("\n");
			// }

			srand(time(0));
			for(i=0; i<C; i++){
				int colum1 = 0;
				int colum2 = 0;
				int colum3 = 0;
				int test1 = 0;
				int test2 = 0;
				int test3 = 0;


				randomic1 = rand()%N;
				printf("valor do randomic1: %d\n",randomic1);
				test1 = rand()%3 ;
				if(test1 == 0){
				 	test1++;
				}
				mat[i][randomic1] = test1;
				colum1 = randomic1;
				

				randomic2 = rand()%N;
				printf("valor do randomic2: %d\n",randomic2);
				test2 = rand()%3 ;
				if(test2 == 0){
				 	test2++;
				}
				while(randomic2 == randomic1){
					randomic2 = rand()%N;
				}
				mat[i][randomic2] = test2;
				colum2 = randomic2;
				
				
				randomic3 = rand()%N;
				printf("valor do randomic3: %d\n",randomic3);
				test3 = rand()%3 ;
				if(test3 == 0){
				 	test3++;
				}
				while(randomic3 == randomic2 || randomic3 == randomic1){
					randomic3 = rand()%N;
				}
				mat[i][randomic3] = test3;
				colum3 = randomic3;
				
				if(colum1<colum2 && colum2<colum3){
					clause[i][0] = test1;
					clause[i][1] = test2;
					clause[i][2] = test3;
				}if(colum1<colum3 && colum3<colum2){
					clause[i][0] = test1;
					clause[i][1] = test3;
					clause[i][2] = test2;
				}if(colum2<colum1 && colum1<colum3){
					clause[i][0] = test2;
					clause[i][1] = test1;
					clause[i][2] = test3;
				}if(colum2<colum3 && colum3<colum1){
					clause[i][0] = test2;
					clause[i][1] = test3;
					clause[i][2] = test1;
				}if(colum3<colum2 && colum2<colum1){
					clause[i][0] = test3;
					clause[i][1] = test2;
					clause[i][2] = test1;
				}if(colum3<colum1 && colum1<colum2){
					clause[i][0] = test3;
					clause[i][1] = test1;
					clause[i][2] = test2;
				}
				
			}
				

			//printa tabela de clauses
			// for(i=0; i<C; i++){
			// 	for(j=0; j<3; j++){
					
			// 		printf("%d",clause[i][j]);
					
			// 	}printf("\n");
			// }	
			
			
			// for(int i=0; i<C; i++){
        	// 	comb(clause[i], sizeof clause[i] / sizeof *clause[i], 0);
				
			// }
			// for(i=0; i<C; i++){
			// 	for(j=0; j<3; j++){
					
			// 		if(j==0){
			// 			printf("( %sa | ",(clause[i][j] == 1 ? "!" : ""));
			// 		}if(j==1){
			// 			printf("%sb | ",(clause[i][j] == 1 ? "!" : ""));
			// 		}if(j==2){
			// 			printf("%sc )",(clause[i][j] == 1 ? "!" : ""));
			// 		}
					
			// 	}if(i!=(C-1))
			// 		printf(" & ");
			// }


		}
		

}

int main(){
	
	escolhaMenu();
	return 0;

}