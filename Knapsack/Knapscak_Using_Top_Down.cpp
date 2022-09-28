#include<bits/stdc++.h>
using namespace std;
class Knapsack{
    int K_weight;
    int t_elements;
    public:
    Knapsack(int K_weight,int t_elements){
        this->K_weight=K_weight;
        this->t_elements=t_elements;
    }

    int TopDown(int wt[],int val[]){
        int Dp[t_elements+1][K_weight+1];
        for(int i=0;i<=t_elements;i++){
            for(int j=0;j<=K_weight;j++){
                if(i==0|| j==0){
                    Dp[i][j]=0;
                }
            }
        }

    }
};
int main()
{
    // memset(dp,-1,sizeof(dp));
    int val[]={20, 5, 10, 40, 15, 25 };
    int wt[]={1, 2, 3, 8, 7, 4};
    int W=10;
    // int ans=Solution.knapsack(wt,val,W,6);
    int ans;
    cout<<"Your Max Profit Can be :"<<ans;
    return 0;
}