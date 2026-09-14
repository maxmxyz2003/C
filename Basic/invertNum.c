#include <stdio.h>
#include <stdlib.h>

void invierte_num(long long int numero, long long int *num_inv);

int main(void){
    long long int num,num_inv;
    scanf("%lld",&num);
    invierte_num(num,&num_inv);
    printf("%lld",num_inv);
    return 0;
}
void invierte_num(long long int numero, long long int *num_inv){
    (*num_inv)=0;
    while (numero!=0)
    {   
        (*num_inv)=(*num_inv)*10+numero%10;
        numero/=10;
    }
    
}
