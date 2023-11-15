// reconocedor.h

#ifndef __RECONOCEDOR_H__
#define __RECONOCEDOR_H__

#define TAMANIO_MAXIMO_DE_EXPRESION 80

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

// Autómatas

bool reconocer_expresion_afd(char*);
void reconocer_tokens_afd(char*);
int automata_constante(char*);
int automata_operador(char*);
bool automata_expresion(char*);
char* truncar_expresion(char*, int);
int posicion_simbolo(char, const char*, int);
bool es_final(int);

// Autómata de expresiones

static const int transiciones_expresion[6][17] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 5, 5, 1, 5, 5, 2, 5, 5 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 5, 5, 5 },
    { 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 3, 5, 5, 5, 5, 5 },
    { 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 2, 2, 2, 2, 5, 4, 5 },
    { 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 5, 5, 5 }
};
static const int estados_finales_expresion[2] = { 1, 4 };
static const int cant_estados_finales_expresion = 2;
static const char simbolos_expresion[16] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '+', '-', '*', '/', '(', ')'};
static const int cant_simbolos_expresion = 16;

// Autómata de token (Constante numérica)

static const int transiciones_constante[3][11] = {
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2 },
    { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2 },
    { 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2 }
};
static const char simbolos_constante[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
static const int cant_simbolos_constante = 10;

// Autómata de token (Operador)

static const int transiciones_operador[3][7] = {
    { 1, 1, 1, 1, 1, 1, 2 },
    { 2, 2, 2, 2, 2, 2, 2 },
    { 2, 2, 2, 2, 2, 2, 2 }
};
static const char simbolos_operador[6] = {'+', '-', '*', '/', '(', ')'};
static const int cant_simbolos_operador = 6;

// En los autómatas de tokens sólo hay un estado final y un estado de error
// por lo tanto, el vector de estados finales no es necesario como en el caso 
// del autómata de expresiones


// Control de flujo (regex)



#endif