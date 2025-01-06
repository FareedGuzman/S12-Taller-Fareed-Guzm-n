#include <stdio.h>

// Definición de la estructura

struct Estudiante {
    char nombre[50];
    int edad;
    float promedio;
};

int main() {

    struct Estudiante estudiante1;
    // Asignación de valores a los miembros de la estructura
    printf("Ingrese el nombre del estudiante: ");
    fgets(estudiante1.nombre, 50, stdin);
    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &estudiante1.edad);
    printf("Ingrese el promedio del estudiante: ");
    scanf("%f", &estudiante1.promedio);
    // Mostrar la información del estudiante
    printf("\nInformación del Estudiante:\n");
    printf("Nombre: %s", estudiante1.nombre);
    printf("Edad: %d\n", estudiante1.edad);
    printf("Promedio: %.2f\n", estudiante1.promedio);

    return 0;
}