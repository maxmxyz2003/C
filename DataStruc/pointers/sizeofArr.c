#include <stdio.h>
#include <ctype.h>
#include <string.h>
size_t CalcTam(float *ptrF){
    return sizeof(ptrF);
}
int main(){
    float arr[20];
    printf("Num de bytes %d \n Num de bytes por fx %d\n", sizeof(arr), CalcTam(arr));
    return 0;
    /*
    ptrB=arr; / ptrB=&arr[0];
    desplazar ptr
    *(ptrB+3);
    */
}
