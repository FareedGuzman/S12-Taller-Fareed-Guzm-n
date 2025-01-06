#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definición de la estructura
struct Persona {
    char nombre[50];
    int edad;
};

// Función para escribir datos en el archivo
void escribirArchivo(struct Persona p) {
    FILE *archivo = fopen("e:\\datos.txt", "w");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    fprintf(archivo, "%s %d\n", p.nombre, p.edad);
    fclose(archivo);
}

// Función para leer y mostrar datos del archivo
void leerArchivo() {
    FILE *archivo = fopen("e:\\datos.txt", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo.\n");
        exit(1);
    }
    struct Persona p;
    fscanf(archivo, "%s %d", p.nombre, &p.edad);
    printf("Nombre: %s\nEdad: %d\n", p.nombre, p.edad);
    fclose(archivo);
}