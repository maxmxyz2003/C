#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// Define a generic structure GEN1
typedef struct {
    char color[20];
} GEN1;
// Define a PRODUCT structure with a void pointer for generic data
typedef struct {
    void *ptrG;
    int profits;
    char prodName[50];
    char id[30];
} PRODUCT;
// Function to allocate memory for the generic data
void AllocGenericData(PRODUCT *product, size_t size) {
    product->ptrG = malloc(size);
    if (product->ptrG == NULL) {
        fprintf(stderr, "Memory allocation failed.\n");
        exit(1);
    }
}
// Function to save data into the generic structure
void SaveGenericData(PRODUCT *product, void *data, size_t sizeofdata) {
    memcpy(product->ptrG, data, sizeofdata);
}
// Function to retrieve data from the generic structure
void GetGenericData(PRODUCT *product, void *data, size_t size) {
    memcpy(data, product->ptrG, size);
}
// Function to free memory
void FreeGenericData(PRODUCT *product) {
    free(product->ptrG);
    product->ptrG = NULL;
}
int main(void) {
    // Create a PRODUCT structure
    PRODUCT product;
    // Create and initialize generic data of type GEN1
    GEN1 genericData;
    strcpy(genericData.color, "Blue");
    // Allocate memory for generic data
    AllocGenericData(&product, sizeof(GEN1));
    // Save the generic data into the PRODUCT structure
    SaveGenericData(&product, &genericData, sizeof(GEN1));
    // Retrieve the generic data from the PRODUCT structure
    GEN1 retrievedData;
    GetGenericData(&product, &retrievedData, sizeof(GEN1));
    // Print the retrieved data
    printf("Color: %s\n", retrievedData.color);
    // Free memory
    FreeGenericData(&product);
    return 0;
}
