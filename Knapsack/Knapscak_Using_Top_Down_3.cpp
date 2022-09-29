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
            cout<<"If there's "<<item<<" item\n";
            cout<<"Then max profit can be :"<<Dp[i][K_weight]<<endl;
            item++;
            for(int k=0;k<=K_weight;k++){
                cout<<Dp[i][k]<<"|"; 
            }
        }
        
        for(int i=0;i<=t_elements;i++){
            for(int j=0;j<=K_weight;j++){
                cout<<"|"<<Dp[i][j]<<"\t";
            }
            cout<<endl;
        }
        return Dp[t_elements][K_weight];
    }
};
int main()
{
    int w,Items,weight,value;
    cout<<"What's the Weight of your knapsack ?\n->";
    cin>>w;
    cout<<"How Many Items are there?\n->";
    cin>>Items;
    Knapsack K(w,Items);
    int wt[Items],val[Items];
    for(int i=0;i<Items;i++){
        cout<<"\n";
        cout<<"Item :"<<(i+1)<<endl;
        cout<<"Weight:";
        cin>>weight;
        cout<<"Value:";
        cin>>value;
        wt[i]=weight;
        val[i]=value;
    }
    K.TopDown(wt,val);
    
}