#include <stdio.h>
int main (void){
    int b[]={11,22,33,44};
    int *ptrB=b;
    int mov;
    for (int i = 0; i < 4; i++)
        printf("b[%d]=%d ", i, b[i]);
    printf("\n");
    for (mov = 0; mov < 4; mov++)
        printf("*(b+%d)=%d ", mov, *(b+mov));
    printf("\n");
    for (int i = 0; i < 4; i++)
        printf("ptrB[%d]=%d ", i, ptrB[i]);
    printf("\n");
    for (mov = 0; mov < 4; mov++)
        printf("*(ptrB+%d)=%d ", mov, *(ptrB+mov));
}
