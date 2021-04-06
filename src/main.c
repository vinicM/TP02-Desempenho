#include "3-sat.h"

int main()
{

	escolhaMenu();
	return 0;
}

// int main()
// {
// 	int i, j, flag = 0;
// 	clock_t duration;
// 	double time_taken;
// 	scanf("%d", &numVar);
// 	scanf("%d", &numLine);
// 	int truthVal[numVar];
// 	int clause[numLine][3];

// 	for (i = 0; i < numLine; i++)
// 	{
// 		for (j = 0; j < 3; j++)
// 		{
// 			scanf("%d", &clause[i][j]);
// 		}
// 	}
// 	// Calculo do tempo
// 	duration = clock();
// 	flag = genCombination(truthVal, numVar, truthVal, numVar, clause);
// 	duration = clock() - duration;
// 	time_taken = ((double)duration) / CLOCKS_PER_SEC; // Em segundos

// 	if (flag == 0)
// 	{
// 		printf("not satisfiable\n");
// 		printf("A combinação demorou %f segundos para ser executada!!!\n", time_taken);
// 	}
// 	else
// 	{
// 		for (i = 0; i < numVar; i++)
// 		{
// 			printf("%d ", truthVal[i]);
// 		}
// 		printf("A combinação demorou %f segundos para ser executada!!!\n", time_taken);
// 	}

// 	return 0;
// }