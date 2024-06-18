#include <stdio.h>
#include <string.h>

void reverse(char *);
int horner(int[], int, int);
int str2int(char *);
void int2str(int, char *);
int fibonacci_r(int);
int fibonacci_i(int);
int factorial_r(int);
int factorial_i(int);
void select_sort(int *, int, int);

int main() {
    char s[] = "hello";
    char *p = s; 
    reverse(p); 
    char t[] = "apples";
    char *w = t; 
    reverse(w); 
    printf("Reverse a string (odd): %s\n", s);
    printf("Reverse a string (even): %s\n", t);
    
    char str[] = "123";
    char *pStr = str;
    printf("%d\n", str2int(pStr));
    
    int a = 1234; 
    char str_arr[11];
    char *pArr = str_arr;
    int2str(a, pArr);
    printf("%s\n", str_arr);

    int len = 10; 
    printf("Fibonacci recursive: %d\n", fibonacci_r(len));
    printf("Fibonacci iterative: %d\n", fibonacci_i(len));

    printf("Factorial recursive: %d\n", factorial_r(len));
    printf("Factorial iterative: %d\n", factorial_i(len));

     int s_array[] = {1,5,2,4};
     int *pS = s_array;
     int left = 0, right = 3;
    select_sort(pS, left, right);
    printf("Sorted array: ");
    for (int i = 0; i <= right; i++) {
        printf("%d ", s_array[i]);
    }
    printf("\n");
    
    return 0;
}

void reverse(char *p) {
    // Your implementation here
    int i, j; 
    i = 0, j = strlen(p) - 1; 
    while (i < j){
          char temp = p[i];
          p[i] = p[j];
          p[j] = temp; 
          i++;
          j--;
    }
}

int horner(int p[], int x, int a) {
    // Your implementation here
     int r = 0;
     for (int t = 0; t < a; t++){
          r = r*x + p[t];
     }
}

int str2int(char *p) {
    // Your implementation here
    int multiplicand = 1, length = strlen(p) - 1, new_s = 0;
    for (int i = 0; p[i] != '\0'; i++){
          multiplicand = 1; 
          for (int j = 0; j < length; j++){
               multiplicand *= 10; 
          }
          new_s += (p[i] - '0') * multiplicand;
          length--;
    }
    return new_s;
}

void int2str(int a, char *s) {
    // Your implementation here
    int length = 0, temp = a, multiplicand = 1, j = 0; 

    // compute the length 
    while (temp){
          length++;
          temp /= 10; 
    }

     // find largest place value 
     for (int i = 0; i < length - 1; i++){
          multiplicand *= 10; 
     }

     while (multiplicand){
          // char representation of integer 
          s[j] = '0' + (a / multiplicand);
          a %= multiplicand;
          multiplicand /= 10; 
          j++; 
     }
     s[j] = '\0';

}

int fibonacci_r(int n) {
    // Your implementation here
     if (n <= 1){
          return n;
     } else {
          return fibonacci_r(n-1) + fibonacci_r(n-2);
     }
}

int fibonacci_i(int n) {
    // Your implementation here
    int i = 0;
    if (n <= 1){
          return n;
    } else{
          int j, k;
          i = 0, j = 0, k = 1;
          for (int t = 2; t <= n; t++){
               i = j + k; 
               j = k;
               k = i; 
          }
    }
    return i;
}

int factorial_r(int n) {
    // Your implementation here
    if (n <= 1){
          return 1;
    } else {
          return n * factorial_r(n-1);
    }
}

int factorial_i(int n) {
    // Your implementation here
    int i, val = 1;
    for (i = 1; i <= n; i++){
          val *= i; 
    }
     return val;
}


void select_sort(int *a, int left, int right){
     // find minimum and switch it with the first value 
     int temp, i, indx = 0; 
     int min;
     while (left <= right){
          min = a[left]; 
          // update minimum
          for (i = left; i <= right; i++){
               if (a[i] < min){
                    indx = i;
                    min = a[i];
               }
          }
          temp = a[left];
          a[left] = min;
          a[indx] = temp;
          left++;
     }
}