#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int countPair(int l, int h, int arr[]){
    if(h-l>=1){
        int mid=(h+l)/2;
        int c1=countPair(l,mid,arr);
        int c2=countPair(mid+1,h,arr);
        if (arr[mid]%2==0&&arr[mid+1]%2==0){
            c1++;
        }return c1+c2;
    }
    return 0;
}
