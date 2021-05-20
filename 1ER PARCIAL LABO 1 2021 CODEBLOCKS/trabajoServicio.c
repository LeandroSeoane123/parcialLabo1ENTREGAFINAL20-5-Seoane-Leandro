#include "trabajoServicio.h"
#include "seoane.h"
#define VACIO 1
#define OCUPADO 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int cargarTrabajo (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF)
{
    int posT;
    int posB;
    int posF;
    int posS;
    int retorno;
    int idTrabajo;
    char idTraStr;
    int idBicicleta;
    char marcaBicicleta[25];
    int rodadoBicicleta;
    char color[25];
    int idServicio;
    int dia;
    int mes;
    int anio;
    int idFecha;

    posT = buscarLibreT(arrayTrabajo, tamT);
    posB = buscarLibreB(arrayBicicleta, tamB);
    posF = buscarLibreF(arrayFecha, tamF);

    if(posT != -1 && posF != -1 && posB != -1)
    {
        puts("\nDISPONIBILIDAD ENCONTRADA.");
        tra_cargarUltimoID("config.csv", &idTraStr);
        idTrabajo = atoi(&idTraStr);
        idTrabajo++;
        tra_guardarUltimoID("config.csv", idTrabajo);
        idBicicleta = idTrabajo;
        idFecha = arrayFecha[posF].idFecha;
        getString("\nIngrese la marca de la bicicleta: ", marcaBicicleta);
        strlwr(marcaBicicleta);
        marcaBicicleta[0] = toupper(marcaBicicleta[0]);
        getInt("\nIngrese el rodado de la bicicleta: ", &rodadoBicicleta);
        getString("\nIngrese el color de la bicicleta: ", color);
        strlwr(color);
        color[0] = toupper(color[0]);
        getInt("\nIngrese el dia en el que entrega la bicicleta: ", &dia);
        validarDia(&dia);
        getInt("\nIngrese el mes en el que entrega la bicicleta: ", &mes);
        validarMes(&mes);
        getInt("\nIngrese el anio en el que entrega la bicicleta: ", &anio);
        validarAnio(&anio);
        mostrarServicios(arrayServicio, tamS);
        getInt("\nIngrese que tipo de servicio desea que le realicemos a su bicicleta: ", &idServicio);
        posS = buscarServicioPorId(arrayServicio, tamS, idServicio);
        while(posS == -1)
        {
            getInt("\nERROR: El numero ingresado no corresponde con ningun servicio existente."
                   "\nPor favor, re-ingrese que tipo de servicio desea que le realicemos a su bicicleta: ", &idServicio);
            posS = buscarServicioPorId(arrayServicio, tamS, idServicio);
        }

        agregarTrabajo (arrayTrabajo, posT, idTrabajo, idBicicleta, idServicio, idFecha);
        agregarBicicleta(arrayBicicleta, posB, idBicicleta, marcaBicicleta, rodadoBicicleta, color);
        agregarFecha(arrayFecha, posF, dia, mes, anio);
        puts("\nTRABAJO CARGADO CON EXITO, NOS COMUNICAREMOS UNA VEZ ESTE REALIZADO.");
        retorno = 1;

    }
    else
    {
        puts("\nLo sentimos, de momento no contamos con disponibilidad para atender su pedido.");
        retorno = 0;
    }

    return retorno;
}

