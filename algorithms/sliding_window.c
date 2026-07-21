#include <stdio.h>

// Goal: Find window with the biggest sum in the array.

int main() {
    int arr[10] = {5, 2, 6, 3, 1, 2, 8, 3, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3; // window size
    
    int window_sum = 0;
    for (int i = 0; i < k; i++) {
        window_sum += arr[i];
    }
    
    int max_sum = window_sum;
    for (int i = k; i < n; i++) {
        printf(
            "%d - %d + %d = %d\n",
            window_sum,
            arr[i - k],
            arr[i],
            window_sum - arr[i - k] + arr[i]
        );
        window_sum = window_sum - arr[i - k] + arr[i];
        
        if (window_sum > max_sum) {
            max_sum = window_sum;
        }
    }
    
    printf("Maximum window sum: %d\n", max_sum);
    
    return 0;
}
