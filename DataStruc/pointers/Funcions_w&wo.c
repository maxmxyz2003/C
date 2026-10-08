#include <stdio.h>
void NumAlCubo_P(int *num){
    (*num)=(*num)*(*num)*(*num);
}
int cubo(int num){
    return num*num*num;
}
int main() {
    int num = 5;
    int num2=2;
    NumAlCubo_P(&num);
    int x=cubo(num2);
    printf("El cubo es: %d\n", num);
    printf("El cubo es: %d\n", x);
    return 0;
}
