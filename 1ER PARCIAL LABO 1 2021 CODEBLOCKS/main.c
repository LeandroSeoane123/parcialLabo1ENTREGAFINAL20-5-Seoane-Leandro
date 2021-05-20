#define CT 10
#define CF 10
#define CS 4
#define CB 10
#include <stdio.h>
#include <stdlib.h>
#include "trabajoServicio.h"
#include "seoane.h"


int main()
{
    int opcion;
    eTrabajo arrayDeTrabajos[CT];
    eServicio arrayDeServicios[CS];
    eFecha arrayDeFechas[CF];
    eBicicleta arrayDeBicicletas[CB];

    hardcodearTrabajos(arrayDeTrabajos, CT);
    hardcodearServicios(arrayDeServicios, CS);
    hardcodearFechas(arrayDeFechas, CF);
    hardcodearBicicletas(arrayDeBicicletas, CB);

   do
    {
        getInt("***** ABM TRABAJOS Y SERVICIOS: MENU DE OPCIONES *****"
               "\n1. Alta trabajo."
               "\n2. Modificar trabajo."
               "\n3. Baja trabajo."
               "\n4. Listar trabajos."
               "\n5. Listar servicios."
               "\n6. Total de pesos por los servicios prestados."
               "\n7. Listado de trabajos ordenados por marca de bicicleta."
               "\n8. El o los servicios con mas trabajos realizados."
               "\n9. Listado de servicios con los datos de las bicicletas a las que se los realizaron."
               "\n10. Cantidad de bicicletas de color rojo que realizaron un servicio elegido por el usuario."
               "\n11. Salir."
               "\nIngrese la opcion que desea realizar: ", &opcion);

        switch(opcion)
        {
        case 1:
            cargarTrabajo(arrayDeTrabajos, CT, arrayDeBicicletas, CB, arrayDeServicios, CS, arrayDeFechas, CF);
            break;
        case 2:
            modificarTrabajo(arrayDeTrabajos, CT, arrayDeBicicletas, CB, arrayDeServicios, CS, arrayDeFechas, CF);
            break;
        case 3:
            bajaLogicaTrabajo(arrayDeTrabajos, CT, arrayDeBicicletas, CB, arrayDeServicios, CS, arrayDeFechas, CF);
            break;
        case 4:
            mostrarTrabajos(arrayDeTrabajos, CT, arrayDeBicicletas, CB, arrayDeServicios, CS, arrayDeFechas, CF);
            break;
        case 5:
            mostrarServicios(arrayDeServicios, CS);
            break;
        case 6:
            mostrarCantidadDePesos(arrayDeTrabajos, CT, arrayDeServicios, CS);
            break;
        case 7:
            mostrarTrabajosOrdenadosPorMarca(arrayDeTrabajos, CT, arrayDeBicicletas, CB, arrayDeServicios, CS, arrayDeFechas, CF);
            break;
        case 8:
            mostrarServiciosConMasTrabajosRealizados(arrayDeTrabajos, CT, arrayDeServicios, CS);
            break;
        case 9:
            listarServiciosConSusBicicletas(arrayDeTrabajos, CT, arrayDeBicicletas, CB, arrayDeServicios, CS);
            break;
        case 10:
            mostrarBicicletasRojasConServicioIngresadoPorUsuario(arrayDeBicicletas, CB, arrayDeTrabajos, CT);
            break;
        case 11:
            puts("\nGracias por utilizar el programa!");
            break;
        }

        validarMenu(opcion, 1, 11);
        limpiarPantalla();

    }while(opcion !=11);


    return 0;
}
