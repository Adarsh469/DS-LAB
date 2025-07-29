#include <stdio.h>

int smallest_element(int n, int a[]) {
    int i;
    int *ptr = a;
    for(i = 1; i < n; i++) {
        if(a[i] < *ptr) {
            *ptr = a[i];
        }
    }
    return *ptr;
}

int main() {
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
    int smallest = smallest_element(n, a);
    printf("Smallest element is: %d\n", smallest);

    return 0;
}
