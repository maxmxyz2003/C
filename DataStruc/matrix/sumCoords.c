#include <stdio.h>
int hallar(int mat[100][100], int arr_col[100], int arr_row[100], int numElem){
    int suma=0;
    for(int i=0; i<numElem;i++){
        //printf("%d %d \n", fil, col);
        // printf("%d \n", mat[fil][col]);
        suma+=(mat[arr_row[i]][arr_col[i]]);
    }
    return suma;
}
int main(){
    //printf("XD");
    int elem, colums, filas;
    printf("Elementos a sumar\n");
    scanf("%d",&elem);
    int arr_col[elem];
    int arr_row[elem];
    printf("Dimensiones de matriz\n");
    scanf("%d %d",&colums, &filas);
    int mat[filas][colums];
    // int xd=(sizeof(arr_col));
    // printf("%d", xd);
    printf("coordenada de columna y fila\n");
    for (int i = 0; i < elem; i++)
    {
        scanf("%d %d", &arr_col[i], &arr_row[i]);
    }
    printf("Elementos de matriz\n");    
    for (int i = 0; i < filas; i++)
    {
        for (int j = 0; j < colums; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    int suma=0;
    
    printf("Elementos selecc\n");
    for (int i = 0; i < elem; i++)
    {
        printf("%d ",mat[arr_row[i]][arr_col[i]]);
        suma+=mat[arr_row[i]][arr_col[i]];
   }
    printf("\nsuma \n%d \n", suma);
    // int xd=hallar(mat, arr_col, arr_row, elem);
    // printf("%d", xd);
}
