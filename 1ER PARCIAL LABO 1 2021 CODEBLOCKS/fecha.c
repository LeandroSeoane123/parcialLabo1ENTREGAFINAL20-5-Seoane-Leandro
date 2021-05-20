#include "fecha.h"
#include "seoane.h"
#define VACIO 1
#define OCUPADO 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hardcodearFechas (eFecha arrayFecha[], int tam)
{
    int i;
    int retorno;

    retorno = 0;

    eFecha arrayFechaLocal[10] = {{1, 15, 5, 2021, OCUPADO},
                                    {2, 16, 2, 2021, OCUPADO},
                                    {3, 17, 3, 2021, OCUPADO},
                                    {4, 18, 1, 2021, OCUPADO},
                                    {5, 19, 4, 2021, OCUPADO},
                                    {-1, -1, -1, -1, VACIO},
                                    {-1, -1, -1, -1, VACIO},
                                    {-1, -1, -1, -1, VACIO},
                                    {-1, -1, -1, -1, VACIO},
                                    {-1, -1, -1, -1, VACIO}};

    for(i=0; i<tam; i++)
    {
        arrayFecha[i] = arrayFechaLocal[i];
        retorno = 1;
    }

    return retorno;
}

int buscarLibreF (eFecha arrayFecha[], int tam)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tam; i++)
    {
        if(arrayFecha[i].isEmpty == VACIO)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

void agregarFecha (eFecha arrayFecha[], int posF, int dia, int mes, int anio)
{
    arrayFecha[posF].dia = dia;
    arrayFecha[posF].mes = mes;
    arrayFecha[posF].anio = anio;
    arrayFecha[posF].isEmpty = OCUPADO;
}


