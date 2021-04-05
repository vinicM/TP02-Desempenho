#include "3-sat.h"

void proximo(char *v, int VAR) {
    int i;
    v[0]++;
    for(i=0; i<VAR; i++) {
        if(v[i] == 2) {
            v[i] = 0;
            v[i+1]++;
        }
    }
}
// 0 0 0
// 0 0 1
// 0 1 0
// 0 1 1
// 1 0 0 
// 1 0 1
// 1 1 0
// 1 1 1
// 0 0 0

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

void printaLinha(char* v,int linha){
	int i;
	for(i =0; i <= linha; i++){
	    printf("%d",v[i]);
	}
}



void percorrer(int VAR) {
    char v[101]; /* int declarado como char para economizar espaço */
    for(int i=0; i<VAR; i++) v[i] = 0;
    int i, j;
    long long linhas=1;
    for(int i=0; i<VAR; i++) linhas *= 2;

    int nega=1, negb=2;
    printf("(%sa | %sb)\n", (nega == 1 ? "!" : ""), (negb == 1 ? "!" : ""));

    for(i=0; i<linhas; i++) {
        
        // adicionar o resto das verificações
        // if(verifica(matclau,linhas,col,v) == 1){ //verifica se clausula da 1
        //     printf("valida");
        //     for(j=VAR-1; j>=0; j--) {
        //         printf("%d ", v[j]);
        //     }
        //     printaLinha(v,col);
        // }
        printf("\n");
        proximo(v, VAR);
    }
}

// Algoritmo para a combinacao
void combinationUtil(int* arr, int n, int r, int index, int* data, int i)
{
    // Current cobination is ready, print it
    if (index == r)
    {
        for (int j=0; j<r; j++)
            printf("%d ",data[j]);
        printf("\n");
        return;
    }
 
    // When no more elements are there to put in data[]
    if (i >= n)
        return;
 
    // current is included, put next at next location
    data[index] = arr[i];
    combinationUtil(arr, n, r, index+1, data, i+1);
 
    // current is excluded, replace it with next (Note that
    // i+1 is passed, but index is not changed)
    combinationUtil(arr, n, r, index, data, i+1);
}

// The main function that prints all combinations of size r
// in arr[] of size n. This function mainly uses combinationUtil()
void printCombination(int* arr, int n, int r)
{
    // A temporary array to store all combination one by one
    int data[r];
 
    // Print all combination using temprary array 'data[]'
    combinationUtil(arr, n, r, 0, data, 0);
}
 
/* arr[]  ---> Input Array
   n      ---> Size of input array
   r      ---> Size of a combination to be printed
   index  ---> Current index in data[]
   data[] ---> Temporary array to store current combination
   i      ---> index of current element in arr[]     */

// Funcao que identifica o SO do computador do usuario
void semPreconceito()
{
    #ifdef _WIN32
        system("cls");
    #elif __linux__
        system("clear");
    #endif
}

int main() {
    automatico();
    //percorrer(matclau,linhas,col);

    return 0;
}
