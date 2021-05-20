#include "trabajo.h"
#include "seoane.h"
#define VACIO 1
#define OCUPADO 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int hardcodearTrabajos (eTrabajo arrayTrabajo[], int tam)
{
    int i;
    int retorno;

    retorno = 0;

    eTrabajo arrayTrabajoLocal[10] = {{25, 25, 20000, 1, OCUPADO},
                                      {26, 26, 20001, 2, OCUPADO},
                                      {27, 27, 20002, 3, OCUPADO},
                                      {28, 28, 20003, 4, OCUPADO},
                                      {29, 29, 20001, 5, OCUPADO},
                                      {-1, -1, -1, -1, VACIO},
                                      {-1, -1, -1, -1, VACIO},
                                      {-1, -1, -1, -1, VACIO},
                                      {-1, -1, -1, -1, VACIO},
                                      {-1, -1, -1, -1, VACIO}};

    for(i=0; i<tam; i++)
    {
        arrayTrabajo[i] = arrayTrabajoLocal[i];
        retorno = 1;
    }

    return retorno;
}

int buscarLibreT (eTrabajo arrayTrabajo[], int tam)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tam; i++)
    {
        if(arrayTrabajo[i].isEmpty == VACIO)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

int buscarTrabajoPorId (eTrabajo arrayTrabajo[], int tam, int id)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tam; i++)
    {
        if(arrayTrabajo[i].isEmpty == OCUPADO)
        {
            if(arrayTrabajo[i].id == id)
            {
                pos = i;
                break;
            }
        }
    }

    return pos;
}

int tra_len (eTrabajo arrayTrabajo[], int tam)
{
    int i;
    int len;

    len = 0;

    for(i=0; i<tam; i++)
    {
        if(arrayTrabajo[i].isEmpty == OCUPADO)
        {
            len++;
        }
    }

    return len;
}

int tra_guardarUltimoID(char* path, int id)
{
    FILE* pFile;
    int retorno=0;

    pFile = fopen(path, "w");

    if(pFile != NULL)
    {
        fprintf(pFile,"%d", id);
        retorno=1;
    }

    fclose(pFile);

    return retorno;
}

int tra_cargarUltimoID (char* path, char* id)
{
    int retorno=0;
    FILE* pFile;

    pFile = fopen(path, "r");

    if(pFile != NULL)
    {
        fscanf(pFile, "%s", id);
        retorno=1;
    }

    fclose(pFile);

    return retorno;
}

