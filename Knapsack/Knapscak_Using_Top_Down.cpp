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
        for(int i=1;i<=t_elements;i++){
            for(int j=1;j<=K_weight;j++){
                if(wt[i-1]<=j){
                    Dp[i][j]=max(val[i-1]+Dp[i-1][j-wt[i-1]],Dp[i-1][j]);
                }
                else{
                    Dp[i][j]=Dp[i-1][j];
                }
            }
            cout<<endl;
        }
        // print()
        for(int i=0;i<=t_elements;i++){
            for(int j=0;j<=K_weight;j++){
                cout<<"|"<<Dp[i][j]<<"\t";
            }
            cout<<endl;
        }
        return Dp[t_elements][K_weight];
    }
    // void display(int *dp){
    //     for(int i=0;i<t_elements;i++){
    //         for(int j=0;j<K_weight;i++){
    //             cout<<*dp[i];
    //         }
    //     }
    // }
};
int main()
{
    Knapsack K(10,6);
    int val[]={20, 5, 10, 40, 15, 25 };
    int wt[]={1, 2, 3, 8, 7, 4};
    // int W=10;
    // int ans=Solution.knapsack(wt,val,W,6);
    int ans=K.TopDown(wt,val);
    cout<<"Your Max Profit Can be :"<<ans;
    return 0;
}