#include <stdio.h>
#include <string.h>
int main() {
    char tempnam[100];
    FILE *fp;
    fp = fopen("data.txt", "w");
    fprintf(fp, "Este archivo se lee varias veces");
    fclose(fp);
    FILE *fr;
    fr = fopen("data.txt", "r");
    int j = 1, c=0;  //Iniciar con la primera palabra
    while (fscanf(fr, "%s", tempnam) != EOF) { // va escaneando palabra 
        int len = strlen(tempnam);  
        for (int i = 0; i < j; i++) {
            fseek(fr, len+1, SEEK_CUR-len);
            printf("%s ", tempnam);
        }
        j++;
    }// SET_CUR=ACTUAL   , SET_SEEK = origenm SET_END = final   
    fclose(fr);
    return 0;
}
