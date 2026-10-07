#include <stdio.h>
#include <limits.h>
int Hallarmenor(int arr[], int tam){
    if (tam == 1)
        return arr[0];
    else{
        int smallest = Hallarmenor(arr + 1, tam - 1);
        return (arr[0] < smallest) ? arr[0] : smallest;
    }
}
int Hallarmayor(int *arr, int tam){
    if (tam == 1)
        return *(arr+0);
    else{
        int mayor = Hallarmayor(arr + 1, tam - 1);
        return (*(arr+0) > mayor) ? *(arr+0) : mayor;
    }
}
int main(){
    int arr[] = {9, 5, 2, 7, 1, 6};
    int tam = sizeof(arr)/sizeof(arr[0]);
    int Elmenor = Hallarmenor(arr, tam);
    printf("El menor es: %d\n", Elmenor);
    int Elmayor = Hallarmayor(arr, tam);
    printf("El mayor es: %d\n", Elmayor);   
    return 0;
}
