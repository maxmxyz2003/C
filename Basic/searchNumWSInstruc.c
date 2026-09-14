#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
int Square(int num){
    for(int i=0;i<num;i++){
        if(i*i==num)
            return 1;
    }
    return 0;
}
void searchNums(){
    for (int i = 0; i < 1000; i++){
        if(i%13==1&&i%7==0&&Square(i)){
            printf("%d ", i);
        }
    }    
}
int main(){   
    searchNums();
    return 0;
}
