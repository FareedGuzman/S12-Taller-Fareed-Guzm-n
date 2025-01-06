#include <stdio.h>

//Definicion de la estructura
struct Cliente{
  char nombre [50];
  char apellido [50];
  int cedula;
}; 

int main(void){
  struct Cliente cliente1;
  //Asignacion de los valores a los miembros de la estructura
  printf("Ingrese el nombre del cliente: ");
  fgets(cliente1.nombre, 50, stdin);
  printf("Ingrese el apellido del cliente");
  fgets(cliente1.apellido, 50, stdin);
  printf("Ingrese la cedula del cliente: ");
  scanf("%d", &cliente1.cedula);

  //Mostrar la informacion del cliente
  printf("Informacion del estudiante:\n");
  printf("Nombre: %s", cliente1.nombre);
  printf("Apellido: %s\n", cliente1.apellido);
  printf("Cedula: %.2d\n", cliente1.cedula);

return 0;
}

