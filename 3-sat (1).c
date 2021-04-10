#include <stdio.h>

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

void percorrer(int VAR, int VL) {
    char v[101];
    int mat[101][50];
    for(int i=0; i<VAR; i++) v[i] = 0;
    int i, j, comb=1;
    for(int i=0; i<VAR; i++) comb *= VL;

    int N = VAR;

    for(int i=0; i<comb; i++){
        for(int j=0; j<VAR; j++){
            mat[i][j] = 0;
        }
    }
    printf("\n");
    
    // int nega=1, negb=2;
    // printf("(%sa | %sb)\n", (nega == 1 ? "!" : ""), (negb == 1 ? "!" : ""));

    for(i=0; i<comb; i++) {
        for(j=VAR-1; j>=0; j--) {
            mat[i][j] =  v[j];
        }
        // adicionar o resto das verificações
        proximo(v, VAR, VL);
    }

    for(int i=0; i<comb; i++){
        for(j=VAR-1; j>=0; j--){
            printf("%d ",mat[i][j]);
        }printf("\n");
    }
}

void automatico() {


}

void manual() {


}

int main() {
    percorrer(6, 2);

    return 0;
}