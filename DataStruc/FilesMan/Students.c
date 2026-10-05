#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    char nombre[50];
    int clave;
    float prom;
    char Carr[10];
    int generacion;
}alumn;
void InsertaCompu(char *nFile, char *name, float calif, int clave, int gen, char *carr){
    FILE *fr = fopen(nFile, "ab");
    if (!fr)
    {
        exit(EXIT_FAILURE);
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

int CambiaCompu(char *nFile, char *name, char *carr, float La_calif, int LaGen, int LaClave, float nuevaCalif, char *nuevCarr, int nuevaGen){
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
            if (strcmp(student.Carr, carr)==0 && La_calif==student.prom&&LaClave==student.clave&&student.generacion==LaGen){
                student.prom = nuevaCalif;
                strcpy(student.Carr, nuevCarr);
                student.generacion=nuevaGen;
                fwrite(&student, sizeof(alumn), 1, tempFile);
                replaced = 1;
            }            
        }
    }
    fclose(fr);
    fclose(tempFile);
    remove(nFile);
    rename("temp.dat", nFile);
    return replaced;
}
int AccessCompu(char *nFile, char *name, char *carr, float La_calif, int LaGen, int LaClave){
    FILE *fr = fopen(nFile, "rb");
    if (!fr){
        exit(1);
    }
    alumn student;
    int replaced = 0;
    while (fread(&student, sizeof(alumn), 1, fr) == 1){
        if (strcmp(student.nombre, name)==0 && La_calif==student.prom&&student.generacion==LaGen&& LaClave==student.clave&&strcmp(student.Carr, carr)==0){
            printf("Nombre: %s Calificacion: %.2f, Clave:%d Carrera:%s Generacion:%d ", student.nombre,student.prom, student.clave, student.Carr,student.generacion);
            replaced=1;
        }
    }    
    fclose(fr);
    return replaced;
}
int AccessCompu2(char *nFile, char *name){
    FILE *fr = fopen(nFile, "rb");
    if (!fr){
        exit(1);
    }
    alumn student;
    int replaced = 0;
    while (fread(&student, sizeof(alumn), 1, fr) == 1){
        if (!strcmp(student.nombre, name)){
            printf("Nombre: %s Calificacion: %.2f, Clave:%d Carrera:%s Generacion:%d ", student.nombre,student.prom, student.clave, student.Carr,student.generacion);
            replaced=1;
        }
        else{
            continue;
        }
    }    
    fclose(fr);
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
void FiltraApCompu(char *nFile, float Lcalif){
    FILE *fr = fopen(nFile, "rb");
    if (!fr){
        exit(1);
    }
    int cont = 0;
    alumn student;
    printf("| Nombre | Calificacion | Clave | Carrera | Generacion |\n");
    while (fread(&student, sizeof(alumn), 1, fr) == 1){
        // printf("Alumno #%d{\nNombre = %s\nCalificacion = %f\nClave = %d\nCarrera = %s\nGeneracion = %d\n}",cont, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
        if(student.prom>Lcalif){    
            printf("#%d %s\t%.2f\t%d\t%s\t%d\n",cont+1, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
            cont++;
        }
        
    }
    fclose(fr);
}
void FiltraReCompu(char *nFile, float Lcalif){
    FILE *fr = fopen(nFile, "rb");
    if (!fr){
        exit(1);
    }
    int cont = 0;
    alumn student;
    printf("| Nombre | Calificacion | Clave | Carrera | Generacion |\n");
    while (fread(&student, sizeof(alumn), 1, fr) == 1){
        // printf("Alumno #%d{\nNombre = %s\nCalificacion = %f\nClave = %d\nCarrera = %s\nGeneracion = %d\n}",cont, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
        if(student.prom<=Lcalif){    
            printf("#%d %s\t%.2f\t%d\t%s\t%d\n",cont+1, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
            cont++;
        }
        
    }
    fclose(fr);
}
void FiltraGenCompu(char *nFile, int Gen){
    FILE *fr = fopen(nFile, "rb");
    if (!fr){
        exit(1);
    }
    int cont = 0;
    alumn student;
    printf("| Nombre | Calificacion | Clave | Carrera | Generacion |\n");
    while (fread(&student, sizeof(alumn), 1, fr) == 1){
        // printf("Alumno #%d{\nNombre = %s\nCalificacion = %f\nClave = %d\nCarrera = %s\nGeneracion = %d\n}",cont, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
        if(student.generacion==Gen){    
            printf("#%d %s\t%.2f\t%d\t%s\t%d\n",cont+1, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
            cont++;
        }
    }
    fclose(fr);
}
void FiltraCarrCompu(char *nFile, char *carrera){
    FILE *fr = fopen(nFile, "rb");
    if (!fr){
        exit(1);
    }
    int cont = 0;
    alumn student;
    printf("| Nombre | Calificacion | Clave | Carrera | Generacion |\n");
    while (fread(&student, sizeof(alumn), 1, fr) == 1){
        // printf("Alumno #%d{\nNombre = %s\nCalificacion = %f\nClave = %d\nCarrera = %s\nGeneracion = %d\n}",cont, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
        if(!strcmp(carrera, student.Carr)){    
            printf("#%d %s\t%.2f\t%d\t%s\t%d\n",cont+1, student.nombre, student.prom, student.clave, student.Carr, student.generacion);
            cont++;
        }
       
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
        printf("Que quieres hacer?\n Imprimir(0),Agregar(1), Eliminar(2), Reemplazar(3), Consulta(4), Filtro(5)\n");
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
        case 4:
            printf("Que buscas? Nombre(1) Clave(2)");
            printf("Nombre:\n");
            scanf("%s", tempnam);
            if(AccessCompu2(nombreArc, tempnam)){
                printf("\n");
            }else{
                printf("No encontrado\n");
            }
            break;
        case 5:
            printf("Filtrar por Promedio(1), Generacion(2), Carrera(3)\n");
            int Nopc;
            scanf("%d",&Nopc);
                switch (Nopc){
                case 1:
                    int masque;
                    printf("Que promedio?\n");
                    scanf("%f", &p);
                    printf("Mayor(1) o menor(2)?");
                    scanf("%d", &masque);
                    if (masque==1)
                    {
                        FiltraApCompu(nombreArc, p);
                    }else{
                        FiltraReCompu(nombreArc, p);
                    }
                    break;
                case 2:
                    printf("Que generacion?\n");
                    scanf("%d", &gener);
                    FiltraGenCompu(nombreArc, gener);
                    break;
                case 3:
                    printf("Que carrera?\n");
                    scanf("%s", tempnam);
                    FiltraCarrCompu(nombreArc, tempnam);
                    break;
                default:
                    break;
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
