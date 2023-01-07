#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = nullptr;
    }
};
class Queue
{
public:
    int data;
    Node *first;
    Node *last;
    Queue()
    {
        first = nullptr;
        last = nullptr;
    }
    bool isEmpty()
    {
        if (first == nullptr)
        {
            return true;
        }
        return false;
    }
    void enqueue(int value)
    {
        Node *t = new Node(value);
        if (first == nullptr)
        {
            first = last = t;
        }
        else
        {
            last->next = t;
            last = t;
        }
    }
    int deqeue()
    {
        int x = -1;
        Node *ptr;
        if (isEmpty())
        {
            // cout << "Queue is empty" << endl;
            return x;
        }
        else
        {
            ptr = first;
            first = first->next;
            x = ptr->data;
            delete (ptr);
            return x;
        }
    }
};
typedef struct process
{
    int Process_Id;
    int Arrival_Time;
    int Burst_Time;
    int Priority;
    int Start_Time;
    int Completion_Time;
    int Turnaround_ime;
    int Waiting_Time;
    int Response_Time;
} process;
void arrivalSort(process arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].Arrival_Time > arr[j + 1].Arrival_Time)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
void process_id_sort(process arr[], int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (arr[j].Process_Id > arr[j + 1].Process_Id)
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void display(process p[], float AVG_Turnaround_Time, float AVG_Waiting_Time, int n)
{
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
        cout << p[i].Process_Id << "\t" << p[i].Arrival_Time << "\t" << p[i].Burst_Time << "\t" << p[i].Completion_Time << "\t" << p[i].Turnaround_ime << "\t" << p[i].Waiting_Time << "\t"
             << "\n"
             << endl;
    }
    cout << "Average Turnaround Time : " << AVG_Turnaround_Time << endl;
    cout << "Average Waiting Time :" << AVG_Waiting_Time << endl;
}
void roundrobin(process p[], int n, int time_quanta)
{
    arrivalSort(p, n);
    float AVG_Turnaround_Time, AVG_Waiting_Time;
    int total_turnaround_time = 0, total_waiting_time = 0;
    int burst_time_remaining[n];
    bool is_completed[n];
    for (int i = 0; i < n; i++)
    {
        is_completed[i] = false;
        burst_time_remaining[i] = p[i].Burst_Time;
    }
    Queue q;
    q.enqueue(0);
    is_completed[0] = true;
    int index;
    cout << "\n";
    int current_time = 0;
    int completed = 0;
    int prev = 0;
    while (completed != n)
    {
        index = q.deqeue();

        if (burst_time_remaining[index] == p[index].Burst_Time)
        {
            p[index].Start_Time = max(current_time, p[index].Arrival_Time);
            current_time = p[index].Start_Time;
        }

        if (burst_time_remaining[index] - time_quanta > 0)
        {
            burst_time_remaining[index] -= time_quanta;
            current_time += time_quanta;
        }
        else
        {
            current_time += burst_time_remaining[index];
            burst_time_remaining[index] = 0;
            completed++;

            p[index].Completion_Time = current_time;
            p[index].Turnaround_ime = p[index].Completion_Time - p[index].Arrival_Time;
            p[index].Waiting_Time = p[index].Turnaround_ime - p[index].Burst_Time;
            p[index].Response_Time = p[index].Start_Time - p[index].Arrival_Time;

            total_turnaround_time += p[index].Turnaround_ime;
            total_waiting_time += p[index].Waiting_Time;
        }

        for (int i = 1; i < n; i++)
        {
            if (burst_time_remaining[i] > 0 && p[i].Arrival_Time <= current_time && is_completed[i] == 0)
            {
                q.enqueue(i);
                is_completed[i] = 1;
            }
        }
        if (burst_time_remaining[index] > 0)
        {
            q.enqueue(index);
        }

        if (q.isEmpty())
        {
            for (int i = 1; i < n; i++)
            {
                if (burst_time_remaining[i] > 0)
                {
                    q.enqueue(i);
                    is_completed[i] = 1;
                    break;
                }
            }
        }
    }
    process_id_sort(p, n);
    AVG_Turnaround_Time = (float)total_turnaround_time / n;
    AVG_Waiting_Time = (float)total_waiting_time / n;
    display(p, AVG_Turnaround_Time, AVG_Waiting_Time, n);
}
void NonPremptive(process p[], int n)
{
    float AVG_Turnaround_Time, AVG_Waiting_Time;
    int total_turnaround_time = 0, total_waiting_time = 0;
    bool is_completed[n];
    for (int i = 0; i < n; i++)
    {
        is_completed[i] = false;
    }
    cout << "\n";
    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != n)
    {
        int index = -1;
        int max_priority_value = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].Arrival_Time <= current_time && is_completed[i] == 0)
            {
                if (p[i].Priority < max_priority_value)
                {
                    max_priority_value = p[i].Priority;
                    index = i;
                }
                if (p[i].Priority == max_priority_value)
                {
                    if (p[i].Arrival_Time < p[index].Arrival_Time)
                    {
                        max_priority_value = p[i].Priority;
                        index = i;
                    }
                }
            }
        }
        if (index != -1)
        {
            p[index].Start_Time = current_time;
            p[index].Completion_Time = p[index].Start_Time + p[index].Burst_Time;
            p[index].Turnaround_ime = p[index].Completion_Time - p[index].Arrival_Time;
            p[index].Waiting_Time = p[index].Turnaround_ime - p[index].Burst_Time;
            p[index].Response_Time = p[index].Start_Time - p[index].Arrival_Time;

            total_turnaround_time += p[index].Turnaround_ime;
            total_waiting_time += p[index].Waiting_Time;

            is_completed[index] = 1;
            completed++;
            current_time = p[index].Completion_Time;
            prev = current_time;
        }
        else
        {
            current_time++;
        }
    }
    AVG_Turnaround_Time = (float)total_turnaround_time / n;
    AVG_Waiting_Time = (float)total_waiting_time / n;
    display(p, AVG_Turnaround_Time, AVG_Waiting_Time, n);
}
void preemptive(process p[], int n)
{
    float AVG_Turnaround_Time, AVG_Waiting_Time;
    int total_turnaround_time = 0, total_waiting_time = 0;
    int burst_time_remaining[n];
    bool is_completed[n];
    for (int i = 0; i < n; i++)
    {
        is_completed[i] = false;
        burst_time_remaining[i] = p[i].Burst_Time;
    }
    cout << "\n";
    int current_time = 0;
    int completed = 0;
    int prev = 0;

    while (completed != n)
    {
        int index = -1;
        int max_priority_value = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].Arrival_Time <= current_time && is_completed[i] == 0)
            {
                if (p[i].Priority < max_priority_value)
                {
                    max_priority_value = p[i].Priority;
                    index = i;
                }
                if (p[i].Priority == max_priority_value)
                {
                    if (p[i].Arrival_Time < p[index].Arrival_Time)
                    {
                        max_priority_value = p[i].Priority;
                        index = i;
                    }
                }
            }
        }
        if (index != -1)
        {
            if (burst_time_remaining[index] == p[index].Burst_Time)
            {
                p[index].Start_Time = current_time;
            }
            burst_time_remaining[index] -= 1;
            current_time++;
            prev = current_time;
            if (burst_time_remaining[index] == 0)
            {
                p[index].Completion_Time = current_time;
                p[index].Turnaround_ime = p[index].Completion_Time - p[index].Arrival_Time;
                p[index].Waiting_Time = p[index].Turnaround_ime - p[index].Burst_Time;
                p[index].Response_Time = p[index].Start_Time - p[index].Arrival_Time;

                total_turnaround_time += p[index].Turnaround_ime;
                total_waiting_time += p[index].Waiting_Time;

                is_completed[index] = true;

                completed++;
            }
        }
        else
        {
            current_time++;
        }
    }

    AVG_Turnaround_Time = (float)total_turnaround_time / n;
    AVG_Waiting_Time = (float)total_waiting_time / n;
    display(p, AVG_Turnaround_Time, AVG_Waiting_Time, n);
}
void SJF(process p[], int n)
{
    bool is_completed[n];
    for (int i = 0; i < n; i++)
    {
        is_completed[i] = false;
    }
    int completed = 0, current_time = 0;
    while (completed != n)
    {
        int index = -1;
        int low = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].Arrival_Time <= current_time && is_completed[i] == false)
            {
                if (p[i].Burst_Time < low)
                {
                    index = i;
                    low = p[i].Burst_Time;
                }
            }
        }
        if (index != -1)
        {
            is_completed[index] = true;
            completed++;
            current_time+=p[index].Burst_Time;
            p[index].Completion_Time = current_time;
            p[index].Turnaround_ime = p[index].Completion_Time - p[index].Arrival_Time;
            p[index].Waiting_Time = p[index].Turnaround_ime - p[index].Burst_Time;
        }
        else
        {
            current_time++;
        }
    }
    int avgWaitingTime = 0, avgTurnaroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        avgTurnaroundTime += p[i].Turnaround_ime;
        avgWaitingTime += p[i].Waiting_Time;
    }
    avgTurnaroundTime /= n;
    avgWaitingTime /= n;
    display(p, avgTurnaroundTime, avgTurnaroundTime, n);
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
        p[i].Process_Id = i + 1;
        cout << "Arrival time :";
        cin >> p[i].Arrival_Time;
        cout << "Burst Time :";
        cin >> p[i].Burst_Time;
        // cout << "Priority :";
        // cin >> p[i].Priority;
        cout << endl;
    }
    SJF(p,n);
    // cout << "\nAT - Arrival Time of the process\nBT - Burst time of the process\nST - Start time of the process\nCT - Completion time of the process\nTAT - Turnaround time of the process\nWT - Waiting time of the process\nRT - Response time of the process";
    // int choice = 0;
    // cout << "\n\n";
    // while (choice != 3)
    // {
    //     cout << "Enter Choice \n1.Preemptive \n2.NonPremptive \n3.Round Robin \n4.Exit \n->";
    //     cin >> choice;
    //     switch (choice)
    //     {
    //     case 1:
    //     {
    //         cout << "\nPreemptive Priority Scheduling\n";
    //         preemptive(p, n);
    //         cout << "\n";
    //     }
    //     break;
    //     case 2:
    //     {
    //         cout << "\nNon-Preemptive Priority Scheduling\n";
    //         NonPremptive(p, n);
    //         cout << "\n";
    //     }
    //     break;
    //     case 3:
    //     {
    //         int tq;
    //         cout << "Enter Time Quanta \n->";
    //         cin >> tq;
    //         cout << "Round Robin Scheduling \n";
    //         roundrobin(p, n, tq);
    //         cout << "\n";
    //     }
    //     break;
    //     case 4:
    //     {
    //         exit(0);
    //     }
    //     break;
    //     default:
    //     {
    //         cout << "Wrong Choice";
    //     }
    //     break;
    //     }
    // }
    return 0;
}