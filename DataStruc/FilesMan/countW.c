#include <stdio.h>
#include <stdlib.h>
int countWords(FILE* file) {
    int count = 0;
    char ch;
    while ((ch = fgetc(file)) != EOF) {
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            count++;
        }
    }
    return count + 1; // Add 1 to account for the last word
}
int main() {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    int wordCount = countWords(inputFile);
    fclose(inputFile);
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }
    fprintf(outputFile, "Word count: %d\n", wordCount);
    fclose(outputFile);
    printf("Word count: %d\n", wordCount);
    return 0;
}
