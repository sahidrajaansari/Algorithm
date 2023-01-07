#include <bits/stdc++.h>
using namespace std;
typedef struct process
{
    int processId;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int priority;
} process;
void preemptivePriority(process p[], int n)
{
    bool visited[n];
    memset(visited, false, sizeof(visited));
    int remainingBurstTime[n];
    for (int i = 0; i < n; i++)
    {
        remainingBurstTime[i] = p[i].burstTime;
    }
    int completed = 0, currentTime = 0;
    while (completed != n)
    {
        int index = -1;
        int lowestPriority = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].arrivalTime < currentTime && visited[i] != true)
            {
                if (p[i].priority < lowestPriority)
                {
                    index = i;
                    lowestPriority = p[i].priority;
                }
                else if (p[i].priority == lowestPriority)
                {
                    index = i;
                    lowestPriority = p[i].priority;
                }
            }
        }
        if (index != -1)
        {
            remainingBurstTime[index]--;
            if (remainingBurstTime[index] == 0)
            {
                completed++;
                visited[index] = true;
                p[index].completionTime = currentTime;
                p[index].turnaroundTime = p[index].completionTime - p[index].arrivalTime;
                p[index].waitingTime = p[index].turnaroundTime - p[index].waitingTime;
            }
            currentTime++;
        }
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
    cout << "Average Waiting Time is :" << (float)(avgWaitingTime / n) << endl;
    cout << "Average Turnaround Time is :" << (float)(avgTurnaroundTime / n) << endl;
}
int main()
{
    int n;
    cout << "No. of Process :";
    cin >> n;
    process p[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Process P" << i + 1<<endl;
        p[i].processId=i+1;
        cout << "Arrival Time: ";
        cin >> p[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> p[i].burstTime;
        cout << "Priority: ";
        cin >> p[i].priority;
    }
    preemptivePriority(p,n);
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