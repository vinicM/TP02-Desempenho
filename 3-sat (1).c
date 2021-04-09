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
    for(int i=0; i<VAR; i++) v[i] = 0;
    int i, j, comb=1;
    for(int i=0; i<VAR; i++) comb *= VL;

    int nega=1, negb=2;
    printf("(%sa | %sb)\n", (nega == 1 ? "!" : ""), (negb == 1 ? "!" : ""));

    for(i=0; i<comb; i++) {
        for(j=VAR-1; j>=0; j--) {
            printf("%d ", v[j]);
        }
        // adicionar o resto das verificações

        printf("\n");
        proximo(v, VAR, VL);
    }
}

void automatico() {


}

void manual() {


}

int main() {
    percorrer(15, 2);

    return 0;
}