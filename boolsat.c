#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>



int numVar,numLine;

/*	This function returns true if a particular set of values of the given input variables *
 *	satisfies all the given clauses else returns false                                    */
int boolSat(int * truthValue,int (*clause)[3]){
	int i,j,val,sum;
	for(i=0;i<numLine;i++){
		sum = 0;
		for(j=0;j<3;j++){
			val = clause[i][j];
			if(val == 2){
				sum = sum + truthValue[val-1];
			}if(val == 1){
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
int genCombination(int *arr,int size,int *base,int actSize, int (*clause)[3]){
	int i,flag=0;
	if(size <= 0){
		return 0;
	}

	for(i=0;i<2;i++){
		arr[0] = i;
		flag = genCombination(arr+1,size-1,base,actSize,clause);
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

		a = getch();

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
		printf("----------------------------------------------------------\n");
		printf("----------------------------------------------------------\n");
		printf("                                                          \n");
		printf("            Escolha qual valor para N deseja  :           \n");
		printf("     1 - 15        2 - 30        3 - 36        4 - 45     \n");
		printf("                                                          \n");
		printf("----------------------------------------------------------\n");
		printf("----------------------------------------------------------\n");

		int escolha;
		escolha = getch();

		system("cls");

		if (escolha == 49){
			int N = 15 ;
			int C;
			int randomic1,test,counter = 1 ;
			int i,j,comb = 1;
			VAR = N;
			C = (N/3)*2;
			char mat[16][11];

   			for(i=0; i<C; i++){
				for(j=0; j<N; j++)
					mat[i][j] = 0;
			}

			
			
			for(i=0; i<C; i++){
				randomic1 = rand()%N;
				test = rand()%3 ;
				if(test == 0){
				 	test++;
				}
				mat[i][randomic1] = test;
		
				randomic1 = rand()%N;
				test = rand()%3 ;
				if(test == 0){
				 	test++;
				}
				mat[i][randomic1] = test;

				randomic1 = rand()%N;
				test = rand()%3 ;
				if(test == 0){
				 	test++;
				}
				mat[i][randomic1] = test;
				
			}

			for(i=0; i<C; i++){
				for(j=0; j<N; j++)
					printf("%d",mat[i][j]);
					printf("\n");
			}			
			
		} 

	
	// int i,j;
	// int flag = 0 ;
	// int numRandom;

	// scanf("%d",&numVar);
	// scanf("%d",&numLine);         //ATRIBUIR N =15/30/36/45

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

int main(){
	
	escolhaMenu();
	return 0;

}