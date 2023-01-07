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
void arrivalSort(process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].arrivalTime > p[j + 1].arrivalTime)
            {
                swap(p[j + 1], p[j]);
            }
        }
    }
}
void idSort(process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (p[j].processId > p[j + 1].processId)
            {
                swap(p[j + 1], p[j]);
            }
        }
    }
}
void Roundrobin(process p[], int n, int tq)
{
    arrivalSort(p, n);
    int remainingBurstTime[n], completed = 0, currentTime = 0;
    for (int i = 0; i < n; i++)
    {
        remainingBurstTime[i] = p[i].burstTime;
    }
    bool visited[n];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(0);
    visited[0] = true;
    while (completed != n)
    {
        int index = q.front();
        q.pop();
        if (remainingBurstTime[index] - tq > 0)
        {
            currentTime += tq;
            remainingBurstTime[index] -= tq;
        }
        else
        {
            completed++;
            currentTime += remainingBurstTime[index];
            remainingBurstTime[index] = 0;
            p[index].completionTime = currentTime;
            p[index].turnaroundTime = p[index].completionTime - p[index].arrivalTime;
            p[index].waitingTime = p[index].turnaroundTime - p[index].burstTime;
        }
        for (int i = 1; i < n; i++)
        {
            if (p[i].arrivalTime <= currentTime && visited[i] == false)
            {
                if (remainingBurstTime[i] > 0)
                {
                    q.push(i);
                    visited[i] = 1;
                }
            }
        }
        if (remainingBurstTime[index] > 0)
        {
            q.push(index);
        }
        if (q.empty())
        {
            for (int i = 0; i < n; i++)
            {
                if (remainingBurstTime[i] > 0)
                {
                    q.push(i);
                    visited[i] = true;
                    break;
                }
            }
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
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; i++)
    {
        cout << "Process P" << i + 1 << endl;
        p[i].processId = i + 1;
        cout << "Arrival Time: ";
        cin >> p[i].arrivalTime;
        cout << "Burst Time: ";
        cin >> p[i].burstTime;
        // cout << "Priority: ";
        // cin >> p[i].priority;
    }
    Roundrobin(p,n,3);
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