int modificarTrabajo (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF)
{
    int retorno;
    int idTrabajo;
    char idTraStr;
    int idBicicleta;
    char marcaBicicleta[25];
    int rodadoBicicleta;
    char color[25];
    int idServicio;
    int posT;
    int posB;
    int posS;
    int posF;
    int len;

    retorno = 0;

    len = tra_len(arrayTrabajo, tamT);

    if(len > 0)
    {
        getInt("\nIngrese el id del trabajo que desea modificar: ", &idTrabajo);
        posT = buscarTrabajoPorId(arrayTrabajo, tamT, idTrabajo);
        posB = buscarBicicletaPorTrabajo(arrayTrabajo, posT, arrayBicicleta, tamB);

        if(posB != -1)
        {
            puts("\nTRABAJO ENCONTRADO.");
            posS = buscarServicioPorTrabajo(arrayTrabajo, posT, arrayServicio, tamS);
            posF = buscarFechaPorTrabajo(arrayTrabajo, posT, arrayFecha, tamF);
            puts("\n--- ID -------- MARCA -------- RODADO -------- COLOR -------- SERVICIO -------- PRECIO -------- FECHA");
            mostrarUnTrabajo(arrayBicicleta, posB, arrayServicio, posS, arrayFecha, posF);
            tra_cargarUltimoID("config.csv", &idTraStr);
            idTrabajo = atoi(&idTraStr);
            idTrabajo++;
            idBicicleta = idTrabajo;
            tra_guardarUltimoID("config.csv", idTrabajo);
            getString("\nRe-ingrese la marca de la bicicleta que esta modificando: ", marcaBicicleta);
            strlwr(marcaBicicleta);
            marcaBicicleta[0] = toupper(marcaBicicleta[0]);
            mostrarServicios(arrayServicio, tamS);
            getInt("\nRe-ingrese el tipo de servicio que desea que le realicemos a su bicicleta: ", &idServicio);
            posS = buscarServicioPorId(arrayServicio, tamS, idServicio);
            while(posS == -1)
            {
                getInt("\nERROR: El numero ingresado no corresponde con ningun servicio existente."
                       "\nPor favor, re-ingrese que tipo de servicio desea que le realicemos a su bicicleta: ", &idServicio);
                posS = buscarServicioPorId(arrayServicio, tamS, idServicio);
            }

            rodadoBicicleta = arrayBicicleta[posB].rodado;
            strcpy(color, arrayBicicleta[posB].color);
            arrayTrabajo[posT].idBicicleta = idBicicleta;
            agregarBicicleta(arrayBicicleta, posB, idBicicleta, marcaBicicleta, rodadoBicicleta, color);

            puts("\nEL TRABAJO HA SIDO MODIFICADO CON EXITO, NOS COMUNICAREMOS UNA VEZ ESTE REALIZADO.");

            retorno = 1;
        }
        else
        {
            puts("\nERROR: El ID ingresado no corresponde con ningun trabajo cargado anteriormente.");
            retorno = 0;
        }
    }
    else
    {
        puts("\nERROR: No hay trabajos cargados para modificar.");
        retorno = 0;
    }

    return retorno;
}

int bajaLogicaTrabajo (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF)
{
    int retorno;
    int len;
    int posT;
    int posB;
    int posS;
    int posF;
    int idTrabajo;
    int confirmacion;

    retorno = 0;

    len = tra_len(arrayTrabajo, tamT);

    if(len > 0)
    {
        getInt("\nIngrese el id del trabajo que desea borrar: ", &idTrabajo);
        posT = buscarTrabajoPorId(arrayTrabajo, tamT, idTrabajo);
        posB = buscarBicicletaPorTrabajo(arrayTrabajo, posT, arrayBicicleta, tamB);

        if(posB != -1)
        {
            puts("\nTRABAJO ENCONTRADO.");
            posS = buscarServicioPorTrabajo(arrayTrabajo, posT, arrayServicio, tamS);
            posF = buscarFechaPorTrabajo(arrayTrabajo, posT, arrayFecha, tamF);
            puts("\n--- ID -------- MARCA -------- RODADO -------- COLOR -------- SERVICIO -------- PRECIO -------- FECHA");
            mostrarUnTrabajo(arrayBicicleta, posB, arrayServicio, posS, arrayFecha, posF);

            getInt("\nEsta seguro que desea eliminar este trabajo?"
                   "\nIngrese '1' para si o cualquier otro numero para no: ", &confirmacion);

            if(confirmacion == 1)
            {
                arrayTrabajo[posT].isEmpty = VACIO;
                arrayBicicleta[posB].isEmpty = VACIO;
                retorno = 1;
                puts("\nTRABAJO BORRADO CON EXITO.");
            }
            else
            {
                puts("\nOPERACION CANCELADA.");
                retorno = 0;
            }
        }
        else
        {
            puts("\nERROR: El ID ingresado no corresponde con ningun trabajo cargado anteriormente.");
        }

    }
    else
    {
        puts("\nERROR: No hay trabajos cargados para borrar.");
        retorno = 0;
    }

    return retorno;
}

void agregarTrabajo (eTrabajo arrayTrabajo[], int posT, int idTrabajo, int idBicicleta, int idServicio, int idFecha)
{
    arrayTrabajo[posT].id = idTrabajo;
    arrayTrabajo[posT].idBicicleta = idBicicleta;
    arrayTrabajo[posT].idServicio = idServicio;
    arrayTrabajo[posT].idFecha = idFecha;
    arrayTrabajo[posT].isEmpty = OCUPADO;
}

void agregarBicicleta (eBicicleta arrayBicicleta[], int posB, int idBicicleta, char marca[], int rodado, char color[])
{
    arrayBicicleta[posB].idBicicleta = idBicicleta;
    strcpy(arrayBicicleta[posB].marca, marca);
    arrayBicicleta[posB].rodado = rodado;
    strcpy(arrayBicicleta[posB].color, color);
    arrayBicicleta[posB].isEmpty = OCUPADO;
}

