#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct{
    int clave;
    double prom;
    char * nombre;
} alumn;

void a(){
    printf("a\n");
}
void InsertaCompu(char *nFile,char *name, int calif){
    FILE *fr=fopen(nFile, "ab");
    if(!fr){
        exit(1);
    }
    fprintf(fr, "\n%s ",name);
    fprintf(fr, "%d",calif);
    fclose(fr);
}
void ImprimeCompu(char *nFile){
    char name[100];
    int calif;
    FILE *fr=fopen(nFile, "rb");
    if(!fr){
        exit(1);
    }
    fseek(fr, 0, SEEK_SET);
    while (fscanf(fr, "%s %d", name, &calif) != EOF) {
        printf("Nombre: %s, Calif: %d\n", name, calif);
    }
    fclose(fr);
}

int main(void) {
    char tempnam[100] = "Jorge_Alberto_Suarez_Saldaña";
    int j = 10, fin=1;
    int clave=355992;
    char nombreArc[]={"data.txt"};
    while (fin){
        printf("Nombre:\n");
        scanf("%s", tempnam);
        printf("Calificacion:\n");
        scanf("%d", &j);
        InsertaCompu(nombreArc,tempnam, j);
        printf("Otro?\n");
        scanf("%d", &fin);
    }
    printf("Inmprimir?\n");
    scanf("%d", &fin);
    if(!fin){
        ImprimeCompu(nombreArc);
    }   
    return 0;
}
