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

void verifica(matclau, linha, col)
{

}

void printaLinha(v, col){

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
        if(verifica(matclau,linhas,col,v) == 1){ //verifica se clausula da 1
            printf("valida");
            for(j=VAR-1; j>=0; j--) {
                printf("%d ", v[j]);
            }
            printaLinha(v,col);
        }
        printf("\n");
        proximo(v, VAR);
    }
}

void automatico() {


}

void manual() {


}

int main() {
    automatico();
    percorrer(matclau,linhas,col);

    return 0;
}
