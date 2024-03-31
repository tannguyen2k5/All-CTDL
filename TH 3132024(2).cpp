#include <stdio.h>
#include <stdbool.h>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

void findPrimes(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (isPrime(arr[i])) {
            printf("So nguyen to tai vi tri: %d\n", i);
            count++;
        }
    }
    printf("So luong so nguyen to: %d\n", count);
}

int main(void) {
    int arr[] = {2, 3, 4, 10, 40, 40, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    findPrimes(arr, n);
    return 0;
}

