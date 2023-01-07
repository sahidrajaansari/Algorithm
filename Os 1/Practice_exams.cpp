#include <bits/stdc++.h>
using namespace std;
typedef struct process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int turnaroundTime;
    int waitingTime;
    int priority;
} process;
void SRTF(process p[], int n)
{
    int remainingTime[n];
    for (int i = 0; i < n; i++)
    {
        remainingTime[i] = p[i].burstTime;
    }
    bool visited[n];
    memset(visited, false, sizeof(visited));
    int completed = 0, currentTime = 0;
    while (completed != n)
    {
        int index = -1;
        int lowestBurstTime = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrivalTime <= currentTime && visited[i] != true)
            {
                if (remainingTime[i] < lowestBurstTime)
                {
                    index = i;
                    lowestBurstTime = p[i].burstTime;
                }
                else if (remainingTime[i] == lowestBurstTime)
                {
                    if (p[i].arrivalTime < p[index].arrivalTime)
                    {
                        index = i;
                        lowestBurstTime = p[i].burstTime;
                    }
                }
            }
        }

        if (index != -1)            //SRTF
        {
            currentTime++;
            remainingTime[index]--;
            if (remainingTime[index] == 0)
            {
                visited[index] = true;
                p[index].completionTime = currentTime;
                p[index].turnaroundTime = p[index].completionTime - p[index].arrivalTime;
                p[index].waitingTime = p[index].turnaroundTime - p[index].burstTime;
                completed++;
            }
        }
        // if (index != -1)             //SJF
        // {
        //     currentTime+=p[index].burstTime;
        //     // if (remainingTime[index] == 0)
        //     // {
        //         visited[index] = true;
        //         p[index].completionTime = currentTime;
        //         p[index].turnaroundTime = p[index].completionTime - p[index].arrivalTime;
        //         p[index].waitingTime = p[index].turnaroundTime - p[index].burstTime;
        //         completed++;
        //     // }
        // }
        else
        {
            currentTime++;
        }
    }
    int avgTurnaroundTime = 0, avgWaitingTime = 0;
    for (int i = 0; i < n; i++)
    {
        avgTurnaroundTime += p[i].turnaroundTime;
        avgWaitingTime += p[i].waitingTime;
    }
    cout << "Average Waiting Time is :" << (float)(avgWaitingTime / 6) << endl;
    cout << "Average Turnaround Time is :" << (float)(avgTurnaroundTime / 6) << endl;
}
int main()
{
    int n;
    cout << "Enter the number of processes \n->";
    cin >> n;
    process p[n];
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Process :" << i + 1 << endl;
        p[i].processId = i + 1;
        cout << "Arrival time :";
        cin >> p[i].arrivalTime;
        cout << "Burst Time :";
        cin >> p[i].burstTime;
        // cout << "Priority :";
        // cin >> p[i].Priority;
        cout << endl;
    }
    SRTF(p,n);
    cout << "\n#P\t"
         << "AT\t"
         << "BT\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t"
         << "\n"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << p[i].processId << "\t" << p[i].arrivalTime << "\t" << p[i].burstTime << "\t" << p[i].completionTime << "\t" << p[i].turnaroundTime << "\t" << p[i].waitingTime << "\t"
             << "\n"
             << endl;
    }
    return 0;
}