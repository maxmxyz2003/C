#include <stdio.h>
void towerOfHanoi(int n, int *cont, char from_rod, char to_rod, char aux_rod){
    if (n == 1){ //Base case: If it is the last move of the top 
        printf("\n Move disk 1 from rod %c to rod %c\n", from_rod, to_rod);
        return;
    }
    (*cont)++;
    //Else we have to move the new "top" to the aux rod to avoid the rule that makes this problem very hard   
    towerOfHanoi(n-1, cont,from_rod, aux_rod, to_rod);
    //We move the (n-1)-disk to the aux rod
    printf("\nDisk %d from %c to %c", n, from_rod, to_rod);
    //Finally we have to move the new top disk to the destiny rod
    towerOfHanoi(n-1, cont,aux_rod, to_rod, from_rod);
}
int main(){
    int n = 4; // Number of disks
    int cont=0;
    towerOfHanoi(n, &cont,'A', 'C', 'B');  // A, B and C are names of rods
    printf("%d", cont);
    return 0;
}
