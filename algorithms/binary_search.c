#include <stdio.h>
#include <limits.h>

// Goal: Find the target value in the fewest moves.

int binary_search(int *arr, int n, int target) {
    int left = 0, right = n - 1;
    int cnt = 0;
    
    while (left != right) {
        cnt++;
        int mid = left + (right - left) / 2;
        printf("%d\n", arr[mid]);
        
        if (arr[mid] == target) return cnt;
        else if (arr[mid] > target) {
            right = mid - 1;
        }
        else if (arr[mid] < target) {
            left = mid + 1;
        }
    }
    
    return cnt;
}

int main() {
    int arr[12] = {2, 5, 7, 12, 15, 19, 25, 30, 44, 51, 52, 55};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 52;

    printf("The fewest number of moves: %d\n", binary_search(arr, n, target));

    return 0;
}
