#include <stdio.h>
#include <stdlib.h>
void rellena(int arr[100], int index){
    if(index==0)
        arr[0]=0;
    else{
        rellena(arr,index-1);
        arr[index]=4*index+arr[index-1];
    }
}

int main(void){
    int tam;
    scanf("%d", &tam);    
    int arr[tam];
    rellena(arr, tam-1);
    for (int i = 0; i < tam; i++){
        printf("%d ", arr[i]);
    }
}
