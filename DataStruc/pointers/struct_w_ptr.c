#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Date {
    int *day;
    int *month;
    int *year;
};

struct Person {
    int *age;
    double *w;
    char *Name;
    struct Date *birthday;
};

int createPer(struct Person **p) {
    *p = (struct Person*)malloc(sizeof(struct Person));
    if (*p) {
        (*p)->age = (int*)malloc(sizeof(int));
        (*p)->w = (double*)malloc(sizeof(double));
        (*p)->Name = (char*)malloc(40 * sizeof(char));
        (*p)->birthday = (struct Date*)malloc(sizeof(struct Date));
        if ((*p)->birthday) {
            (*p)->birthday->day = (int*)malloc(sizeof(int));
            (*p)->birthday->month = (int*)malloc(sizeof(int));
            (*p)->birthday->year = (int*)malloc(sizeof(int));
            return 1;
        }
    }
    return 0;
}
struct Person* asigData(int Age, double Weight, char *name, int Day, int Month, int Year) {
    struct Person* myP = NULL;
    if (createPer(&myP)) {
        *(myP->age) = Age;
        *(myP->w) = Weight;
        strcpy(myP->Name, name);
        *(myP->birthday->day) = Day;
        *(myP->birthday->month) = Month;
        *(myP->birthday->year) = Year;
        return myP;
    }
    return NULL;
}
void printData(struct Person* p) {
    printf("Name: %s, Age: %d, Weight: %lf, Birthday: %d/%d/%d\n", p->Name, *(p->age), *(p->w), *(p->birthday->day), *(p->birthday->month), *(p->birthday->year));
}
int main() {
    struct Person* p = NULL;
    p = asigData(17, 65.5, "Shaggy", 13, 9, 1969);
    if (p != NULL) {
        printData(p);
    }
    return 0;
}
