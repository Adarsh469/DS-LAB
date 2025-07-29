#include <stdio.h>
int main() {
    int arr[100], n, i, j, min_ind, temp;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    for(i = 0; i < n - 1; i++) {
        min_ind = i;
        for(j = i + 1; j < n; j++) {
            if(arr[j] < arr[min_ind]) {
                min_ind = j;
            }
        }

        temp = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = temp;
    }

    printf("The given array sorted is: ");
    for(i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
