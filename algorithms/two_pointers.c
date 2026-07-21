#include <stdio.h>

// Goal: Count how many pairs of elements sum up to 10.

void show(int *arr, int left, int right) {
    printf("left: %d, right: %d\n", left, right);
    printf("%d + %d = %d\n", arr[left], arr[right], arr[left] + arr[right]);
    puts("-----------------------");
}

int count(int *arr, int n, int target) {
    int left = 0, right = n - 1;
    int cnt = 0;
    
    while (left != right) {
        int sum = arr[left] + arr[right];
        
        if (sum == target) {
            show(arr, left, right);
            cnt++;
            left++;
        }
        else if (sum > target) {
            right--;
        }
        else if (sum < target) {
            left++;
        }
    }
    
    return cnt;
}

int main() {
    int arr[15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    printf("Count: %d\n", count(arr, n, target));

    return 0;
}
