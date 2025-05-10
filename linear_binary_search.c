#include <stdio.h>

// Linear Search Function
int linearSearch(int arr[], int n, int val) {
    for(int i = 0; i < n; i++) {
        if(arr[i] == val)
            return i;
    }
    return -1;
}

// Bubble Sort Function
void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = n - 1; j > i; j--) {
            if(arr[j] < arr[j - 1]) {
                int temp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = temp;
            }
        }
    }
}

// Binary Search Function
int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;
    while(low <= high) {
        int mid = (low + high) / 2;
        if(arr[mid] == key)
            return mid;
        else if(key < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main() {
    int n, arr[100], val, i, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter value to search: ");
    scanf("%d", &val);

    // Linear Search
    pos = linearSearch(arr, n, val);
    if(pos != -1)
        printf("Linear Search: Element %d found at index %d\n", val, pos);
    else
        printf("Linear Search: Element %d not found\n", val);

    // Bubble Sort before Binary Search
    bubbleSort(arr, n);
    printf("Array after Bubble Sort: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Binary Search
    pos = binarySearch(arr, n, val);
    if(pos != -1)
        printf("Binary Search: Element %d found at index %d\n", val, pos);
    else
        printf("Binary Search: Element %d not found\n", val);

    return 0;
}
