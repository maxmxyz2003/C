#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int min(int a, int b) {
  if (a < b)
    return a;
  else if (a == b)
    return b;
  else
    return b;
}
void reset(int arr[100], int n) {
  for (int i = 0; i < n; i++) {
    arr[i] = 0;
  }
}
int searchChar(char c, int n, char *str, int *arr) {
  int cont = 0;
  for (int i = 0; arr[i] != '\0'; i++) {
    if (c == str[i]) {
      cont++;
    }
  }
  if (cont > 1)
    return 1;
  return 0;
}
void dynamic_largest_palindrome(char *str) {
  int n = strlen(str); // string length
  printf("\nInstance string: %s, n=%d\n", str,
         n);       // print lenght and the instance string
  int arr_indx[n]; // Array to store the index of the largest palindrome
  // initilize the array
  reset(arr_indx, n);
  // Find the largest palindrome
  // starting index of the palindrome
  int c_start = 0;
  int c_end = n;
  // Temporary start & end, and the definitive start and end
  int t_start, t_end, s, e;
  int T_c = 0;
  int c = 0;
  int p_len = 0; // The lenght of the palindrome
  // loop through the string to search and determine the largest palindrome
  while (c_start < c_end) {
    for (int i = n - 1; i > c_start; i--) { // loop through the string backwards
      if (str[c_start] == str[i] &&
          i - c_start + 1 > p_len) { // check if we consider this option
        // and make a verification of the possible lenght of the palindrome
        arr_indx[c_start] = 1;
        arr_indx[i] = 1;
        t_start = c_start;
        t_end = i;
        // check that is the largest making a tracking
        int c1 = t_start, c2 = t_end;
        while (c1 < c2) {
          for (int i = c2; i > c1; i--) {
            if (str[i] == str[c1 + 1]) {
              arr_indx[i] = 1;
              arr_indx[c1 + 1] = 1;
              break;
            }
          }
          c1++;
        }
        // Count the lenght of this temporary
        for (int i = t_start; i <= t_end; i++) {
          if (arr_indx[i]) {
            T_c++;
            // Check it is an simetric palindrome (...xx...) or a palindrome
            // with a separator (...xyx...)
            if ((arr_indx[i] && !arr_indx[i + 1] && arr_indx[i + 2] &&
                 str[i] == str[i + 2]) ||
                arr_indx[i] && !arr_indx[i + 1] && !arr_indx[i + 2]) {
              T_c++;
              arr_indx[i + 1] = 1;
            }
          }
        }
        if (T_c > p_len) {
          s = t_start;
          e = t_end;
          p_len = T_c;
          // for(int i=s;i<e;i++){
            // arr_indx[i]=searchChar(str[i], n, str, arr_indx);
          // }
        }
      }
    }
    // increment the starting index
    c_start++;
  }
  printf("Largest palindrome: ");
  if (p_len == 0) { // if there is no palindrome
    printf("No palindrome or %c\n", str[rand() % n]);
  } else { // if there is a palindrome
    for (int i = s; i <= e; i++) {
      if (arr_indx[i])
        printf("%c", str[i]); // print the palindrome without the index
    }
    printf("\n");
  }
}

// Function is palindrome
int is_Palindrome(char *str) {
  int n = strlen(str);
  printf("%d\n", n);
  for (int i = 0; i < n / 2; i++) {
    if (str[i] != str[n - i - 1]) {
      return 0;
    }
  }
  return 1;
}
// Function to print a substring str[low..high]
void printSubStr(const char *str, int low, int high) {
  for (int i = low; i <= high; ++i)
    printf("%c", str[i]);
}
// This function prints the longest palindrome substring
// It also returns the length of the longest palindrome
int longestPalSubstr(const char *str) {
  // Get length of input string
  int n = strlen(str);
  // All substrings of length 1 are palindromes
  int maxLength = 1, start = 0;
  // Nested loop to mark start and end index
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      int flag = 1;
      // Check palindrome
      for (int k = 0; k < (j - i + 1) / 2; k++)
        if (str[i + k] != str[j - k])
          flag = 0;
      // Palindrome
      if (flag && (j - i + 1) > maxLength) {
        start = i;
        maxLength = j - i + 1;
      }
    }
  }
  printf("Longest palindrome substring is: ");
  printSubStr(str, start, start + maxLength - 1);
  printf("\n");
  // Return length of LPS
  return maxLength;
}
/**********fgvhg***vhgvghvhv****/
int main(void){
  clock_t t_ini, t_end;
  double t_elapsed;
  // Origin
  printf("\nInitial time: %f\n", ((double)t_ini));
  t_ini = clock();
  dynamic_largest_palindrome("uwuwu");
  t_end = clock() - t_ini;
  printf("\nFinal time: %f", ((double)t_end));
  t_elapsed = ((double)t_end) / CLOCKS_PER_SEC;
  printf("\nTotal time: %f segs\n", t_elapsed);

  return 0;
}
