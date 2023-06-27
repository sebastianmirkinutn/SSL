// Conversion.c

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "conversion.h"

double celcius(int temp){
    return ((temp - CONVERTION_DIFF) / CONVERTION_RATIO);
}

double farenheit(int temp){
    return ((temp*CONVERTION_RATIO) + CONVERTION_DIFF);
}

void printFila(int temp1, double temp2){
    printf("%3d         %3.1f\n",temp1,temp2);
}

void printFilas(int lower, int upper, int step, double (*ptr)(int)){
    for(int i=lower;i<=upper;i+=step){
        printFila(i, ptr(i));
    }
}

void printTablaCelcius(int lower, int upper, int step){
    printf("Celcius     Farenheit\n");
    printFilas(lower,upper,step,celcius);
}

void printTablaFarenheit(int lower, int upper, int step){
    printf("\nFarenheit   Celcius\n");
    printFilas(lower,upper,step,farenheit);
}

void printTablas(int lower, int upper, int step){
    printTablaCelcius(lower,upper,step);
    printTablaFarenheit(lower,upper,step);
}

int main(int argc, char *argv[]){
    if(argc!=5)
        return 1;
    const int lower = atoi(argv[1]), upper = atoi(argv[2]), step = atoi(argv[3]);
    switch (atoi(argv[4]))
    {
    case 1:
        printTablas(lower,upper,step);
        break;
    case 2:
        printTablaCelcius(lower,upper,step);
        break;
    case 3:
        printTablaFarenheit(lower,upper,step);
    default:
        return 1;
        break;
    }
    return 0;
}