#include "reconocedor.h"


int main(int argc, char **argv)
{
    char *ruta;
    char expresion[TAMANIO_MAXIMO_DE_EXPRESION] = {0};
    unsigned int conteo_de_expresiones = 0;
    
    if (argc < 1)
        return EXIT_FAILURE;
    ruta = argv[1];
    
    FILE *archivo = fopen(ruta, "r");
    
    if (!archivo)
    {
        perror(ruta);
        return EXIT_FAILURE;
    }
    
    while (fgets(expresion, TAMANIO_MAXIMO_DE_EXPRESION, archivo))
    {
        printf("Linea %d: Expresion: %s\n", ++conteo_de_expresiones, expresion);
        if(reconocer_expresion_afd(expresion))
            printf("La expresion es valida\n");
        else
            printf("La expresion es invalida\n");
        //reconocer_tokens_afd(expresion);
        printf("a");
    }
    
    if (fclose(archivo))
    {
        return EXIT_FAILURE;
        perror(ruta);
    }
}


int posicion_simbolo(char c, const char* simbolos, int cant_simbolos){
    for (int i = 0; i < cant_simbolos; i++){
        if(simbolos[i] == c)
            return i;
    }
    return cant_simbolos; 
}

bool reconocer_expresion_afd(char* expresion){
    return automata_expresion(expresion);
}

void reconocer_tokens_afd(char* expresion){
    int pos = 0, pos_previa = 0;                                                        // Arranco con la expresión completa
    while(expresion[pos]!='\n'){
        pos_previa = pos;
        pos += automata_constante(truncar_expresion(expresion, pos));    // A medida que voy reconociendo los tokens
        pos += automata_operador(truncar_expresion(expresion, pos));        // los retiro de la expresión
        if(pos != 0 && pos == pos_previa){
            printf("Caracter no reconocido en la posicion: %d\n", pos);
            pos++;
        }
            
    }
}

char* truncar_expresion(char* expresion, int pos) {
    int len = strlen(expresion);
    if (len > pos) {
        expresion = expresion + pos;
    }
    return expresion;
}

int automata_operador(char* expresion){ // En este caso, al no ser recursivo y las palabras del lenguaje sólo tienen un caracter, necesito reconocer unicamente el primer caracter de la expresión truncada
    int estado = transiciones_operador[0][posicion_simbolo(expresion[0], simbolos_operador, cant_simbolos_operador)];
    if(estado != 2){ // 
        printf("Operador\n");
        return 1;
    }
    else
        return 0;
        
}

int automata_constante(char* expresion){
    bool match = false; // Utilizo como flag para saber si encontró al menos un caracter
    int estado = 0; // Estado iniial
    int pos; // Posición en el string
    for(pos = 0; pos < strlen(expresion); pos++){
        if(estado != 2){ // En el caso de ser estado de error salgo del ciclo repetitivo
            estado = transiciones_constante[estado][posicion_simbolo(expresion[pos], simbolos_constante, cant_simbolos_constante)]; // Actualizo el estado con la tabla de transiciones
            match = true; // Encontró coincidencia, lo considero como token
        }
        else
            break;
    }
    if(match)
        printf("Constante numerica\n");
    return pos; // Devuelvo la posición donde quedó
}

bool automata_expresion(char* expresion){

    int estado = 0;
    for(int i=0; i < strlen(expresion); i++){
        if(expresion[i] != ' ' && expresion[i] != '\t') // Desconsidero cambios de estado por espacios en blanco
            estado = transiciones_operador[estado][posicion_simbolo(expresion[i], simbolos_expresion, cant_simbolos_expresion)];
    }
    return es_final(estado);
}

bool es_final(int estado){
    bool resultado = false;
    for(int i=0; i < cant_estados_finales_expresion; i++)
        resultado = resultado || (estado == estados_finales_expresion[i]);
    return resultado;
}