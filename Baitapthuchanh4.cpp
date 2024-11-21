#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_SIZE 1000

// H�m ki?m tra s? c� ph?i l� d�y kh�ng gi?m hay kh�ng
int isNonDecreasing(int number) {
    int prevDigit = 10; // Gi� tr? b?t d?u cho ph�p l� 10 (ch? s? tru?c t?t c? c�c ch? s?)
    
    while (number > 0) {
        int digit = number % 10;
        if (digit > prevDigit) {
            return 0; // N?u c� ch? s? nh? hon ch? s? tru?c d�, tr? v? 0
        }
        prevDigit = digit;
        number /= 10;
    }
    
    return 1; // N?u t?t c? ch? s? d?u kh�ng gi?m, tr? v? 1
}

int main() {
    char line[MAX_SIZE];
    int numbers[MAX_SIZE], count = 0;
    
    // �?c t?t c? c�c s? t? d?u v�o
    printf("Nh?p d�y s? (k?t th�c b?ng EOF):\n");
    while (fgets(line, sizeof(line), stdin)) {
        char *token = strtok(line, " \n");
        while (token != NULL) {
            int num = 0;
            // Chuy?n d?i chu?i token th�nh s? nguy�n
            for (int i = 0; token[i] != '\0'; i++) {
                if (isdigit(token[i])) {
                    num = num * 10 + (token[i] - '0');
                }
            }
            numbers[count++] = num;
            token = strtok(NULL, " \n");
        }
    }
    
    // M?ng d? d?m s? l?n xu?t hi?n c?a c�c s? kh�ng gi?m
    int freq[MAX_SIZE] = {0};
    
    // Duy?t qua t?ng s? trong m?ng numbers
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i])) {
            freq[numbers[i]]++;
        }
    }
    
    // In ra c�c s? kh�ng gi?m v� s? l?n xu?t hi?n
    printf("C�c s? kh�ng gi?m v� s? l?n xu?t hi?n:\n");
    for (int i = 0; i < count; i++) {
        if (isNonDecreasing(numbers[i]) && freq[numbers[i]] > 0) {
            printf("S? %d xu?t hi?n %d l?n\n", numbers[i], freq[numbers[i]]);
            freq[numbers[i]] = 0; // �?m b?o ch? in m?t l?n
        }
    }

    return 0;
}
