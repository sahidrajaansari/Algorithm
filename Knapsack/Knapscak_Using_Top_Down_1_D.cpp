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
        int dp[K_weight];
        dp[0]=0;
        int i=1,j=1;
        while(i<t_elements){
            for(j=1;j<=K_weight;j++){
    
            }
        }
    }
};
int main()
{
    return 0;
}