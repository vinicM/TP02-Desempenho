#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int numVar, numLine;

void proximo(char *v, int VAR);
void percorrer(int VAR);
int verifica(char **mat, int linha, int col, char *clause);
void printaLinha(char *v, int linha);
void combinationUtil(int *arr, int n, int r, int index, int *data, int i);
void printCombination(int *arr, int n, int r);
void atribui(int **mat, int *clause);
// Funcao que identifica o SO do computador do usuario
void semPreconceito();
