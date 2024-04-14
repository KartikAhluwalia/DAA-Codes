#include <stdio.h>

void bubbleSort(int array[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (array[j] > array[j+1]) {
                // swapping if the element at j is greater than element at j+1
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array)/sizeof(array[0]);

    printf("Array before sorting: \n");
    for (int i=0; i < n; i++) {
        printf("%d ", array[i]);
    }

    bubbleSort(array, n);

    printf("\nArray after sorting: \n");
    for (int i=0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
