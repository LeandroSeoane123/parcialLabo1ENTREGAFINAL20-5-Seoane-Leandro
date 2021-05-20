#include "bicicleta.h"
#include "seoane.h"
#define VACIO 1
#define OCUPADO 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hardcodearBicicletas(eBicicleta arrayBicicletas[], int tam)
{
    int i;
    int retorno;

    retorno = 0;

    eBicicleta arrayBicicletaLocal[10] = {{25, "Nordic", 25, "Roja", OCUPADO},
                                         {26, "Venzo", 23, "Amarilla", OCUPADO},
                                         {27, "Vairo", 24, "Verde", OCUPADO},
                                         {28, "Olmo", 29, "Azul", OCUPADO},
                                         {29, "Trinx", 22, "Negra", OCUPADO},
                                         {-1, "", -1, "", VACIO},
                                         {-1, "", -1, "", VACIO},
                                         {-1, "", -1, "", VACIO},
                                         {-1, "", -1, "", VACIO},
                                         {-1, "", -1, "", VACIO}};

    for(i=0; i<tam; i++)
    {
        arrayBicicletas[i] = arrayBicicletaLocal[i];
        retorno = 1;
    }

    return retorno;
}

int buscarLibreB (eBicicleta arrayBicicletas[], int tam)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tam; i++)
    {
        if(arrayBicicletas[i].isEmpty==VACIO)
        {
            pos=i;
            break;
        }
    }

    return pos;
}
