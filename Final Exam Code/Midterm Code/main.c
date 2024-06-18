
#include <stdio.h>
#include <string.h>
void reverse(char *);
int horner(int p[], int x, int a);
int str2int(char *);
void int2str(int, char *);
int fibonacci_r(int);
int fibonacci_i(int);
int factorial_r(int);
int factorial_i(int);
int main() {
    // Write C code here
    
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


    int len = 5; 
    printf("Fibonacci: %d\n", fibonacci_r(len));


    printf("Factorial: %d\n", factorial_r(len));

    printf("Factorial non-recursive: %d\n", factorial_i(len));
    return 0;
}

// reverse a string 
void reverse(char *p){
    int length = strlen(p);
    int i = 0, j = length - 1;
    
    while (i<j){
        char temp = p[i];
        p[i] = p[j];
        p[j] = temp;
        i++;
        j--;
    }
}

int horner(int p[], int x, int a){
    int result = 0;
    for(int i = 0; i < a; i++){
        result = result * x + p[i];
    }
}

int str2int(char *p){
    int multiplicand = 1, length = strlen(p)-1, new_s = 0;
    for (int i = 0; p[i] != '\0'; i++){
        multiplicand = 1; 
        for (int k = 0; k < length; k++){
            multiplicand *= 10;
        }
        new_s += (p[i] - '0') * multiplicand;
        length--;
    }
    return new_s;
}

void int2str(int a, char *s){
    int j = 0, m = a, count = 0;
    while (m != 0){
        j++;
        m/=10;
    }
    // j now stores the length of the integer 
    
    int multiplicand = 1; 
    for (int i = 0; i < j-1; i++){
        multiplicand *= 10; 
    }
    
    // multiplicand now stores the largest place value 
    
    while(multiplicand != 0){
        // get the current digit
        int curr = a/multiplicand;
        s[count] = '0' + curr; 
        a %= multiplicand; 
        multiplicand /= 10;
        count++;
    }
    s[count] = '\0';
}

int fibonacci_r(int n){
    if (n <= 1){
        return n; 
    } else {
        return fibonacci_r(n-2) + fibonacci_r(n-1);
    }
}



int fibonacci_i(int n){
    if (n <= 1){
        return n;
    } else {
        int i, j, k;
        i = 0, j = 0, k = 1;
        for (int t = 0; t <= n; t++){
            i = j + k; 
            j = k; 
            k = i;
        }
    }
}


int factorial_r(int n){
    if (n <= 1){
        return 1;
    } else {
        return n * factorial_r(n-1);
    }
}

int factorial_i(int n){
    int hold = 1;

    for (int i = 1; i <= n; i++){
        hold *= i;
    }
    return hold;

}