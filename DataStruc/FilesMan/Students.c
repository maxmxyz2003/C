#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char nombre[100];
    int clave;
    int prom;
     // Changed to a fixed-size character array
} alumn;
void InsertaCompu(char *nFile, char *name, int calif, int clave) {
    FILE *fr = fopen(nFile, "ab");
    if (!fr) {
        exit(1);
    }
    alumn student;
    strcpy(student.nombre, name);
    student.clave = clave;
    student.prom = calif; // You can set this to the desired value if needed.
    fwrite(&student, sizeof(alumn), 1, fr);
    fclose(fr);
}

int EliminaCompu(char *nFile, char *name) {
    FILE *fr = fopen(nFile, "rb");
    if (!fr) {
        exit(1);
    }
    FILE *tempFile = fopen("temp.dat", "ab"); // Temporary file
    if (!tempFile) {
        exit(1);
    }
    alumn student;
    int deleted = 0;
    while (fread(&student, sizeof(alumn), 1, fr) == 1) {
        if (strcmp(student.nombre, name) != 0) {
            fwrite(&student, sizeof(alumn), 1, tempFile);
        } else {
            deleted = 1;
        }
    }
    fclose(fr);
    fclose(tempFile);
    remove(nFile);
    rename("temp.dat", nFile);
    return deleted;
}
void ImprimeCompu(char *nFile) {
    FILE *fr = fopen(nFile, "rb");
    if (!fr){
        exit(1);
    }
    alumn student;
    while (fread(&student, sizeof(alumn), 1, fr) == 1) {
        printf("Nombre: %s, Calif: %d Clave: %d \n", student.nombre, student.prom, student.clave);
    }
    fclose(fr);
}
int main(void) {
    char tempnam[100] = "Jorge_Alberto_Suarez_Saldaña";
    int j = 10, fin = 0, opc=0;
    int p;
    char nombreArc[] = "data.dat"; // Change the file extension to .dat for binary data
    while (!fin) {
        printf("Que quieres hacer?\nAgregar(1), Eliminar(2), Imprimir(0)\n");
        scanf("%d", &opc);
        switch (opc){
        case 0:
            ImprimeCompu(nombreArc);
            break;
        case 1:
            printf("Nombre:\n");
            scanf("%s", tempnam);
            printf("Calificacion:\n");
            scanf("%d", &p);
            printf("Clave:\n");
            scanf("%d", &j);
            InsertaCompu(nombreArc, tempnam, p, j);
            break;
        case 2:
            printf("Nombre:\n");
            scanf("%s", tempnam);
            EliminaCompu(nombreArc, tempnam);
            break;
        default:
            printf("Opcion no valida: \n");
            break;
        }        
        printf("Terminar?\n");
        scanf("%d", &fin);
    }
    return 0;
}
