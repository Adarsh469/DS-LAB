#include <stdio.h>

// Linear Search
int linearsearch(int a[], int n, int key) {
    for (int i = 0; i < n; i++) {
        if (a[i] == key) {
            return i + 1; // position (1-based index)
        }
    }
    return -1; // not found
}

// Binary Search (array must be sorted)
int binarysearch(int a[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (a[mid] == key) {
            return mid + 1; // position
        } else if (a[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1; // not found
}

int main() {
    int a[] = {1, 2, 3, 4, 6, 7}; // must be sorted for binary search
    int n = sizeof(a) / sizeof(a[0]);
    int key, pos;

    printf("Enter the element to be searched (linear search): ");
    scanf("%d", &key);

    pos = linearsearch(a, n, key);
    if (pos != -1)
        printf("Element found at position %d (linear search)\n", pos);
    else
        printf("Element not found (linear search)\n");

    printf("Enter the element to be searched (binary search): ");
    scanf("%d", &key);

    pos = binarysearch(a, n, key);
    if (pos != -1)
        printf("Element found at position %d (binary search)\n", pos);
    else
        printf("Element not found (binary search)\n");

    return 0;
}
