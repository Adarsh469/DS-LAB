#include <stdio.h>

int length(int a[]){
    int len = sizeof(a)/sizeof(a[0]);
    return len;
}
void bubblesort(int a[], int n){
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; i++)
        {
            if (a[j]>a[j+1])
            {
                a[j]=a[j]^a[j+1];
                a[j+1]=a[j+1]^a[j];
                a[j]=a[j]^a[j+1];
            }
        }
        
    }
    
}

void selectionSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_index = i;  

        for (int j = i + 1; j < n; j++) {
            if (a[j] < a[min_index]) {
                min_index = j; 
            }
        }
        if (min_index != i) {
            int temp = a[i];
            a[i] = a[min_index];
            a[min_index] = temp;
        }
    }
}

void insertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key; 
    }
}

int main(){
    int a[] = {1,4,2,3,7,6};
    int n = length(a);
    bubblesort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    

    int a[] = {1,4,2,3,7,6};
    int n = length(a);
    selectionsort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
    
    int a[] = {1,4,2,3,7,6};
    int n = length(a);
    insertionSort(a, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d", a[i]);
    }
}