#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char nombre[50];
    int edad;
    float peso;
}Persona;

int AsignMem(Persona ** persona){
    *persona=(Persona*)malloc(sizeof(Persona));
    if (*persona){
        return 1;
    }else{
        printf("Asignacion de memoria fallido.\n");
        return 0;
    }
}
void ModData(Persona * persona, char *nNombre, int nEdad, float nPeso){
    persona->edad=nEdad;
    persona->peso=nPeso;   
    strcpy(persona->nombre, nNombre);
}
void ImprimirData(Persona *per){
    printf("Nombre: %s, Edad: %d, Peso: %f\n", per->nombre,per->edad,per->peso );
}
int main(void){
    Persona * per;
    if(AsignMem(&per)){
        ModData(per, "Santos Saul Alvarez Barragan", 33, 73.1);
        ImprimirData(per);
        ModData(per, "Floyd Joy Mayweather", 46, 69.9);
        ImprimirData(per);
    }
    return 0;
}