int buscarServicioPorTrabajo(eTrabajo arrayTrabajo[], int posT, eServicio arrayServicio[], int tamS)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tamS; i++)
    {
        if(arrayServicio[i].isEmpty == OCUPADO)
        {
            if(arrayServicio[i].id == arrayTrabajo[posT].idServicio)
            {
                pos = i;
                break;
            }
        }
    }

    return pos;
}

int buscarFechaPorTrabajo (eTrabajo arrayTrabajo[], int posT, eFecha arrayFecha[], int tamF)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tamF; i++)
    {
        if(arrayFecha[i].isEmpty == OCUPADO)
        {

            if(arrayFecha[i].idFecha == arrayTrabajo[posT].idFecha)
            {
                pos = i;
                break;
            }
        }
    }

    return pos;
}

int buscarBicicletaPorTrabajo (eTrabajo arrayTrabajo[], int posT, eBicicleta arrayBicicleta[], int tamB)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tamB; i++)
    {
        if(arrayBicicleta[i].isEmpty == OCUPADO)
        {

            if(arrayBicicleta[i].idBicicleta == arrayTrabajo[posT].idBicicleta)
            {
                pos = i;
                break;
            }
        }
    }

    return pos;
}

int buscarTrabajoPorServicio (eServicio arrayServicio[], int posS, eTrabajo arrayTrabajo[], int tamT)
{
    int i;
    int pos;

    pos = -1;

    for(i=0; i<tamT; i++)
    {
        if(arrayServicio[posS].id == arrayTrabajo[i].idServicio)
        {
            pos = i;
            break;
        }
    }

    return pos;
}

void mostrarTrabajos (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF)
{
    int i;
    int len;
    int posS;
    int posF;
    int posB;

    len = tra_len(arrayTrabajo, tamT);

    if(len > 0)
    {
        puts("\n--- ID -------- MARCA -------- RODADO -------- COLOR -------- SERVICIO -------- PRECIO -------- FECHA");

        for(i=0; i<tamT; i++)
        {
            if(arrayTrabajo[i].isEmpty == OCUPADO)
            {
                posB = buscarBicicletaPorTrabajo(arrayTrabajo, i, arrayBicicleta, tamB);
                if(posB != -1)
                {
                    posS = buscarServicioPorTrabajo(arrayTrabajo, i, arrayServicio, tamS);
                    if(posS != -1)
                    {
                        posF = buscarFechaPorTrabajo(arrayTrabajo, i, arrayFecha, tamF);
                        if(posF != -1)
                        {
                            mostrarUnTrabajo(arrayBicicleta, posB, arrayServicio, posS, arrayFecha, posF);
                        }
                        else
                        {
                            puts("\nERROR: Fallo al buscar la fecha del ingreso.");
                        }
                    }
                    else
                    {
                        puts("\nERROR: Fallo al buscar el servicio contratado.");
                    }

                }
                else
                {
                    puts("\nERROR: Fallo al buscar la bicicleta asociada al trabajo.");
                }
            }
        }
    }
    else
    {
        puts("\nERROR: No hay trabajos cargados para mostrar.");

    }
}

void mostrarUnTrabajo (eBicicleta arrayBicicleta[], int posB, eServicio arrayServicio[], int posS, eFecha arrayFecha[], int posF)
{
    printf("\n%6d %14s %15d %14s %17s %15.2f %7d/%d/%d", arrayBicicleta[posB].idBicicleta,
                                                          arrayBicicleta[posB].marca,
                                                          arrayBicicleta[posB].rodado,
                                                          arrayBicicleta[posB].color,
                                                          arrayServicio[posS].descripcion,
                                                          arrayServicio[posS].precio,
                                                          arrayFecha[posF].dia,
                                                          arrayFecha[posF].mes,
                                                          arrayFecha[posF].anio);
}

void mostrarCantidadDePesos (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS)
{
    int i;
    int posS;
    float sumaPrecios;
    int len;

    len = tra_len(arrayTrabajo, tamT);

    sumaPrecios = 0;

    if(len > 0)
    {


        for(i=0; i<tamT; i++)
        {
            if(arrayTrabajo[i].isEmpty == OCUPADO)
            {
                posS = buscarServicioPorTrabajo(arrayTrabajo, i, arrayServicio, tamS);

                if(posS != -1)
                {
                    sumaPrecios = sumaPrecios + arrayServicio[posS].precio;
                }
            }
        }

        printf("\nLa suma de todos los precios de todos los trabajos encargados es: %.2f", sumaPrecios);

    }
    else
    {
        puts("\nNo hay trabajos cargados para informar la cantidad de precios totales.");
    }
}

void mostrarTrabajosOrdenadosPorMarca (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF)
{
    ordenarBicicletasPorMarca(arrayBicicleta, tamB, arrayTrabajo, tamT);
    mostrarTrabajos(arrayTrabajo, tamT, arrayBicicleta, tamB, arrayServicio, tamS, arrayFecha, tamF);
}

