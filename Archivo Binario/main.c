#include <stdio.h>
#include <string.h>

typedef struct
{
    int valor;
    char nombre[30];
} Calificaciones;

int main(char const *argv[], int argc)
{
    FILE *archivo;
    int valor=9;
    int valorRegreso;
    int alumnos;
    int arr[10];
    int promedio;
    int sumaDeValores=0;
    Calificaciones calif, califLeida;
    strcpy(calif.nombre, "Santi");
    calif.valor=8;
    archivo=fopen("Calif.dat", "wb");
    printf("Dame el numero de alumnos");
    scanf("%d", &alumnos);
    for(int i=0; i<alumnos; i++)
    {
        printf("Dame un nombre: ");
        scanf("%s", calif.nombre);
        printf("Dame la calificacion: ");
        scanf("%d", &calif.valor);
        fwrite(&calif, sizeof(Calificaciones), 1, archivo);
    }
    fclose(archivo);
    archivo=fopen("Calif.dat", "rb");
    while(!feof(archivo))
    {
      fread(&califLeida, sizeof(Calificaciones), 1, archivo);
      printf("%s-%d", califLeida.nombre, califLeida.valor);
      for(int j=0; j<alumnos; j++)
      {
        Calificaciones>>arr[j];
        sumaDeValores+=arr[j];
      }
    }
    promedio=sumaDeValores/alumnos;
    fclose(archivo);
    return 0;
}
