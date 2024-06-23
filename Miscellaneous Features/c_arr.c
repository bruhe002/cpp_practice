#include <stdio.h>

void display_array(int arr[], int arr_size) {
    for(int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}