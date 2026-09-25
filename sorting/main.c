// main.c
#include <stdio.h>
#include <stdlib.h>
  #include "mymath.h"
void BubbleSort(int arr[], int size) {
  int temp;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        temp = arr[j];
        arr[j] = arr[j + 1];
        arr[j + 1] = temp;
      }
    }
  }
}
//QUICKSORT B(n)=nlog(n), A(n)=nlog(n), W(n)=n^2 
void swap(long int *a, long int *b){
    long int t=*a;
    *a=*b;
    *b=t;
}
int Partitition(long int arr[], int A, int D){
    int pivot=arr[D];
    int j=A;
    for (int i = A; i < D; i++){
        if (arr[i]<pivot){
            swap(&arr[i],&arr[j]);
            j++;
        }
    }
    swap(&arr[j],&arr[D]);   
    return j;
}
void QuickSort_Asc(long int arr[], int A, int D){
    if(A<D){
        int pivot=Partitition(arr,A,D);
        QuickSort_Asc(arr,A,pivot-1);
        QuickSort_Asc(arr,pivot+1,D);
    }
}
void DisplayArray(long int arr[], int n){
    for (int i = 0; i < n; i++){
        printf("arr[%d]=%ld ",i,arr[i]);
    }
}

// MERGESORT Complexity O(nlog(n))
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
int encontrarMaximo(int arr[], int n) {
    int maximo = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    return maximo;
}
void RadixSort(int arr[], int n) {
    int maximo = encontrarMaximo(arr, n);// Realizar el conteo de frecuencia de cada dígito
    for (int exp = 1; maximo / exp > 0; exp *= 10) {
        int conteo[10] = {0}; // Inicializar el arreglo de conteo a 0
        // Contar la frecuencia de cada dígito en la posición 'exp'
        for (int i = 0; i < n; i++) {
            conteo[(arr[i] / exp) % 10]++;
        }
        // Actualizar el conteo para indicar la posición real de los dígitos en el arreglo ordenado
        for (int i = 1; i < 10; i++) {
            conteo[i] += conteo[i - 1];
        }
        // Construir el arreglo ordenado
        int salida[n];
        for (int i = n - 1; i >= 0; i--) {
            salida[conteo[(arr[i] / exp) % 10] - 1] = arr[i];
            conteo[(arr[i] / exp) % 10]--;
        }
        // Copiar el arreglo ordenado de salida al arreglo original
        for (int i = 0; i < n; i++) {
            arr[i] = salida[i];
        }
    }
}

int main(void){
    long int arr[]={5,4,7,88,32,43,11,15};
    DisplayArray(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n");
    QuickSort_Asc(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    DisplayArray(arr,sizeof(arr)/sizeof(arr[0]));
   //----
  int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr) / sizeof(arr[0]);
    printf("Arreglo original:\n");
    printArray(arr, arr_size);
    mergeSort(arr, 0, arr_size - 1);
    printf("Arreglo ordenado:\n");
    printArray(arr, arr_size);
}
