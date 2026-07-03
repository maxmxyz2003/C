#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void replaceWordInFile(const char* filename, const char* wordToReplace, const char* replacement) {
    FILE* inputFile = fopen(filename, "r");
    FILE* outputFile = fopen("temp.txt", "w");
    if (inputFile == NULL || outputFile == NULL) {
        printf("Error opening file.\n");
        return;
    }
    char line[100];
    while (fgets(line, sizeof(line), inputFile) != NULL) {
        char* found = strstr(line, wordToReplace);
        while (found != NULL) {
            // Replace the word with the replacement string
            strncpy(found, replacement, strlen(replacement));
            found = strstr(found + 1, wordToReplace);
        }
        fputs(line, outputFile);
    }
    fclose(inputFile);
    fclose(outputFile);
    remove(filename);
    rename("temp.txt", filename);
    printf("Replacement complete.\n");
}
int main() {
    const char* filename = "data.txt";
    const char* wordToReplace = "Este ";
    const char* replacement = "Ese ";
    replaceWordInFile(filename, wordToReplace, replacement);
    return 0;
}
