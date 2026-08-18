#include <stdio.h> 
#include <stdlib.h>

void arrOrd(int arr[10], int tam, int arr_r[10]){
    int TmpSmallest_P=INT_MAX,TmpSmallest_U=INT_MAX;
    int index=0;
    for (int i = 0; i < tam; i++){
        for (int j = 0; j < tam-1; j++){
            if (arr[j]>arr[j+1]){
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }            
        }
    }
    for(int i = 0;i<tam; i++){
        if (arr[i]%2==0)
            arr_r[index++]=arr[i];
    }
    for(int i = 0;i<tam; i++){
        if (arr[i]%2==1)
            arr_r[index++]=arr[i];
    }
}
int main(){
    int arr[10]={1,3,4,56,65,2};
    int arr2[10];
    arrOrd(arr,6,arr2);
    for(int i = 0;i<6; i++)
        printf("arr_r[%d]=%d\n",i,arr2[i]);
    
}
