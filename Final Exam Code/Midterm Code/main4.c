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

int main() {
    char s[] = "hello";
    char *p = s; 
    reverse(p); 
    printf("Reverse a string: %s\n", s);
    
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
    
    return 0;
}

void reverse(char *p) {
    // Your implementation here
    int i = 0, j = strlen(p) - 1; 
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
    int result = 0;
    for (int i = 0; i <= a; i++){
          result = (result * x) + p[i];
    }
}

int str2int(char *p) {
    // Your implementation here
    int multiplicand = 1, new_s = 0, i, length = strlen(p) - 1;
    for (i = 0; p[i] != '\0'; i++){
          multiplicand = 1; 
          for (int j = 0; j < length; j++){
               multiplicand *= 10; 
          }
          new_s += (p[i] - '0') * multiplicand;
          length--;
}

void int2str(int a, char *s) {
    // Your implementation here
    int temp = a, length = 0, multiplicand = 1, j =0;
    while (temp){
          length++;
          temp /= 10; 
    }

     for(int i = 0; i < length - 1; i++){
          multiplicand *= 10;
     }

     while (multiplicand){
          s[j] = '0' + (a/multiplicand);
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
     int ans = 1;
     if (n <= 1){
          return n;
     } else{
          int i, j;
          i = 0; j = 1;
          for (int t = 2; t < n; t++){
               ans = i + j;
               i = j;
               j = ans;
          }
     }
     return ans;
}

int factorial_r(int n) {
    // Your implementation here
    if (n <= 1){
          return n; 
    } else {
          return n * factorial_r(n-1);
    }
}

int factorial_i(int n) {
    // Your implementation here
    int ans = 1;
    if (n <= 1){
          return n; 
    } else {
          for (int i = 1; i <= n; i++){
               ans *= i;
          }
    }
    return ans;
}
