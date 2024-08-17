#include <stdio.h>

void mm(int arr[], int *min, int *max, int size) {
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < size; i++) {
        if (arr[i] > *max) {
            *max = arr[i];
        }

        if (arr[i] < *min) {
            *min = arr[i];
        }
    }
}

int main() {
    int arr[10];

    for (int i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    int min, max;
    mm(arr, &min, &max, sizeof(arr)/sizeof(int));

    printf("Max: %d\nMin: %d", max, min);

    return 0;
}