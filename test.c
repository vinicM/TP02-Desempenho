#include <stdio.h>

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
int main(void) {
    int N = 15 ;
	int C = (N/3)*2;
    int mat[10][3];
    for(int i=0; i<10; i++){
		for(int j=0; j<3; j++)
		    mat[i][j] = 0;
	}


     for(int i=0; i<10; i++){
         comb(mat[i], sizeof mat[i] / sizeof *mat[i], 0);
	 }
    
    
    return 0;
}