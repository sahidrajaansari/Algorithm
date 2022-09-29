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
        int item=1,i,j;
        for(i=1;i<=t_elements;i++){
            for(j=1;j<=K_weight;j++){
                if(wt[i-1]<=j){
                    Dp[i][j]=max(val[i-1]+Dp[i-1][j-wt[i-1]],Dp[i-1][j]);
                }
                else{
                    Dp[i][j]=Dp[i-1][j];
                }
            }
            // int maxcurrent=Dp[i][K_weight];
            // int x[t_elements];
            cout<<"If there's "<<item<<" item\n";
            cout<<"Then max profit can be :"<<Dp[i][K_weight]<<endl;
            item++;
            for(int k=0;k<=K_weight;k++){
                cout<<Dp[i][k]<<"|\t"; 
            }
            cout<<endl<<"\n";
            // while(maxcurrent!=0){
            //     if(maxcurrent!=)

            // }
        }
        cout<<"Top-Down DP Matrix--------------------------------------------------------\n\n";
        for(int i=0;i<=t_elements;i++){
            for(int j=0;j<=K_weight;j++){
                cout<<"|"<<Dp[i][j]<<"\t";
            }
            cout<<endl;
        }
        cout<<"\n";
        return Dp[t_elements][K_weight];
    }
};
int main()
{
    Knapsack K(10,6);
    int wt[]={1, 2, 3, 8, 7, 4};
    int val[]={20, 5, 10, 40, 15, 25 };
    // int W=10;
    // int ans=Solution.knapsack(wt,val,W,6);
    int ans=K.TopDown(wt,val);
    cout<<"Your Max Profit Can be :"<<ans;
    return 0;
}