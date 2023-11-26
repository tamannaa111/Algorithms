#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b)
{
    return (a > b) ? a : b;
}

// Function to solve the 0/1 Knapsack Problem
int knapsack(int values[], int weights[], int n, int capacity)
{
    int dp[n + 1][capacity + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++)
    {
        for (int w = 0; w <= capacity; w++)
        {
            if (i == 0 || w == 0)  //initialize 1st row and col value to zero
            {
                dp[i][w] = 0;
            }
            else if (weights[i - 1] <= w)  //include or dont include
            {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            }
            else
            {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][capacity];
}

int main()
{
    int n;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int values[n];
    int weights[n];

    printf("Enter the values and weights of the items:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &values[i], &weights[i]);
    }

    int capacity;

    printf("Enter the knapsack capacity: ");
    scanf("%d", &capacity);

    int result = knapsack(values, weights, n, capacity);

    printf("The maximum value that can be obtained: %d\n", result);

    return 0;
}

//4
//3,2 4,3 5,4 6,5 (profit,weight)
//5
