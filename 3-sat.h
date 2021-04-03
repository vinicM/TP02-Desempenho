#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int numVar, numLine;

void proximo(char *v, int VAR);
void percorrer(int VAR);
int verifica(char** mat,int linha, int col, char* clause);
void printaLinha(char v, int col);
void automatic();
void manual();

void semPreconceito();
