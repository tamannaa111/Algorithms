#include <stdio.h>
#include <string.h>

char a[101], b[101];
int l[101][101];

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int Lcs(int m, int n)
{
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)               //fill up the 1st row and col value with 0's
                l[i][j] = 0;

            else if (a[i - 1] == b[j - 1])      // if you get a match add diagonal +1
                l[i][j] = l[i - 1][j - 1] + 1;

            else
                l[i][j] = max(l[i - 1][j], l[i][j - 1]);  //if you do not get a match take the maximum for previous row or col
        }
    }
    return l[m][n];
}

int main()
{
    scanf("%s %s", a, b);
    int m = strlen(a);
    int n = strlen(b);
    int c = Lcs(m, n);
    printf("%d\n", c);

    return 0;
}
//abcd
//bd

//stone
//longest
