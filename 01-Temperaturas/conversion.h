// conversion.h
#ifndef __CONVERSION_H__
#define __CONVERSION_H__


double celsius(int temp);
double farenheit(int temp);
void printFila(int temp1, double temp2);
void printFilas(int lower, int upper, int step, double (*ptr)(int));
void printTablaCelcius(int lower, int upper, int step);
void printTablaFarenheit(int lower, int upper, int step);
void printTablas(int lower, int upper, int step);

#define CONVERTION_RATIO 1.8
#define CONVERTION_DIFF 32.0

#endif
