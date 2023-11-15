#include "reconocedor.h"


int main()
{
    char *ruta;
    char expresion[TAMANIO_MAXIMO_DE_EXPRESION] = {0};
    unsigned int conteo_de_expresiones = 0;

    ruta = "./docs/test.txt";

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
        reconocer_tokens_afd(expresion);
    }

    if (fclose(archivo))
    {
        return EXIT_FAILURE;
        perror(ruta);
    }
}