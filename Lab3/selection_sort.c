#include <stdio.h>

void selectionSort(int array[], int n) {
    int i, j, minIndex, temp;
    for (i = 0; i < n-1; i++) {
        minIndex = i;
        for (j = i+1; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(array)/sizeof(array[0]);

    printf("Array before sorting: \n");
    for (int i=0; i < n; i++) {
        printf("%d ", array[i]);
    }

    selectionSort(array, n);

    printf("\nArray after sorting: \n");
    for (int i=0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}
