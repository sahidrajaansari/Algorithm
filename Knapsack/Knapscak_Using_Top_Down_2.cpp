#include <bits/stdc++.h>
using namespace std;
class Knapsack
{
    int K_weight;
    int t_elements;

public:
    Knapsack(int K_weight, int t_elements)
    {
        this->K_weight = K_weight;
        this->t_elements = t_elements;
    }

    int TopDown(int wt[], int val[])
    {
        int Dp[t_elements + 1][K_weight + 1];
        for (int i = 0; i <= t_elements; i++)
        {
            for (int j = 0; j <= K_weight; j++)
            {
                if (i == 0 || j == 0)
                {
                    Dp[i][j] = 0;
                }
            }
        }
        int item = 1, i, j;
        for (i = 1; i <= t_elements; i++)
        {
            for (j = 1; j <= K_weight; j++)
            {
                if (wt[i - 1] <= j)
                {
                    Dp[i][j] = max(val[i - 1] + Dp[i - 1][j - wt[i - 1]], Dp[i - 1][j]);
                }
                else
                {
                    Dp[i][j] = Dp[i - 1][j];
                }
            }
            int n = i, maxProfit = Dp[i][K_weight];
            int selected[t_elements + 1];
            while (n >= 0)
            {
                if (Dp[n][K_weight] != Dp[n - 1][K_weight] && maxProfit == Dp[n][K_weight])
                {
                    selected[n] = 1;
                    maxProfit = maxProfit - val[n - 1];
                }
                else
                {
                    selected[n] = 0;
                }
                n--;
            }
            cout << "\nIf there's " << i << " item\n";
            cout << "Then max profit can be :" << Dp[i][K_weight] << endl;
            for (int i = 1; i <= t_elements; i++)
            {
                if (selected[i] == 1)
                {
                    cout << "Item " << i << " | Included " << "| weight "<<wt[i-1]<<" |Value "<<val[i-1]<<endl;
                }
                else{
                    cout<<"Item "<<i<<" | Not included "<<endl;
                }
            }
            cout << endl;
        }
        cout << "\n------------------------Top-Down DP Matrix----------------------------------\n\n";
        for (int i = 0; i <= t_elements; i++)
        {
            for (int j = 0; j <= K_weight; j++)
            {
                cout << "|" << Dp[i][j] << "\t";
            }
            cout << endl;
        }
        cout << "\n";
        return Dp[t_elements][K_weight];
    }
};
int main()
{
    Knapsack K(10, 6);
    int wt[] = {1, 2, 3, 8, 7, 4};
    int val[] = {20, 5, 10, 40, 15, 25};
    // int wt[]={2, 3, 4, 5};
    // int val[]={3, 4, 5, 6};

    // int W=10;
    // int ans=Solution.knapsack(wt,val,W,6);
    int ans = K.TopDown(wt, val);
    cout << "Your Max Profit Can be :" << ans;
    return 0;
}