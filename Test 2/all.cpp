#include <bits/stdc++.h>
using namespace std;
void FCFS(int table[][6], int Process)
{
    int Complete = 0;
    cout << "\n\nGantt chart " << Complete << " ";
    Complete = table[0][2];
    for (int i = 0; i < Process; i++)
    {
        cout << "[P" << table[i][0] << "]";
        cout << " " << Complete << " ";
        table[i][3] = Complete;
        Complete += table[i + 1][2];
        table[i][4] = table[i][3] - table[i][1];
        table[i][5] = table[i][4] - table[i][2];
    }
}
void sjf(int table[][6],int n){
    int val,temp;
    table[0][3]=table[0][1]+table[0][2];
    table[0][4]=table[0][3]-table[0][1];
    table[0][5]=table[0][4]-table[0][2];
    for(int i=1;i<n;i++){
        temp=table[i-1][3];
        int low=table[i][2];
        for(int j=i;j<n;j++){
            if(temp>=table[j][1] && table[j][2]<=low){
                low=table[j][2];
                val=j;
            }
        }
        table[val][3]=temp+table[val][2];
        table[val][4]=table[val][3]-table[val][1];
        table[val][5]=table[val][4]-table[val][1];
        for(int k=0;k<6;k++){
            swap(table[val][k],table[i][k]);
        }
    }
}
void sortArrival(int table[][6], int process)
{
    for (int i = 0; i < process; i++)
    {
        for (int j = 0; j < process - i - 1; j++)
        {
            if (table[j][1] > table[j + 1][1])
            {
                for (int k = 0; k < 6; k++)
                {
                    swap(table[j][k], table[j + 1][k]);
                }
            }
        }
    }
}
int main()
{
    int Process;
    cout << "Enter Number of process ";
    cin >> Process;
    int table[Process][6];
    memset(table, 0, sizeof(table));
    for (int i = 0; i < Process; i++)
    {
        cout << "Enter Process Number ";
        cin >> table[i][0];
        cout << "Enter Arrival time of Process [P" << table[i][0] << "] ";
        cin >> table[i][1];
        cout << "Enter burst time of Process [P" << table[i][0] << "] ";
        cin >> table[i][2];
        cout << "\n";
    }
    cout << "\n\nProcess\tAT\tWT\tCT\tTAT\tWT\n";
    for (int i = 0; i < Process; i++)
    {
        cout << table[i][0] << "\t" << table[i][1] << "\t" << table[i][2] << "\t" << table[i][3] << "\t" << table[i][4] << "\t" << table[i][5] << "\n";
    }
    sortArrival(table, Process);
    cout<<"Gantt chart --\n";
    cout<<table[0][1];
    for(int i=0;i<Process;i++){
        cout<<"[P"<<table[i][0]<<"]"<<" "<<table[i][3]<<" ";
    }
    sjf(table,Process);
    // FCFS(table, Process);
    cout << "\n\nProcess\tAT\tWT\tCT\tTAT\tWT\n";
    for (int i = 0; i < Process; i++)
    {
        cout << table[i][0] << "\t" << table[i][1] << "\t" << table[i][2] << "\t" << table[i][3] << "\t" << table[i][4] << "\t" << table[i][5] << "\n";
    }
    return 0;
}