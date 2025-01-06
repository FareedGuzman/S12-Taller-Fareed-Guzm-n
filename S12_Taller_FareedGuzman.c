/* S12 - Taller
Nombre: Fareed Guzmán
Fecha: 05/01/2025
Este programa permite registrar datos de estudiantes, guardarlos en un archivo CSV y leerlos desde ese mismo archivo */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de una estructura para almacenar información de un estudiante
typedef struct {
    int id;             // Identificador único para el estudiante
    char nombre[50];    // Nombre del estudiante (hasta 50 caracteres)
    float calificacion; // Calificación del estudiante (puede tener decimales)
} Estudiante;

// Función para guardar los datos de los estudiantes en un archivo
void guardarEnArchivo(Estudiante estudiantes[], int n, const char *nombreArchivo) {
    // Abrimos el archivo en modo escritura ("w")
    FILE *archivo = fopen(nombreArchivo, "w");
    if (archivo == NULL) { // Verificamos si el archivo se abrió correctamente
        printf("Error al abrir el archivo para escritura.\n");
        exit(1); // Finalizamos el programa si ocurre un error
    }

    // Escribimos los encabezados del archivo CSV
    fprintf(archivo, "ID,Nombre,Calificación\n");

    // Recorremos el arreglo de estudiantes y escribimos cada uno en el archivo
    for (int i = 0; i < n; i++) {
        fprintf(archivo, "%d,%s,%.2f\n", estudiantes[i].id, estudiantes[i].nombre, estudiantes[i].calificacion);
    }

    // Cerramos el archivo después de escribir los datos
    fclose(archivo);
    printf("Datos guardados exitosamente en %s\n", nombreArchivo);
}

// Función para leer los datos desde un archivo y mostrarlos en la consola
void leerDesdeArchivo(const char *nombreArchivo) {
    // Abrimos el archivo en modo lectura ("r")
    FILE *archivo = fopen(nombreArchivo, "r");
    if (archivo == NULL) { // Verificamos si el archivo se abrió correctamente
        printf("Error al abrir el archivo para lectura.\n");
        exit(1); // Finalizamos el programa si ocurre un error
    }

    // Variable para leer cada línea del archivo
    char linea[100];

    // Imprimimos el contenido del archivo línea por línea
    printf("\nContenido del archivo:\n");
    while (fgets(linea, sizeof(linea), archivo)) {
        printf("%s", linea); // Mostramos cada línea en la consola
    }

    // Cerramos el archivo después de leer los datos
    fclose(archivo);
}

int main() {
    int n; // Variable para almacenar el número de estudiantes

    // Solicitamos al usuario ingresar cuántos estudiantes se van a registrar
    printf("Ingrese el número de estudiantes: ");
    scanf("%d", &n);

    // Creamos un arreglo de estructuras para almacenar los datos de los estudiantes
    Estudiante estudiantes[n];

    // Captura de datos de cada estudiante
    for (int i = 0; i < n; i++) {
        printf("\nIngrese los datos del estudiante %d:\n", i + 1);
        
        // Pedimos el ID del estudiante
        printf("ID: ");
        scanf("%d", &estudiantes[i].id);

        // Pedimos el nombre del estudiante
        printf("Nombre: ");
        getchar(); // Limpiamos el buffer de entrada para evitar problemas al leer cadenas
        fgets(estudiantes[i].nombre, sizeof(estudiantes[i].nombre), stdin);
        estudiantes[i].nombre[strcspn(estudiantes[i].nombre, "\n")] = 0; // Eliminamos el salto de línea que fgets agrega

        // Pedimos la calificación del estudiante
        printf("Calificación: ");
        scanf("%f", &estudiantes[i].calificacion);
    }

    // Nombre del archivo donde se guardarán los datos
    const char *nombreArchivo = "estudiantes.csv";

    // Llamamos a la función para guardar los datos en un archivo
    guardarEnArchivo(estudiantes, n, nombreArchivo);

    // Llamamos a la función para leer los datos desde el archivo y mostrarlos
    leerDesdeArchivo(nombreArchivo);

    // Terminamos el programa
    return 0;
}
