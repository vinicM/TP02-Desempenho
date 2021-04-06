#include "3-sat.h"

int numVar, numLine;

void escolhaMenu()
{
	int a;
	while (1)
	{
		printf("----------------------------------------------------------\n");
		printf("----------------------------------------------------------\n");
		printf("                                                          \n");
		printf("            Escolha o tipo de entrada desejado:           \n");
		printf("            1 - Manual        2 - Automatico              \n");
		printf("                                                          \n");
		printf("----------------------------------------------------------\n");
		printf("----------------------------------------------------------\n");

		//a = getch();
		a = getchar();

		if (a == 27)
		{
			semPreconceito();
			break;
		}
		else if (a == 49)
		{
			semPreconceito();
			break;
		}
		else if (a == 50)
		{
			semPreconceito();
			menuAutomatic();
			break;
		}
	}
}

void menuManual()
{

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

void menuAutomatic()
{
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
	scanf("%d", &escolha);
	//escolha = getch();
	semPreconceito();

	if (escolha == 49 || escolha == 1)
	{
		int N = 15;
		int C;
		int randomic1, randomic2, randomic3, test1, test2, test3;
		int i, j;
		VAR = N;
		C = (N / 3) * 2;
		int mat[C][N];

		for (i = 0; i < C; i++)
		{
			for (j = 0; j < N; j++)
				mat[i][j] = 0;
		}

		srand(time(0));
		for (i = 0; i < C; i++)
		{
			int colum1 = 0;
			int colum2 = 0;
			int colum3 = 0;
			int test1 = 0;
			int test2 = 0;
			int test3 = 0;

			randomic1 = rand() % N;
			test1 = rand() % 3;
			if (test1 == 0)
			{
				test1++;
			}
			mat[i][randomic1] = test1;

			colum1 = randomic1;

			randomic2 = rand() % N;

			test2 = rand() % 3;

			if (test2 == 0)
			{
				test2++;
			}
			while (randomic2 == randomic1)
			{
				randomic2 = rand() % N;
			}

			mat[i][randomic2] = test2;
			colum2 = randomic2;

			randomic3 = rand() % N;

			test3 = rand() % 3;
			if (test3 == 0)
			{
				test3++;
			}

			while (randomic3 == randomic2 || randomic3 == randomic1)
			{
				randomic3 = rand() % N;
			}
			mat[i][randomic3] = test3;
			colum3 = randomic3;

			if (colum1 < colum2 && colum2 < colum3)
			{
				clause[i][0] = test1;
				clause[i][1] = test2;
				clause[i][2] = test3;
			}
			if (colum1 < colum3 && colum3 < colum2)
			{
				clause[i][0] = test1;
				clause[i][1] = test3;
				clause[i][2] = test2;
			}
			if (colum2 < colum1 && colum1 < colum3)
			{
				clause[i][0] = test2;
				clause[i][1] = test1;
				clause[i][2] = test3;
			}
			if (colum2 < colum3 && colum3 < colum1)
			{
				clause[i][0] = test2;
				clause[i][1] = test3;
				clause[i][2] = test1;
			}
			if (colum3 < colum2 && colum2 < colum1)
			{
				clause[i][0] = test3;
				clause[i][1] = test2;
				clause[i][2] = test1;
			}
			if (colum3 < colum1 && colum1 < colum2)
			{
				clause[i][0] = test3;
				clause[i][1] = test1;
				clause[i][2] = test2;
			}
		}
		//printa tabela geral
		for (i = 0; i < C; i++)
		{
			for (j = 0; j < N; j++)
			{
				printf("%d", mat[i][j]);
			}
			printf("\n");
		}

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

		printCombination(clause, C, 3);
	}
	if (escolha == 3)
	{
		int N = 30;
		int C;
		int randomic1, randomic2, randomic3, test1, test2, test3;
		int i, j;
		VAR = N;
		C = (N / 3) * 2;

		int mat[C][N];

		for (i = 0; i < C; i++)
		{
			for (j = 0; j < N; j++)
				mat[i][j] = 0;
		}

		srand(time(0));
		for (i = 0; i < C; i++)
		{
			int colum1 = 0;
			int colum2 = 0;
			int colum3 = 0;
			int test1 = 0;
			int test2 = 0;
			int test3 = 0;

			randomic1 = rand() % N;

			test1 = rand() % 3;
			if (test1 == 0)
			{
				test1++;
			}
			mat[i][randomic1] = test1;
			colum1 = randomic1;

			randomic2 = rand() % N;

			test2 = rand() % 3;
			if (test2 == 0)
			{
				test2++;
			}
			while (randomic2 == randomic1)
			{
				randomic2 = rand() % N;
			}
			mat[i][randomic2] = test2;
			colum2 = randomic2;

			randomic3 = rand() % N;

			test3 = rand() % 3;
			if (test3 == 0)
			{
				test3++;
			}
			while (randomic3 == randomic2 || randomic3 == randomic1)
			{
				randomic3 = rand() % N;
			}
			mat[i][randomic3] = test3;
			colum3 = randomic3;

			if (colum1 < colum2 && colum2 < colum3)
			{
				clause[i][0] = test1;
				clause[i][1] = test2;
				clause[i][2] = test3;
			}
			if (colum1 < colum3 && colum3 < colum2)
			{
				clause[i][0] = test1;
				clause[i][1] = test3;
				clause[i][2] = test2;
			}
			if (colum2 < colum1 && colum1 < colum3)
			{
				clause[i][0] = test2;
				clause[i][1] = test1;
				clause[i][2] = test3;
			}
			if (colum2 < colum3 && colum3 < colum1)
			{
				clause[i][0] = test2;
				clause[i][1] = test3;
				clause[i][2] = test1;
			}
			if (colum3 < colum2 && colum2 < colum1)
			{
				clause[i][0] = test3;
				clause[i][1] = test2;
				clause[i][2] = test1;
			}
			if (colum3 < colum1 && colum1 < colum2)
			{
				clause[i][0] = test3;
				clause[i][1] = test1;
				clause[i][2] = test2;
			}
		}
		//printa tabela geral
		for (i = 0; i < C; i++)
		{
			for (j = 0; j < N; j++)
			{
				printf("%d", mat[i][j]);
			}
			printf("\n");
		}

		//printa tabela de clauses
		for (i = 0; i < C; i++)
		{
			for (j = 0; j < 3; j++)
			{

				printf("%d", clause[i][j]);
			}
			printf("\n");
		}

		printCombination(clause, C, 3);
	}
}
