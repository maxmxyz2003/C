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
int main(void) {
    char tempnam[100] = "Jorge_Alberto_Suarez_Saldaña";
    int j = 10;
    int clave=355992;
    int clave2;
    int calif;
    char * nombre=(char*)malloc(strlen(tempnam)*sizeof(char));
    FILE *fp;
    fp = fopen("data.bin", "wb");
    if (fp == NULL){
        perror("Error opening file");
        return 1;
    }
    a();
    fwrite(tempnam, sizeof(char), strlen(tempnam), fp);
    fwrite(&j, sizeof(int), 1, fp);
    fwrite(&clave, sizeof(int), 1, fp);    
    fclose(fp);
    FILE *fr;
    fr = fopen("data.bin", "rb");
    if (fr == NULL) {
        perror("Error opening file");
        return 1;
    }
    fread(nombre, sizeof(char), strlen(tempnam), fr); 
    fread(&calif, sizeof(int), 1, fr); 
    fread(&clave2, sizeof(int), 1, fr); 
    printf("Nombre: %s Clave: %d Tiene: %d\n", nombre, clave2, calif);
    fclose(fr);
    return 0;
}
