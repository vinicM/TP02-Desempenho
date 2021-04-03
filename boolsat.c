#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>



int numVar,numLine;

/*	This function returns true if a particular set of values of the given input variables *
 *	satisfies all the given clauses else returns false                                    */
int boolSat(int* truthValue,int (*clause)[3]){
	int i,j,val,sum;
	for(i=0;i<numLine;i++){
		sum = 0;
		for(j=0;j<3;j++){
			val = clause[i][j];
			if(val > 0){
				sum = sum + truthValue[val-1];
			}else{
				sum = sum + (1 - truthValue[(-1*val)-1]);
			}
		}
		if(sum == 0){	// No need to check other clauses if one of the clause
			return 0;	// is not satifiable for a particular set of values
		}
	}
	return 1;
}

//	This function generates the boolean truth table for the given set of input variables
int genCombination(int *arr,int size,int *base, int (*clause)[3]){
	int i,flag=0;
	if(size <= 0){
		return 0;
	}

	for(i=0;i<11;i++){
		arr[0] = i;
		flag = genCombination(arr+1,size-1,base,clause);
		if(flag==1){
			return flag;
		}else if(size==1){				// Size 1 indicates we have reached last element of array
			flag = boolSat(base,clause);// and hence have generated a particular set of values
			if(flag==1){
				return flag;
			}
		}
	}
	return flag;
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

		a = getchar();

			if(a == 27){
				//system("cls");
				break;
			}else if(a == 49){
				//system("cls");	
								      
			}else if(a == 50){
				//system("cls");
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
		scanf("%d", &escolha);

		//system("cls");

		if (escolha == 1){
			int N = 15 ;
			int C;
			int randomic1,randomic2,randomic3,test1,test2,test3,counter = 1 ;
			int i,j,comb = 1;
			VAR = N;
			C = (N/3)*2;
			char mat[11][16];

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
			 for(i=0; i<C; i++){
			 	for(j=0; j<N; j++){
			 		printf("%d",mat[i][j]);
					
			 	}printf("\n");
			 }		
			
			int flag =0;
			int numVar = N, numLine = 10;
			
			int truthVal[11];
			int colum = 0;

			//printa tabela de clauses
			for(i=0; i<C; i++){
				for(j=0; j<3; j++){
					
					printf("%d",clause[i][j]);
					
				}printf("\n");
			}	
			
			flag = genCombination(truthVal,numVar,truthVal,clause);	
			
			if(flag==0){
				printf("not satisfiable\n");
			}else{
				for(i=0;i<numVar;i++){
				printf("%d ",truthVal[i]);
				}
				printf("\n");
			}
		} 


}

int main(){
	
	escolhaMenu();
	return 0;

}