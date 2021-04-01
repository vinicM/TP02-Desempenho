#include <stdio.h>
#include <time.h>

int boolSat(int * truthValue,int (*clause)[3]);
int genCombination(int *arr,int size,int *base,int actSize, int (*clause)[3]);
void automatico();
void manual();