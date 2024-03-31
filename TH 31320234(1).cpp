#include <stdio.h>

void binarySearch(int arr[], int l, int r, int x) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (arr[mid] == x) {
            int count = 0;
            for (int i = 0; i <= r; i++) {
                if (arr[i] == x) {
                    printf("Xuat hien tai vi tri: %d\n", i);
                    count++;
                }
            }
            printf("So lan xuat hien: %d\n", count);
        } else if (arr[mid] > x) {
            binarySearch(arr, l, mid - 1, x);
        } else {
            binarySearch(arr, mid + 1, r, x);
        }
    } else {
        printf("Khong co trong mang.\n");
    }
}

int main(void) {
    int arr[] = {2, 3, 4, 10, 40, 40, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 10;
    binarySearch(arr, 0, n - 1, x);
    return 0;
}

