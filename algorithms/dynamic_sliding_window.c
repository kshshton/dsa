#include <stdio.h>
#include <limits.h>

// Goal: Find the shortest window with sum at least 10.

int main() {
    int arr[10] = {5, 2, 6, 3, 1, 2, 8, 3, 6, 3};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    int left = 0, window_sum = 0, min_length = INT_MAX;

    for (int right = 0; right < n; right++) {
        window_sum += arr[right];
        
        while (window_sum >= target) {
            int window_length = right - left + 1;
            
            if (window_length < min_length)
                min_length = window_length;
                
            window_sum -= arr[left];
            left++;
        }
    }

    printf("The shortest window with the sum at least 10: %d\n", min_length);

    return 0;
}
