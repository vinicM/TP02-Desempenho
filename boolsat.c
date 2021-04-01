#include<stdio.h>
#include<time.h>
#include <stdlib.h>

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

void menuAutomatic(){



}

int main(){
	int i,j,flag=0;
	int numRandom;
	scanf("%d",&numVar);
	scanf("%d",&numLine);
	int truthVal[101];
	int clause[101][3];

	for(i=0;i<numLine;i++){
		for(j=0;j<3;j++){
			srand(time(NULL));
			numRandom = 1 + rand() % (2-1);
			printf("%d\n", numRandom);
			clause[i][j] = numRandom;
		}
	}

	flag = genCombination(truthVal,numVar,truthVal,numVar,clause);

	if(flag==0){
		printf("not satisfiable\n");
	}else{
		for(i=0;i<numVar;i++){
			printf("%d ",truthVal[i]);
		}
		printf("\n");
	}

	return 0;
}