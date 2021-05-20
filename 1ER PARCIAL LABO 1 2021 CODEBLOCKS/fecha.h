typedef struct{

    int idFecha;
    int dia;
    int mes;
    int anio;
    int isEmpty;

}eFecha;

int hardcodearFechas (eFecha arrayFecha[], int tam);
int buscarLibreF (eFecha arrayFecha[], int tam);
void agregarFecha (eFecha arrayFecha[], int posF, int dia, int mes, int anio);

