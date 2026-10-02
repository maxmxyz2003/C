#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>
int Prime(long int num, int div){
    if(div==1)
        return 1;
    else if(num%div==0)
        return 0;
    else
        return Prime(num, div-1);
}
int Prime2(long int num){
    for (long int i = 2; i < num; i++)
        if (num%i==0)
            return 0;
    return 1;
}
int BiggestPrime(long int *arr, int n){
    long int ref=INT_MIN;
    for (int i = 0; i <n; i++){
        if (arr[i]>ref&&Prime2(arr[i]))
            ref=arr[i];
    }
    return ref;
}
void DisplayArray(long int *arr, int n){
    for (int i = 0; i < n; i++)
        printf("%ld ",arr[i]);
}
int main(){
    long int arr[25];
    srand(time(NULL));
    for (int i = 0; i < 25; i++)
        arr[i]=rand()%500;
    DisplayArray(arr,25);
    printf("\n");
    printf("%ld", BiggestPrime(arr,25));
}
