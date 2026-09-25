#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
void BiggestAndSmallest_2n(int *arr, int tam, int *Big, int *small){
    *Big=-INT_MAX;*small=INT_MAX;
    for (int  i = 0; i < tam; i++){// Aqui a fuerzas hace 2 comparaciones 
        if (*(arr+i)>*Big){
            *Big=*(arr+i);
        }if (*(arr+i)<*small){
            *small=*(arr+i);
        }
    }
}

int main(void){
    int arr[]={1,43,32,6,7,8,89};
    int TheBiggest,TheSmallest;
    BiggestAndSmallest_2n(arr,sizeof(arr)/sizeof(int), &TheBiggest,&TheSmallest);
    printf("%d %d\n",TheBiggest,TheSmallest);
    return 0;
}
