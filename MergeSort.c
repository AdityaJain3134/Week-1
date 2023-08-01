#include <stdio.h>
#include <stdlib.h>

void Merge(int arr1[], int low, int mid, int high){
    int arr2[high + 1];
    int i = low, j = mid + 1, k = low;
    while(i <= mid && j <= high){
        if(arr1[i] < arr1[j])
            arr2[k++] = arr1[i++];
        else
            arr2[k++] = arr1[j++];
    }
    for(; i <= mid; i++)
        arr2[k++] = arr1[i];
    for(; j <= high; j++)
        arr2[k++] = arr1[j];

    for(k = low; k <= high; k++)
        arr1[k] = arr2[k];
}

void Merge_Sort(int arr[], int low, int high){
    if(low < high){
        int mid = (low + high)/2;
        Merge_Sort(arr, low, mid);
        Merge_Sort(arr, mid + 1, high);
        Merge(arr, low, mid, high);
    }
}

void Displpay_Array(int arr[], int length){
    printf("Array: ");
    for(int c = 0; c < length; c++)
        printf("%d ", arr[c]);
    printf("\n\n");
}

int main()
{
    int arr[] = {9, 8, 5, 6, 3, 1};
    int size = sizeof(arr)/sizeof(int);
    Displpay_Array(arr, size);
    Merge_Sort(arr, 0, size-1);
    Displpay_Array(arr, size);
    return 0;
}
