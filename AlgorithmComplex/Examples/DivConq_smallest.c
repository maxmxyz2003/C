#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
int searchSmallestRec(int arr[], int h, int l){
    if(h-l>=1){
        int mid=(h+l)/2;
        int b1=searchSmallestRec(arr,h,mid+1);
        int b2=searchSmallestRec(arr,mid,l);
        return b1>b2?b1:b2;
    }
    return arr[h];
}
int main(){
    int arr[]={2,4,6,102,8,9,2,77,88};
    printf("%d", searchSmallestRec(arr,sizeof(arr)/sizeof(arr[0])-1,0));
    return 0;
}
