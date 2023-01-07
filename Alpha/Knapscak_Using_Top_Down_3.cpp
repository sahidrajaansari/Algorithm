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
        int w, p;
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
            w = 0, p = 0;
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
            // for (int k = 0; k <= K_weight; k++)
            // {
            //     cout << Dp[i][k] << "|\t";
            // }
            for (int i = 1; i <= t_elements; i++)
            {
                if (selected[i] == 1)
                {
                    w += wt[i - 1];
                    p += val[i - 1];
                    cout << "Item " << i << " | Included "
                         << "| weight " << wt[i - 1] << " |Value " << val[i - 1] << endl;
                }
                else
                {
                    cout << "Item " << i << " | Not included " << endl;
                }
            }
            cout << "Space left in knapsack :" << (K_weight - w) << endl;
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
        return Dp[t_elements][K_weight];
    }
};
int main()
{
    int w, Items, weight, value;
    cout << "What's the Highest Capacity of knapsack ?\n->";
    cin >> w;
    cout << "How Many Items are there?\n->";
    cin >> Items;
    Knapsack K(w, Items);
    int wt[Items], val[Items];
    for (int i = 0; i < Items; i++)
    {
        cout << "\n";
        cout << "Item :" << (i + 1) << endl;
        cout << "Weight:";
        cin >> weight;
        cout << "Value:";
        cin >> value;
        wt[i] = weight;
        val[i] = value;
    }
    int result = K.TopDown(wt, val);
    cout << "\nMaxProfit can be " << result;
}