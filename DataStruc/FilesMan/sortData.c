#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
void saveDataToFile(int data[], int size, const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("Error opening file for writing.\n");
        return;
    }

    fwrite(data, sizeof(int), size, file);
    fclose(file);

    printf("Data saved to file successfully.\n");
}

void sortData(int data[], int size) {
    // Use any sorting algorithm of your choice
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (data[j] > data[j + 1]) {
                int temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }

    printf("Data sorted successfully.\n");
}

void printData(int data[], int size) {
    printf("Sorted data:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
}

int main() {
    int data[MAX_SIZE];
    int size;

    printf("Enter the number of elements (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE || size <= 0) {
        printf("Invalid size. Exiting program.\n");
        return 0;
    }

    printf("Enter the elements:\n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    saveDataToFile(data, size, "data.bin");
    sortData(data, size);
    printData(data, size);

    return 0;
}
