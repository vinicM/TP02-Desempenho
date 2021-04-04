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

void printaLinha(char v, int col){

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

void automatico() {


}

void manual() {


}
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
