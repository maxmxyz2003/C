#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nombre[50];
    int clave;
    float prom;
    char Carr[10];
    int generacion;
} alumn;

void InsertaCompu(char *nFile, char *name, float calif, int clave, int gen, char *carr){
    FILE *fr = fopen(nFile, "ab");
    if (!fr)
    {
        exit(1);
    }
    alumn student;
    strcpy(student.nombre, name);
    student.clave = clave;
    student.generacion = gen;
    strcpy(student.Carr, carr);
    student.prom = calif; // You can set this to the desired value if needed.
    fwrite(&student, sizeof(alumn), 1, fr);
    fclose(fr);
}
int EliminaCompu(char *nFile, char *name){
    FILE *fr = fopen(nFile, "rb");
    if (!fr)
    {
        exit(1);
    }
    FILE *tempFile = fopen("temp.dat", "ab"); // Temporary file
    if (!tempFile)
    {
        exit(1);
    }
    alumn student;
    int deleted = 0;
    while (fread(&student, sizeof(alumn), 1, fr) == 1)
    {
        if (strcmp(student.nombre, name) != 0)
        {
            fwrite(&student, sizeof(alumn), 1, tempFile);
        }
        else
        {
            deleted = 1;
        }
    }
    fclose(fr);
    fclose(tempFile);
    remove(nFile);
    rename("temp.dat", nFile);
    return deleted;
}
int RemCompu(char *nFile, char *name, float Nuev_calif){
    FILE *fr = fopen(nFile, "rb");
    if (!fr){
        exit(1);
    }
    FILE *tempFile = fopen("temp.dat", "ab"); // Temporary file
    if (!tempFile){
        exit(1);
    }
    alumn student;
    int replaced = 0;
    while (fread(&student, sizeof(alumn), 1, fr) == 1){
        if (strcmp(student.nombre, name) != 0){
            fwrite(&student, sizeof(alumn), 1, tempFile);
        }
        else{
            student.prom = Nuev_calif;
            fwrite(&student, sizeof(alumn), 1, tempFile);
            replaced = 1;
        }
    }
    fclose(fr);
    fclose(tempFile);
    remove(nFile);
    rename("temp.dat", nFile);
    return replaced;
}
void ImprimeCompu(char *nFile){
    FILE *fr = fopen(nFile, "rb");
    if (!fr){
        exit(1);
    }
    int cont = 0;
    alumn student;
    printf("| Nombre | Calificacion | Clave | Carrera | Generacion |\n");
    while (fread(&student, sizeof(alumn), 1, fr) == 1){
        // printf("Alumno #%d{\nNombre = %s\nCalificacion = %f\nClave = %d\nCarrera = %s\nGeneracion = %d\n}",cont, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
        printf("#%d %s\t%.2f\t%d\t%s\t%d\n",cont+1, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
        cont++;
    }
    fclose(fr);
}
int main(void){
    char tempnam[100] = "Jorge_Alberto_Suarez_Saldaña";
    int Miclave = 10, fin = 0, opc = 0;
    float p;
    int gener;
    char nombreArc[] = "database.dat"; // Change the file extension to .dat for binary data
    char carrera[50];
    while (!fin){
        printf("Que quieres hacer?\n Imprimir(0),Agregar(1), Eliminar(2), Reemplazar(3)\n");
        scanf("%d", &opc);
        switch (opc){
        case 0:
            ImprimeCompu(nombreArc);
            break;
        case 1:
            printf("Nombre:\n");
            scanf("%s", tempnam);
            printf("Calificacion:\n");
            scanf("%f", &p);
            printf("Clave:\n");
            scanf("%d", &Miclave);
            printf("Generación:\n");
            scanf("%d", &gener);
            printf("Carrera:\n");
            scanf("%s", carrera);
            InsertaCompu(nombreArc, tempnam, p, Miclave, gener, carrera);
            break;
        case 2:
            printf("Nombre:\n");
            scanf("%s", tempnam);
            EliminaCompu(nombreArc, tempnam);
            break;
        case 3:
            int cuantos = 0;
            printf("Cuantos reemplazos/actualizaciones?\n");
            scanf("%d", &cuantos);
            while (cuantos > 0){
                printf("Nombre:\n");
                scanf("%s", tempnam);
                printf("Nueva Calificación:\n");
                scanf("%f", &p);
                RemCompu(nombreArc, tempnam, p);
                cuantos--;
            }
            break;
        default:
            printf("Opcion no valida: \n");
            break;
        }
        printf("\nTerminar?\n");
        scanf("%d", &fin);
    }
    return 0;
}
