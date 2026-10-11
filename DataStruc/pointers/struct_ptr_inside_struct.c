#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    char nombre[40];
    char apellido[40];
} Nombre;
typedef struct {
    Nombre* nombre;
    int edad;
    float peso;
} Persona;
//Asignacion de memoria a los apuntadores 
void AsignMem(Persona** personaPtr) {
    *personaPtr = (Persona*)malloc(sizeof(Persona));
    if (*personaPtr == NULL){//Si no hay espacio
        printf("Memory allocation for Persona failed.\n");
        exit(1);
    }
    (*personaPtr)->nombre = (Nombre*)malloc(sizeof(Nombre));//Asignamos memoria al apuntador a la estructura Nombre
    if (!(*personaPtr)->nombre){//Si no hay espacio para Nombre
        printf("Memory allocation for nombre failed.\n");
        free(*personaPtr);
        exit(1);
    }
}
//Asignar nuevos valores a la estructura
void initPerson(Persona* persona, const char* nombre, const char* apellido, int edad, float peso) {
    strcpy(persona->nombre->nombre, nombre);
    strcpy(persona->nombre->apellido, apellido);
    persona->edad = edad;
    persona->peso = peso;
}
void ImprimeData(Persona* persona) {
    printf("Nombre: %s %s\n", persona->nombre->nombre, persona->nombre->apellido);
    printf("Edad: %d\n", persona->edad);
    printf("Peso: %.2f\n", persona->peso);
}
//Liberar memoria
void LiberarMem(Persona** personaPtr) {
    free((*personaPtr)->nombre);
    free(*personaPtr);
    *personaPtr = NULL;
}
int main(void){
    Persona* personaPtr = NULL;
    AsignMem(&personaPtr);
    initPerson(personaPtr, "John", "Doe", 25, 70.5);
    ImprimeData(personaPtr);
    LiberarMem(&personaPtr);
    return 0;
}
