#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
    void* data;
    size_t size;
} GenericStruct;
// Function to initialize a GenericStruct
GenericStruct* createGenericStruct(void* data, size_t size) {
    GenericStruct* gs = (GenericStruct*)malloc(sizeof(GenericStruct));
    if(gs){
        gs->data = malloc(size);
        if(gs->data){
            memcpy(gs->data, data, size);
            gs->size = size;
            return gs;
        }else
            free(gs);
    }
    return NULL;
}
// Function to print the contents of a GenericStruct
void printGenericStruct(GenericStruct* gs) {
    printf("Data: ");
    for (size_t i = 0; i < gs->size; i++) {
        printf("%02X ", *((unsigned char*)gs->data + i));
    }
    printf("\nSize: %zu bytes\n", gs->size);
}
// Function to release memory used by a GenericStruct
void destroyGenericStruct(GenericStruct* gs) {
    if (gs) {
        free(gs->data);
        free(gs);
    }
}
int main() {
    // Create an integer array and a character array
    int intArray[] = {1, 2, 3, 4, 5};
    char charArray[] = {'H', 'e', 'l', 'l', 'o'};
    // Create GenericStruct instances for both arrays
    GenericStruct* intStruct = createGenericStruct(intArray, sizeof(intArray));
    GenericStruct* charStruct = createGenericStruct(charArray, sizeof(charArray));
    // Print the contents and size of both GenericStructs
    printf("Generic Struct for Integer Array:\n");
    printGenericStruct(intStruct);
    printf("\nGeneric Struct for Character Array:\n");
    printGenericStruct(charStruct);
    // Clean up memory
    destroyGenericStruct(intStruct);
    destroyGenericStruct(charStruct);
    return 0;
}
