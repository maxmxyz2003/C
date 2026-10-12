#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 10 // Tamaño de la tabla hash

typedef struct {
    int key;
    int value;
} HashEntry;
typedef struct {
    HashEntry* entries[SIZE];
} HashTable;

HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < SIZE; i++) {
        hashTable->entries[i] = NULL;
    }
    return hashTable;
}
int hashFunction(int key) {
    return key % SIZE;
}
void insert(HashTable* hashTable, int key, int value) {
    HashEntry* entry = (HashEntry*)malloc(sizeof(HashEntry));
    entry->key = key;
    entry->value = value;
    int hashIndex = hashFunction(key);
    int index = hashIndex;
    while (hashTable->entries[index] != NULL) {
        index = (index + 1) % SIZE; // Avance simple
        if (index == hashIndex) {
            printf("Tabla hash llena. No se puede insertar el elemento.\n");
            return;
        }
    }
    hashTable->entries[index] = entry;
}
int search(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key);
    int index = hashIndex;
    while (hashTable->entries[index] != NULL) {
        if (hashTable->entries[index]->key == key) {
            return hashTable->entries[index]->value;
        }
        index = (index + 1) % SIZE; // Avance simple
        if (index == hashIndex) {
            break; // Se ha recorrido toda la tabla sin encontrar el elemento
        }
    }
    return -1; // Elemento no encontrado
}

void delete(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key);
    int index = hashIndex;
    while (hashTable->entries[index] != NULL) {
        if (hashTable->entries[index]->key == key) {
            free(hashTable->entries[index]);
            hashTable->entries[index] = NULL;
            return;
        }
        index = (index + 1) % SIZE; // Avance simple
        if (index == hashIndex) {
            break; // Se ha recorrido toda la tabla sin encontrar el elemento
        }
    }
    printf("Elemento no encontrado en la tabla hash.\n");
}
void displayHashTable(HashTable* hashTable) {
    printf("Tabla Hash:\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashTable->entries[i] != NULL) {
            printf("Posición %d: (Clave: %d, Valor: %d)\n", i, hashTable->entries[i]->key, hashTable->entries[i]->value);
        } else {
            printf("Posición %d: Vacía\n", i);
        }
    }
}
int main() {
    HashTable* hashTable = createHashTable();
    insert(hashTable, 5, 100);
    insert(hashTable, 15, 200);
    insert(hashTable, 25, 300);
    insert(hashTable, 35, 400);
    insert(hashTable, 45, 500);
    insert(hashTable, 55, 600);
    displayHashTable(hashTable);
    int value = search(hashTable, 35);
    if (value != -1) {
        printf("Valor encontrado: %d\n", value);
    } else {
        printf("Elemento no encontrado en la tabla hash.\n");
    }
    delete(hashTable, 25);
    displayHashTable(hashTable);
    return 0;
}
