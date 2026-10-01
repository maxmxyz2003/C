#include <stdio.h>
#include <stdlib.h>
void analyzeGrades(FILE* inputFile, FILE* outputFile) {
    char name[50];
    int grade;
    int totalGrades = 0;
    int highestGrade = 0;
    int lowestGrade = 100;
    int sumGrades = 0;
    while (fscanf(inputFile, "%s %d", name, &grade) == 2) {
        totalGrades++;
        sumGrades += grade;

        if (grade > highestGrade) {
            highestGrade = grade;
        }

        if (grade < lowestGrade) {
            lowestGrade = grade;
        }
    }
    double averageGrade = (double)sumGrades / totalGrades;
    fprintf(outputFile, "Total Grades: %d\n", totalGrades);
    fprintf(outputFile, "Average Grade: %.2lf\n", averageGrade);
    fprintf(outputFile, "Highest Grade: %d\n", highestGrade);
    fprintf(outputFile, "Lowest Grade: %d\n", lowestGrade);
}
int main() {
    FILE* inputFile = fopen("grades.txt", "r");
    if (inputFile == NULL) {
        printf("Error opening input file\n");
        return 1;
    }
    FILE* outputFile = fopen("grade_analysis.txt", "w");
    if (outputFile == NULL) {
        printf("Error opening output file\n");
        return 1;
    }
    analyzeGrades(inputFile, outputFile);
    fclose(inputFile);
    fclose(outputFile);
    printf("Grade analysis completed\n");
    return 0;
}
