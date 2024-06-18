#include <stdio.h>

#define ROWS 3
#define COLS 4

void select_sort_2d(int a[][COLS], int rows, int cols);

int main() {
    int array[ROWS][COLS] = {
        {5, 3, 8, 2},
        {9, 7, 1, 4},
        {6, 0, 3, 2}
    };

    printf("Original array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    select_sort_2d(array, ROWS, COLS);

    printf("\nSorted array:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void select_sort_2d(int a[][COLS], int rows, int cols) {
     for (int row = 0; row < rows; row++){
          int left = 0, right = cols - 1; 
          int min, temp, i, indx = 0;
          while (left <= right){
               min = a[row][left];
               for (i= left; i <= right; i++){
                    if(a[row][i] < min){
                         indx = i; 
                         min = a[row][i];
                    }
               }
               temp = a[row][left];
               a[row][left] = min;
               a[row][indx] = temp;
               left++;
               
          }
     }
}
