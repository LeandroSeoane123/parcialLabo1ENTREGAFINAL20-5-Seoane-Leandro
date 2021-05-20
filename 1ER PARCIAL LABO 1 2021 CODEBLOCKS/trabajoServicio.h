#include "trabajo.h"
#include "servicio.h"
#include "fecha.h"
#include "bicicleta.h"

int cargarTrabajo (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF);
void agregarTrabajo (eTrabajo arrayTrabajo[], int posT, int idTrabajo, int idBicicleta, int idServicio, int idFecha);
void agregarBicicleta (eBicicleta arrayBicicleta[], int posB, int idBicicleta, char marca[], int rodado, char color[]);
int modificarTrabajo (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF);
int bajaLogicaTrabajo (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF);
int buscarServicioPorTrabajo (eTrabajo arrayTrabajo[], int posT, eServicio arrayServicio[], int tamS);
int buscarFechaPorTrabajo (eTrabajo arrayTrabajo[], int posT, eFecha arrayFecha[], int tamF);
int buscarBicicletaPorTrabajo (eTrabajo arrayTrabajo[], int posT, eBicicleta arrayBicicleta[], int tamB);
int buscarTrabajoPorServicio (eServicio arrayServicio[], int posS, eTrabajo arrayTrabajo[], int tamT);
void mostrarTrabajos (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF);
void mostrarUnTrabajo (eBicicleta arrayBicicleta[], int posB, eServicio arrayServicio[], int posS, eFecha arrayFecha[], int posF);
void mostrarCantidadDePesos (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS);
void mostrarTrabajosOrdenadosPorMarca (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS, eFecha arrayFecha[], int tamF);
void ordenarBicicletasPorMarca (eBicicleta arrayBicicleta[], int tamB, eTrabajo arrayTrabajo[], int tamT);
void listarServiciosConSusBicicletas (eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB, eServicio arrayServicio[], int tamS);
void mostrarUnServicioConSuBicicleta (eServicio arrayServicio[], int posS, eTrabajo arrayTrabajo[], int tamT, eBicicleta arrayBicicleta[], int tamB);
void mostrarUnaBicicletaPorServicio (eBicicleta arrayBicicleta[], int posB);
void mostrarServiciosConMasTrabajosRealizados (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS);
int devolverIdServicioConMasTrabajos (eTrabajo arrayTrabajo[], int tamT, eServicio arrayServicio[], int tamS);
void mostrarBicicletasRojasConServicioIngresadoPorUsuario (eBicicleta arrayBicicleta[], int tamB, eTrabajo arrayTrabajo[], int tamT);
