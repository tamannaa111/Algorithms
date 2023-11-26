#include <stdio.h>
#include <limits.h>


int min(int a, int b)
{
    return (a > b) ? b : a;
}

// Function to find the minimum number of coins needed to make a given amount of change
int minCoins(int coins[], int n, int amount) {
    int dp[n + 1][amount + 1];

    // Initialize the first row
    for (int i = 0; i <= amount; i++) {
        dp[0][i] = INT_MAX; // Initialize with a large value
    }
    dp[0][0] = 0;

    // Fill the 2D DP array
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= amount; j++) {
            // If the current coin value is greater than the amount, exclude it
            if (coins[i - 1] > j) {
                dp[i][j] = dp[i - 1][j];
            } else {
                // Choose the minimum of not including the current coin or including it
                dp[i][j] = min(dp[i - 1][j] , 1 + dp[i][j - coins[i - 1]]);
            }
        }
    }

    return dp[n][amount];
}

int main() {
    int n;

    printf("Enter the number of coin denominations: ");
    scanf("%d", &n);

    int coins[n];

    printf("Enter the coin denominations: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &coins[i]);
    }

    int amount;

    printf("Enter the amount of change: ");
    scanf("%d", &amount);

    int result = minCoins(coins, n, amount);

    if (result == INT_MAX) {
        printf("It's not possible to make the given amount of change with the given coins.\n");
    } else {
        printf("Minimum number of coins needed: %d\n", result);
    }

    return 0;
}
//4
//1 5 6 9
//10
