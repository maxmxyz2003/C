#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int main() {
    char nombre[100];
    FILE *fp;
    fp=fopen("data.txt", "w");
    fprintf(fp,"HOLA MUNDO");
    fclose(fp);
    FILE *fr; 
    fr=fopen("data.txt", "r");
    while (!feof(fp))
    {
        fscanf(fp, "%s", nombre);
        printf("%s", nombre);
        printf(" ");
    }
    fclose(fr);    
}
