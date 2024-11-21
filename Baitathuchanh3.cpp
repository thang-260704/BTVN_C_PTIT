#include <stdio.h>

// H�m in d�y s?
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// H�m th?c hi?n thu?t to�n s?p x?p d?i ch? tr?c ti?p
void bubbleSort(int arr[], int n) {
    printf("D�y ban d?u: ");
    printArray(arr, n);
    
    for (int i = 0; i < n - 1; i++) { // L?p qua c�c v�ng
        printf("Bu?c %d:\n", i + 1);
        int swapped = 0; // �? ki?m tra c� d?i ch? hay kh�ng
        
        for (int j = 0; j < n - i - 1; j++) { // So s�nh t?ng c?p
            if (arr[j] > arr[j + 1]) { // �?i ch? n?u kh�ng d�ng th? t?
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        printArray(arr, n); // In tr?ng th�i sau m?i bu?c
        
        // N?u kh�ng c� s? d?i ch? n�o, d�y d� s?p x?p xong
        if (!swapped) {
            printf("Kh�ng c� ho�n v?, d�y d� s?p x?p.\n");
            break;
        }
    }
}

int main() {
    int n;
    printf("Nh?p s? lu?ng ph?n t?: ");
    scanf("%d", &n);
    int arr[n];
    
    printf("Nh?p c�c ph?n t?:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    bubbleSort(arr, n);
    
    printf("D�y d� s?p x?p: ");
    printArray(arr, n);
    
    return 0;
}
