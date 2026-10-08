#include <stdio.h>
#include <ctype.h>
#include <string.h>
void fX(const int *ptrI){
    //*ptrI=100;
}
int main(void){
    int x=5;
    int y;
    const int *const ptr=&x;
    printf("%d\n", *ptr);
    // *ptr=7;
    // ptr=y;
    x++;
    printf("%d\n", *ptr);
    return 0;
}
