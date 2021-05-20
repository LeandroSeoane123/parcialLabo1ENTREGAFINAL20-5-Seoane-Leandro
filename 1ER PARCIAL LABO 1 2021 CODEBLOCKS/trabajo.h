typedef struct{

    int id;
    int idBicicleta;
    int idServicio;
    int idFecha;
    int isEmpty;

}eTrabajo;

int hardcodearTrabajos (eTrabajo arrayTrabajo[], int tam);
int buscarLibreT (eTrabajo arrayTrabajo[], int tam);
int buscarTrabajoPorId (eTrabajo arrayTrabajo[], int tam, int id);
int tra_len (eTrabajo arrayTrabajo[], int tam);
int tra_guardarUltimoID(char* path, int id);
int tra_cargarUltimoID (char* path, char* id);
