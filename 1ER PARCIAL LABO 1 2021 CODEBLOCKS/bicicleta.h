typedef struct{

    int idBicicleta;
    char marca[25];
    int rodado;
    char color[25];
    int isEmpty;

}eBicicleta;


int hardcodearBicicletas (eBicicleta arrayBicicletas[], int tam);
int buscarLibreB (eBicicleta arrayBicicletas[], int tam);
