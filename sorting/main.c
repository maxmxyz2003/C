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

int main(void){
    long int arr[]={5,4,7,88,32,43,11,15};
    DisplayArray(arr,sizeof(arr)/sizeof(arr[0]));
    printf("\n");
    QuickSort_Asc(arr,0,sizeof(arr)/sizeof(arr[0])-1);
    DisplayArray(arr,sizeof(arr)/sizeof(arr[0]));
}
