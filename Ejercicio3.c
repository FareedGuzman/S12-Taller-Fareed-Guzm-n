#include <stdio.h>

int main(void) {
  FILE *file;
  const char *filename = "archivo.txt";
  const char *message = "Hola, mundo!\n";
  file = fopen(filename, "a");
  if (file == NULL){
    printf("Error al abrir el archivo.\n");
    return 1;
  }
fputs(message, file);
fclose(file);

file = fopen(filename, "r");
  if (file) {
    printf("El archivo '%s' fue creado correctamente.\n", filename);
    fclose(file);
    } else {
    printf("Error: El archivo '%s' no se pudo crear.\n", filename);
    }

return 0;
}

