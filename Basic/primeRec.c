#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define NUM 113

int EsPrimoRec(int num, int cop){
    if (cop==1){
        return 1;
    }else if(num%cop==0){
        return 0;
    }else{
        return EsPrimoRec(num,cop-1);
    }
}

int main(void)
{
    
    if (EsPrimoRec(NUM,NUM-1)){
        printf("Primo");
    }else{
        printf("No primo");
    }

    return 0;
}
