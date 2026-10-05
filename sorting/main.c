// Libraries
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
// Total size of the array
// You should change N for the experiments according to the description (see PDF)
#define N 15
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
      array[i] = rand() % 5000;
   }
}
// Declaration of your sorting functions
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
// RADIXSORT Complexity
int encontrarMaximo(int arr[], int n) {
    int maximo = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    return maximo;
}
// Función para ordenar los elementos usando Radix Sort
void RadixSort(int arr[], int n) {
    int maximo = encontrarMaximo(arr, n);// Realizar el conteo de frecuencia de cada dígito
    for (int exp = 1; maximo / exp > 0; exp *= 10) {
        int conteo[10] = {0}; // Inicializar el arreglo de conteo a 0
        // Contar la frecuencia de cada dígito en la posición 'exp'
        for (int i = 0; i < n; i++) {
            conteo[(arr[i] / exp) % 10]++;
        }
        // Actualizar el conteo para indicar la posición real de los dígitos en el arreglo ordenado
        for (int i = 1; i < 10; i++) {
            conteo[i] += conteo[i - 1];
        }
        // Construir el arreglo ordenado
        int salida[n];
        for (int i = n - 1; i >= 0; i--) {
            salida[conteo[(arr[i] / exp) % 10] - 1] = arr[i];
            conteo[(arr[i] / exp) % 10]--;
        }
        // Copiar el arreglo ordenado de salida al arreglo original
        for (int i = 0; i < n; i++) {
            arr[i] = salida[i];
        }
    }
}


// MERGESORT Complexity O(nlog(n))
void merge(int arr[], int l, int m, int r){
   int i, j, k;
   int n1 = m - l + 1; // Tamaño del primer subarray
   int n2 = r - m; // Tamaño del segundo subarray
   int L[n1], R[n2];// Crear arreglos temporales   
   // Copiar datos a los arreglos temporales L[] y R[]
   for (i = 0; i < n1; i++)
      L[i] = arr[l + i];
   for (j = 0; j < n2; j++)
      R[j] = arr[m + 1 + j];
   // Combinar los arreglos temporales en arr[l..r]
   i = 0; // Índice inicial del primer subarray
   j = 0; // Índice inicial del segundo subarray
   k = l; // Índice inicial del arreglo combinado
   while (i < n1 && j < n2){
      if (L[i] <= R[j]){
         arr[k] = L[i]; // Copiar el elemento de L[]
         i++;
      }
      else{
         arr[k] = R[j]; // Copiar el elemento de R[]
         j++;
      }
      k++;
   }
   // Copiar los elementos restantes de L[], si es que hay alguno
   while (i < n1){
      arr[k] = L[i];
      i++;
      k++;
   }
   // Copiar los elementos restantes de R[], si es que hay alguno
   while (j < n2){
      arr[k] = R[j];
      j++;
      k++;
   }
}


// INSERTIONSORT Complexity B(n)=n, A(n)=n^2 , W(n)=n^2
void insertionSort(int arr[], int n){
   int key;
   for (int i = 1; i < n; i++){ // Recorremos el array desde el segundo elemento hasta el final
      key = arr[i]; // Almacenamos el valor del elemento actual en 'key'
      int j = i - 1; // Inicializamos 'j' como el índice del elemento anterior al actual
      while (j >= 0 && arr[j] > key){ // Iteramos mientras 'j' sea mayor o igual a 0 y el elemento en la posición 'j' sea mayor que 'key'
         arr[j + 1] = arr[j]; // Movemos el elemento en 'j' una posición hacia adelante
         j--; // Disminuimos 'j' para comparar con el siguiente elemento hacia atrás
      }
      arr[j + 1] = key; // Insertamos 'key' en la posición adecuada
   }
}
// SELECTIONSORT Complexity: O(n^2)
void selectionSort(int arr[], int n) {
   for (int i = 0; i < n - 1; i++) { // Recorremos el array desde el primer elemento hasta el penúltimo
      int minIndex = i; // Inicializamos 'minIndex' como el índice del elemento actual
      for (int j = i + 1; j < n; j++) { // Iteramos sobre los elementos restantes del array
         if (arr[j] < arr[minIndex]) { // Comparamos el elemento actual con el elemento mínimo
            minIndex = j; // Si encontramos un elemento menor, actualizamos 'minIndex'
         }
      }
      swap(&arr[minIndex], &arr[i]); // Intercambiamos el elemento más pequeño encontrado con el elemento en la posición 'i'
   }
}

void printArray(int array[N]){
   printf("\n\n");
   for (int i = 0; i < N; i++)
   {
      printf("%d, ", array[i]);
   }
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
   // WARNING: Only print the array for testing purposes and if N is small
   // printf("\nUNSORTED ARRAY:");
   // printArray(arr);
   // Check the initial time
   t_ini = clock();
   printf("N=%d", N);
   printf("\nInitial time: %f", ((double)t_ini));
   // Start the sorting algorithm
   QuickSort_Asc(arr,0,N-1);
   // mergeSort(arr,0,N-1);
   // insertionSort(arr, N);  
   // selectionSort(arr,N);
   // RadixSort(arr,N);
   // Check the final time and calculate the elapsed time
   t_end = clock() - t_ini;
   printf("\nFinal time: %f", ((double)t_end));
   t_elapsed = ((double)t_end) / CLOCKS_PER_SEC;
   printf("\nTotal time: %f segs", t_elapsed);
   // WARNING: Only print the array for testing purposes and if N is small
   // printf("\nSORTED ARRAY:");
   // printArray(arr);
   return 0;
}
