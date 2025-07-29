#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int findminindex(int *arr, int start, int n){
    int minindex = start;
    for(int i = start + 1; i < n; i++){
        if (*(arr + i) < *(arr + minindex)) {
            minindex = i;
        }
    }
    return minindex;
}

void selection_sort(int n, int *arr, int start){
    if (start >= n - 1) {
        return;
    }
    int minindex = findminindex(arr, start, n);
    if (minindex != start) {
        swap(arr + start, arr + minindex);
    }
    selection_sort(n, arr, start + 1);
}

int main(){
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int *a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    printf("Enter the elements of the array:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    selection_sort(n, a, 0);

    printf("The sorted array is: ");
    for(i = 0; i < n; i++){
        printf("%d ", *(a + i));
    }
    printf("\n");

    free(a);

    return 0;
}
