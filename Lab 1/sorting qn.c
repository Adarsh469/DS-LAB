#include <stdio.h>
int main(){
    int arr[100], n, i, low, mid, high, f;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    low = 0;
    high = n-1;
    mid = low + (high-low)/2;
    printf("Enter number to be found: ");
    scanf("%d", &f);
    while (low<=high){
        if(arr[mid] == f){
            printf(mid);
            break;
        }
        if(arr[mid] < f){
            low = mid +1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}
