
// Libraries
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// Total size of the array
// You should change N for the experiments according to the description (see PDF)
#define N 50
// Function declaration
// Array functions
// Prints an array of size N
// Fills an existing array with random values
void createArray(int array[N]){
   time_t t;
   srand((unsigned)time(&t));
   for (int i = 0; i < N; i++){
      // NOTE: If N is large try to have large numbers in the array
      // otherwise the array would contain many repeated elements
      array[i] = rand();
   }
}
//QUICKSORT B(n)=nlog(n), A(n)=nlog(n), W(n)=n^2 
void swap(int *a, int *b){
   long int t = *a;
   *a = *b;
   *b = t;
}
int Partitition(int arr[], int A, int D){
   int pivot = arr[D]; // Se elige el pivote como el último elemento del array
   int j = A; // Se inicializa el índice de referencia como A  
   for (int i = A; i < D; i++){
      if (arr[i] < pivot){ // Si el elemento actual es menor que el pivote
         swap(&arr[i], &arr[j]); // Se intercambian los elementos y se incrementa j
         j++;
      }
   }
   swap(&arr[j], &arr[D]); // Se coloca el pivote en su posición correcta
   return j; // Se devuelve el índice de referencia
}
void QuickSort_Asc(int arr[], int A, int D){
   if (A < D){ // Si no se ha alcanzado el caso base (cuando A == D)
      int pivot = Partitition(arr, A, D); // Se obtiene la posición del pivote
      
      // Se ordenan recursivamente las dos mitades del array
      QuickSort_Asc(arr, A, pivot - 1); // Mitad izquierda
      QuickSort_Asc(arr, pivot + 1, D); // Mitad derecha
   }
   // No se necesita una acción específica cuando A == D porque ya está ordenado
}

// Declaration of your search functions
int BinSearchRec(int array[N], int l, int h, int x){
    if(l>h){
        return -1;
    }else{
        int mid=(l+h)/2;
        if(x==array[mid]){
            return mid;
        }else if (x<array[mid]){
            return BinSearchRec(array,l,mid,x);
        }else{
            return BinSearchRec(array,mid+1,h,x);
        }
    }
}

//always in array
int BinSearchRecB(int array[N], int l, int h, int x){
    if(l>h){
        return -1;
    }else{
        int mid=(l+h)/2;
        if(x==array[mid]){
            return mid;
        }else if (x<array[mid]){
            return BinSearchRec(array,l,mid,x);
        }else{
            return BinSearchRec(array,mid+1,h,x);
        }
    }
}

// mid = floor
int BinSearchRec2(int array[N], int l, int h, int x){
    if(l>h){
        return -1;
    }else{
        int mid=l;
        if(x==array[mid]){
            return mid;
        }else if (x<array[mid]){
            return BinSearchRec2(array,l,mid,x);
        }else{
            return BinSearchRec2(array,mid+1,h,x);
        }
    }
}
int TerSearchB(int array[N], int l, int h, int x){
    if(l>h){
        return -1;
    }else{
        int T1=(l+h)/3;
        if(x==array[T1]){
            return T1;
        }else if (array[T1]<x &&array[T1*2]>x){
            return BinSearchRec2(array,T1,2*T1,x);
        }else if (array[T1]>x){
            return BinSearchRec2(array,l,T1,x);
        }else if (array[2*T1]<x){
            return BinSearchRec2(array,T1,h,x);
        }   
    }
}
int binarySearch(int array[], int l, int h, int x) {
    if (l <= h) { // No se necesita la condición l > h
        int mid = l + (h - l) / 2;
        if (array[mid] == x) {
            return mid;
        } else if (array[mid] < x) {
            return binarySearch(array, mid + 1, h, x);
        } else {
            return binarySearch(array, l, mid - 1, x);
        }
    }
    return -1; // Se asume que el elemento siempre se encontrará en la lista
}
int TerSearchA(int array[N], int l, int h, int x) {
    if (l <= h) {// Si el menor esta dentro de 
        int mid1 = l + (h - l) / 3; // Calculamos el 1er "tercil"
        int mid2 = h - (h - l) / 3; // Calculamos el 2do "tercil"
        if (array[mid1] == x)// Si está en el 2do tercil
            return mid1;
        if (array[mid2] == x)// Si esta en el 1er tercil
            return mid2;
        if (array[mid1] > x) // Si se se encuentra entre el primer tercil 
            return TerSearchA(array, l, mid1 - 1, x);
        else if (array[mid2] < x) // Si se se encuentra entre el segundo tercil
            return TerSearchA(array, mid2 + 1, h, x);
        else // Si se se encuentra entre el primer y segundo tercil
            return TerSearchA(array, mid1 + 1, mid2 - 1, x);
    }
    return -1; // Elemento no encontrado
}

int secSearch(int array[N],int x){
    for (int i = 0; i < N; i++){
        if (array[i]==x){
            return i;
        }
    }
    return -1;
}
void printArray(int array[N]){
    printf("\n");
    for (int i = 0; i < N; i++)
        printf("%d, ", array[i]);
}
// Main function where the sorting algorithm is called
int main(){
   // Array is static so that the compiler can store it beforehand in memory
   static int arr[N];
   // Variables to measure time
   clock_t t_ini, t_end;
   double t_elapsed;
   // Create the array with random elements
   createArray(arr);
    QuickSort_Asc(arr,0,N-1);
   // Check the initial time
   t_ini = clock();
   int s=1;
   int x=10000000;
   arr[N-1]=x;
    printArray(arr);
   printf("\nN=%d", N);
   printf("\nInitial time: %f", ((double)t_ini));
   // Start the search algorithm
    // int index=TerSearchA(arr,0,N-1,x);
    int index=binarySearch(arr,0,N-1,x);
    // int index=secSearch(arr,-1);
   // Check the final time and calculate the elapsed time
   t_end = clock() - t_ini;
//    printArray(arr);
   printf("\nFinal time: %f", ((double)t_end));
   t_elapsed = ((double)t_end) / CLOCKS_PER_SEC;
   printf("\nTotal time: %f segs", t_elapsed);
   printf("Index of %d: %d", x,index);
   return 0;
}
