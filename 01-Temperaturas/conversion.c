// Conversion.c

#include <stdio.h>
#include "conversion.h"

const int lower = 0;
const int upper = 300;
const int step = 20;

double celcius(int temp){
    return ((temp - CONVERTION_DIFF) / CONVERTION_RATIO);
}

double farenheit(int temp){
    return ((temp*CONVERTION_RATIO) + CONVERTION_DIFF);
}

int main(){
    double fahr, cel;
    
    cel = lower;

    printf("Celcius     Farenheit\n");

    while(cel <= upper){
        fahr = farenheit(cel);
        printf("%3.0f          %6.1f\n",cel,fahr);
        cel += step;
    }

    fahr = lower;

    printf("\nFarenheit   Celcius\n");

    while(fahr <= upper){
        cel = celcius(fahr);
        printf("%3.0f         %6.1f\n",fahr,cel);
        fahr += step;
    }
}

