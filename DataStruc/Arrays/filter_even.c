#include <stdio.h>
#include <stdlib.h>
void rellena(int arr[100], int index,int arr2[100]){
    for (int i = 0; i <=index; i++){
        if (arr[i]%2==0){

        }
    }
}
int main(void){
    int tam;
    // printf("Numeros de elementos");
    scanf("%d", &tam);
    int arr[tam];
    int arr2[tam];
    for (int i = 0; i < tam; i++)
        scanf("%d",arr[i]);    
    rellena(arr, tam-1,arr2);
    for (int i = 0; i < tam; i++){
        printf("%d ", arr[i]);
    }
}
