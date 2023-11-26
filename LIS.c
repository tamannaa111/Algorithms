
#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int lengthOfLIS(int arr[], int n) {
    if (n <= 0) {
        return 0;
    }

    int dp[n]; // Create a 1D DP array to store LIS lengths
    int maxLIS = 1; // Initialize the maximum LIS length to 1

    // Initialize each cell of the DP array to 1
    for (int i = 0; i < n; i++) {
        dp[i] = 1;
    }

    // Calculate LIS lengths for each element
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }

        // Update the maximum LIS length found so far
        maxLIS = max(maxLIS, dp[i]);
    }

    return maxLIS;
}

int main() {
    int n;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Invalid input. The number of elements must be greater than 0.\n");
        return 1;
    }

    int arr[n];

    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int result = lengthOfLIS(arr, n);
    printf("Length of LIS is %d\n", result);

    return 0;
}

//10, 22, 9, 33, 21, 50, 41, 60
//8
