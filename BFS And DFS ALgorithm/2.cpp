#include <bits/stdc++.h>
using namespace std;
int knapsack(int val[], int wt[], int n, int w)
{
    int t[n + 1][w + 1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < w + 1; j++)
        {
            if (j >= wt[i - 1])
            {
                t[i][j] = max(val[i - 1] + t[i - 1][j - wt[i - 1]], t[i - 1][j]);
            }
            else
            {
                t[i][j] = t[i - 1][j];
            }
        }
    }
    return t[n][w];
}
int main()
{
    int val[] = {2, 3, 1, 4};
    int wt[] = {3, 4, 6, 5};
    int W = 8;
    int n = 4;
    cout << knapsack(val, wt, n, W);
    return 0;
}