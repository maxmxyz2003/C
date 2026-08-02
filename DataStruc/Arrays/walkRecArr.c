#include <stdio.h> 
#include <stdlib.h>
void recorrer_arr_rec_asc(int arr[100], int tam, int index){
    if (index==tam-1)
    {
        printf("%d \n",arr[index]);
    }else{
        printf("%d ",arr[index]);
        index++;
        recorrer_arr_rec_asc(arr,tam,index);
    }
}
void recorrer_arr_rec_desc(int arr[100], int tam){
    if (tam-1==0)
    {
        printf("%d ",arr[tam-1]);
    }else{
        printf("%d ",arr[tam-1]);
        recorrer_arr_rec_desc(arr,tam-1);
    }   
}

int main(void){
    int numero=0;
    int arre[]={1,2,3,4,45,7};
    recorrer_arr_rec_asc(arre, 6,numero);
    recorrer_arr_rec_desc(arre, 6);
    
}
