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
/*
#include <stdio.h>
#include <stdlib.h>
// Define a structure
struct Student {
    int id;
    char name[50];
};
// Function to allocate memory for a struct pointer
void allocateMemory(struct Student** ptr) {
    *ptr = (struct Student*)malloc(sizeof(struct Student));
    if (*ptr == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
}
// Function to initialize the values of a struct
void initializeValues(struct Student* ptr, int id, const char* name) {
    ptr->id = id;
    strcpy(ptr->name, name);
}
// Function to print the values of a struct
void printValues(struct Student* ptr) {
    printf("Student ID: %d\n", ptr->id);
    printf("Student Name: %s\n", ptr->name);
}
// Function to deallocate memory for a struct pointer
void deallocateMemory(struct Student** ptr) {
    free(*ptr);
    *ptr = NULL;
}
int main() {
    struct Student* studentPtr = NULL;
    // Allocate memory for the struct pointer
    allocateMemory(&studentPtr);
    // Initialize the values of the struct
    initializeValues(studentPtr, 12345, "John Doe");
    // Print the values of the struct
    printValues(studentPtr);
    // Deallocate memory
    deallocateMemory(&studentPtr);
    return 0;
}
*/
