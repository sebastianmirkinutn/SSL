#include "reconocedor.h"

int posicion_simbolo(char c, const char* simbolos, int cant_simbolos){
    for (int i = 0; i < cant_simbolos; i++){
        if(simbolos[i] == c){       // Evaluo la posición en el vector del alfabeto para calcular el siguiente estado
            return i;
        }
    }
    return cant_simbolos; // Si no pertenece al alfabeto devuelvo la ultima posición correspondiente al estado de error
}

bool reconocer_expresion_afd(char* expresion){
    return automata_expresion(expresion);
}

void reconocer_tokens_afd(char* expresion){
    int pos = 0, pos_previa = 0;    
    while(expresion[pos]!='\n' && expresion[pos]!='\0'){
        pos_previa = pos;
        pos += automata_constante(truncar_expresion(expresion, pos));    // A medida que voy reconociendo los tokens
        pos += automata_operador(truncar_expresion(expresion, pos));     // los retiro de la expresión
        if(pos == pos_previa){                                           // Si no encuentro tokens es por que el caracter es inválido
            printf("Caracter no reconocido en la posicion: %d\n", pos);
            pos++;
        }
            
    }
}

char* truncar_expresion(char* expresion, int pos) {
    expresion += pos;
    return expresion;
}

int automata_operador(char* expresion){ // En este caso, al no ser recursivo y las palabras del lenguaje sólo tienen un caracter, necesito reconocer únicamente el primer caracter de la expresión truncada
    int estado = transiciones_operador[0][posicion_simbolo(expresion[0], simbolos_operador, cant_simbolos_operador)];
    if(estado != 2){ // Si no es estado de error, lo considero como token
        printf("Operador\n");
        return 1; // Devuelvo la siguiente posición ya que este token solo ocupa un caracter
    }
    else
        return 0;
        
}

int automata_constante(char* expresion){
    bool match = false; // Utilizo como flag para saber si encontró al menos un caracter
    int estado = 0; // Estado inicial
    int pos; // Posición en el string
    for(pos = 0; pos < strlen(expresion); pos++){
        if(!isspace(expresion[pos])) // No considero cambios de estado por espacios en blanco
            estado = transiciones_constante[estado][posicion_simbolo(expresion[pos], simbolos_constante, cant_simbolos_constante)];// Actualizo el estado con la tabla de transiciones
        if(estado == 2){ // En el caso de ser estado de error salgo del ciclo repetitivo
            break;
        }
        else
            match = true; // Si encontró al menos un caracter numérico lo considero como token
    }
    if(match)
        printf("Constante numerica\n");
    return pos--; // Devuelvo la posición donde quedó
}

bool automata_expresion(char* expresion){

    int estado = 0;
    for(int i=0; i < (strlen(expresion))-1; i++){
        if(!isspace(expresion[i]) && estado != 5) // No considero cambios de estado por espacios en blanco
            estado = transiciones_expresion[estado][posicion_simbolo(expresion[i], simbolos_expresion, cant_simbolos_expresion)]; //Actualizo el estado según el caracter leído
    }
    return es_final(estado);
}

bool es_final(int estado){ // Determina si el estado es final para el autómata de expresiones
    bool resultado = false;
    for(int i=0; i < cant_estados_finales_expresion; i++)
        resultado = resultado || (estado == estados_finales_expresion[i]);
    return resultado;
}