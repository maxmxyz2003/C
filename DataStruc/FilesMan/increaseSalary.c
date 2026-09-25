#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int id;
    char name[50];
    double salary;
} Employee;
void extractDataFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Failed to open the file.\n");
        return;
    }
    fseek(file, 0, SEEK_SET);
    int number;
    char name[50];
    while (fscanf(file, "%d %s", &number, name) != EOF) {
        printf("Number: %d, Name: %s\n", number, name);
    }
    fclose(file);
}

void printFileRows(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file\n");
        return;
    }
    char line[1000];
    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }
    fclose(file);
}
void processEmployees(const char *inputFileName, const char *outputFileName)
{
    // Open the input file in read mode
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL)
    {
        printf("Error opening input file.\n");
        return;
    }
    // Open the output file in binary write mode
    FILE *outputFile = fopen(outputFileName, "wb");
    if (outputFile == NULL)
    {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return;
    }

    Employee employee;
    while (fscanf(inputFile, "%d %s %lf", &employee.id, employee.name, &employee.salary) == 3)
    {
        // Perform some operations on the employee data
        employee.salary *= 1.1; // Increase the salary by 10%
        // Write the modified employee data to the binary file
        fwrite(&employee, sizeof(Employee), 1, outputFile);
    }
    // Close the files
    fclose(inputFile);
    fclose(outputFile);
}
void printEmployees(const char *fileName)
{
    // Open the binary file in read mode
    FILE *file = fopen(fileName, "rb");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }
    Employee employee;
    while (fread(&employee, sizeof(Employee), 1, file) == 1)
    {
        // Print the employee data
        printf("ID: %d, Name: %s, Salary: %.2lf\n", employee.id, employee.name, employee.salary);
    }
    // Close the file
    fclose(file);
}
int main()
{
    const char *inputFileName = "employees.txt";
    const char *outputFileName = "employees.bin";

    // Process the employees data and store it in the binary file
    processEmployees(inputFileName, outputFileName);

    // Print the employee data from the binary file
    printEmployees(outputFileName);

    return 0;
}
