#include <stdio.h>
#include <string.h> // for memcpy

// Bubble Sort
void bubbleSort(int a[], int n, int *comp, int *swaps) {
    *comp = 0;
    *swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            (*comp)++;
            if (a[j] > a[j + 1]) {
                // swap
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
}

// Selection Sort
void selectionSort(int a[], int n, int *comp, int *swaps) {
    *comp = 0;
    *swaps = 0;

    for (int i = 0; i < n - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < n; j++) {
            (*comp)++;
            if (a[j] < a[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
            (*swaps)++;
        }
    }
}

// Insertion Sort
void insertionSort(int a[], int n, int *comp, int *swaps) {
    *comp = 0;
    *swaps = 0;

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0) {
            (*comp)++;
            if (a[j] > key) {
                a[j + 1] = a[j];
                (*swaps)++; // shifting counts as swap/assignment
                j--;
            } else {
                break;
            }
        }
        a[j + 1] = key;
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    int arr1[n], arr2[n], arr3[n];
    memcpy(arr1, arr, sizeof(arr));
    memcpy(arr2, arr, sizeof(arr));
    memcpy(arr3, arr, sizeof(arr));

    int comp, swaps;

    bubbleSort(arr1, n, &comp, &swaps);
    printf("Bubble Sort -> Comparisons: %d, Swaps: %d\n", comp, swaps);

    selectionSort(arr2, n, &comp, &swaps);
    printf("Selection Sort -> Comparisons: %d, Swaps: %d\n", comp, swaps);

    insertionSort(arr3, n, &comp, &swaps);
    printf("Insertion Sort -> Comparisons: %d, Shifts: %d\n", comp, swaps);

    return 0;
}
