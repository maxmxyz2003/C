#include <stdio.h>
#include <stdlib.h>
void hallar(int mat[100][100], int arr[], int n1, int n2){
    int Non=1;
    int inic=0;
    while (Non==1){
        int elemIg=0;
        for (int i=0;i<n1;i++){
            for (int j=0;j<n1;j++){
                if (mat[i][j]==arr[0] && n2<=(n1-j)){
                    for (int c=0;c<n2;c++){
                        if(mat[i][j+c]==arr[c]){
                            elemIg++;
                            if (elemIg==n2){
                                printf("The array is in the matrix");
                                Non=0;
                            }
                        }
                    }           
                }
            }       
        }
    }
}

int main(int argc, char *argv[]) {
	int matx[4][4]={{1,2,1,1},{4,5,6,5},{7,8,9,10},{0,1,2,6}};
    int arrg[3][4]={1,2,1};
    hallar(matx, arrg, 4, 3);
}//not completed
