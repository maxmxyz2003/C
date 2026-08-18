  #include <stdio.h>
int max(int a, int b) {
    return (a > b) ? a : b;
}
int sum(int arr[], int start, int end) {
    int total = 0;
    for (int i = start; i <= end; i++) {
        total += arr[i];
    }
    return total;
}
int maximize_sublist_difference(int arr[], int start, int end) {
    if (start >= end) {
        return 0;
    }
    int mid = (start + end) / 2;    
    int left_sum = sum(arr, start, mid);
    int right_sum = sum(arr, mid + 1, end);
    int max_diff = max(left_sum - right_sum,max(maximize_sublist_difference(arr, start, mid),maximize_sublist_difference(arr, mid + 1, end)));
    return max_diff;
}
int main() {
    int arr[] = {10,9,8,7,4,3};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d\n", n);
    int result = maximize_sublist_difference(arr, 0, n - 1);
    printf("Diferencia maxima de las sumas de las sublistas: %d\n", result);
    return 0;
}