void ordenarBicicletasPorMarca (eBicicleta arrayBicicleta[], int tamB, eTrabajo arrayTrabajo[], int tamT)
{
    int i;
    int j;
    int retornoCmp;
    eBicicleta aux;
    eTrabajo auxT;

    for(i=0; i<tamB-1; i++)
    {
        for(j=i+1; j<tamB; j++)
        {
            retornoCmp = strcmp(arrayBicicleta[i].marca, arrayBicicleta[j].marca);
            if(retornoCmp == 1)
            {
               aux = arrayBicicleta[i];
               auxT = arrayTrabajo[i];
               arrayBicicleta[i] = arrayBicicleta[j];
               arrayTrabajo[i] = arrayTrabajo[j];
               arrayBicicleta[j] = aux;
               arrayTrabajo[j] = auxT;
            }
        }
    }
}

void listarServiciosConSusBicicletas (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS)
{
    int i;

    puts("\nLISTANDO SERVICIOS CON SUS RESPECTIVAS BICICLETAS");
    puts("ID -------- SERVICIO -------- PRECIO");

    for(i=0; i<tamS; i++)
    {
        mostrarUnServicioConSuBicicleta(arrayServicio, i, arrayTrabajo, tamT, arrayBicicleta, tamB);
    }
}

void mostrarUnServicioConSuBicicleta (eServicio arrayServicio[], int posS, eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB)
{
    int i;
    int posB;

    printf("\n%d %14s %15.2f -------- MARCA -------- RODADO -------- COLOR\n", arrayServicio[posS].id,
                               arrayServicio[posS].descripcion,
                               arrayServicio[posS].precio);

    for(i=0; i<tamT; i++)
    {
        if(arrayTrabajo[i].isEmpty == OCUPADO)
        {
            if(arrayTrabajo[i].idServicio == arrayServicio[posS].id)
            {
                posB = buscarBicicletaPorTrabajo(arrayTrabajo, i, arrayBicicleta, tamB);
                mostrarUnaBicicletaPorServicio(arrayBicicleta, posB);
            }
        }
    }
}

void mostrarUnaBicicletaPorServicio (eBicicleta arrayBicicleta[], int posB)
{
    printf("\n%51s %15d %14s\n", arrayBicicleta[posB].marca,
                               arrayBicicleta[posB].rodado,
                               arrayBicicleta[posB].color);
}

void mostrarServiciosConMasTrabajosRealizados (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS)
{
    int posSMax;

    posSMax = devolverIdServicioConMasTrabajos(arrayTrabajo, tamT, arrayServicio, tamS);

    puts("\nEl servicio con mas trabajos ingresados es: ");
    puts("ID -------- SERVICIO -------- PRECIO");
    mostrarUnServicio(arrayServicio, posSMax);
}

int devolverIdServicioConMasTrabajos (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS)
{
    int i;
    int j;
    int max;
    int posMax;
    int contador;

    max = 0;
    contador = 0;

    for(i=0; i<tamS; i++)
    {
        for(j=0; j<tamT; j++)
        {
            if(arrayTrabajo[j].isEmpty == OCUPADO)
            {
                if(arrayTrabajo[j].idServicio == arrayServicio[i].id)
                {
                    contador++;
                    if(contador>max)
                    {
                        max = contador;
                        posMax = i;
                    }
                }
            }
        }
        contador = 0;
    }

    return posMax;
}

void mostrarBicicletasRojasConServicioIngresadoPorUsuario (eBicicleta arrayBicicleta[], int tamB, eTrabajo arrayTrabajo[], int tamT)
{
    int i;
    int posB;
    int retornoCmp;
    int contador;

    contador = 0;

    for(i=0; i<tamT; i++)
    {
       posB = buscarBicicletaPorTrabajo(arrayTrabajo, i, arrayBicicleta, tamB);

        if(arrayBicicleta[posB].isEmpty == OCUPADO)
        {
            if(arrayBicicleta[posB].idBicicleta > 29)
            {
                retornoCmp = strcmp(arrayBicicleta[posB].color, "Rojo");
                if(retornoCmp==0)
                {
                    contador++;
                }
                retornoCmp = strcmp(arrayBicicleta[posB].color, "Roja");
                if(retornoCmp==0)
                {
                    contador++;
                }
            }
        }
    }

    if(contador > 0)
    {
        printf("\nLa cantidad de bicicletas rojas que fueron ingresadas por el usuario es: %d", contador);
    }
    else
    {
        puts("\nNo se encontraron bicicletas de color rojo ingresadas por el usuario.");
    }
}
