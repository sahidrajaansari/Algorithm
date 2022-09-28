#include<bits/stdc++.h>
using namespace std;
int dp[100][100];
class k{
public:
int count=0;
int knapsack(int wt[],int val[],int W,int size){
    cout<<"Running for :"<<count<<endl;
    count++;
    if(size==0 || wt==0){
        return 0;
    }
    if(dp[W][size]!=-1){
        return dp[W][size];
    }
    if(wt[size-1]<W){
        return dp[W][size]=max(val[size-1]+knapsack(wt,val,W-wt[size-1],(size-1)),knapsack(wt,val,W,(size-1)));
    }
    else{
        return dp[W][size]=knapsack(wt,val,W,(size-1));
    }
}
};
int main()
{
    k e;
    memset(dp,-1,sizeof(dp));
    int val[]={20, 5, 10, 40, 15, 25 };
    int wt[]={1, 2, 3, 8, 7, 4};
    int W=10;
    int ans=e.knapsack(wt,val,W,6);
    cout<<"Your Max Profit Can be :"<<ans;
    return 0;
}