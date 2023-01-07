#include <iostream>
#include <algorithm>
#include <iomanip>
#include <string.h>
using namespace std;

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
// class sort
// {
//     public:
//     void merge(process array[], int const left, int const mid,int const right)
//     {
//         auto const subArrayOne = mid - left + 1;
//         auto const subArrayTwo = right - mid;
//         auto *leftArray = new int[subArrayOne],*rightArray = new int[subArrayTwo];
//         for (auto i = 0; i < subArrayOne; i++)
//             leftArray[i] = array[left + i].Arrival_Time;
//         for (auto j = 0; j < subArrayTwo; j++)
//             rightArray[j] = array[mid + 1 + j].Arrival_Time;

//         auto indexOfSubArrayOne = 0,indexOfSubArrayTwo = 0;
//         int indexOfMergedArray = left;

//         while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
//         {
//             if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
//             {
//                 array[indexOfMergedArray].Arrival_Time = leftArray[indexOfSubArrayOne];
//                 indexOfSubArrayOne++;
//             }
//             else
//             {
//                 array[indexOfMergedArray].Arrival_Time = rightArray[indexOfSubArrayTwo];
//                 indexOfSubArrayTwo++;
//             }
//             indexOfMergedArray++;
//         }

//         while (indexOfSubArrayOne < subArrayOne)
//         {
//             array[indexOfMergedArray].Arrival_Time= leftArray[indexOfSubArrayOne];
//             indexOfSubArrayOne++;
//             indexOfMergedArray++;
//         }
//         while (indexOfSubArrayTwo < subArrayTwo)
//         {
//             array[indexOfMergedArray].Arrival_Time= rightArray[indexOfSubArrayTwo];
//             indexOfSubArrayTwo++;
//             indexOfMergedArray++;
//         }
//         delete[] leftArray;
//         delete[] rightArray;
//     }

//     void mergeSort(process array[], int const begin, int const end)
//     {
//         if (begin >= end)
//             return;

//         auto mid = begin + (end - begin) / 2;
//         mergeSort(array, begin, mid);
//         mergeSort(array, mid + 1, end);
//         merge(array, begin, mid, end);
//     }
// };
void display(process p[], float AVG_Turnaround_Time, float AVG_Waiting_Time, int n)
{
    cout << "\n#P\t"
         << "AT\t"
         << "BT\t"
         << "PRI\t"
         << "ST\t"
         << "CT\t"
         << "TAT\t"
         << "WT\t"
         << "RT\t"
         << "\n"
         << endl;

    for (int i = 0; i < n; i++)
    {
        cout << p[i].Process_Id << "\t" << p[i].Arrival_Time << "\t" << p[i].Burst_Time << "\t" << p[i].Priority << "\t" << p[i].Start_Time << "\t" << p[i].Completion_Time << "\t" << p[i].Turnaround_ime << "\t" << p[i].Waiting_Time << "\t" << p[i].Response_Time << "\t"
             << "\n"
             << endl;
    }
    cout << "Average Turnaround Time : " << AVG_Turnaround_Time << endl;
    cout << "Average Waiting Time :" << AVG_Waiting_Time << endl;
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
        int max_priority_index = -1;
        int max_priority_value = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].Arrival_Time <= current_time && is_completed[i] == 0)
            {
                if (p[i].Priority < max_priority_value)
                {
                    max_priority_value = p[i].Priority;
                    max_priority_index = i;
                }
                if (p[i].Priority == max_priority_value)
                {
                    if (p[i].Arrival_Time < p[max_priority_index].Arrival_Time)
                    {
                        max_priority_value = p[i].Priority;
                        max_priority_index = i;
                    }
                }
            }
        }
        if (max_priority_index != -1)
        {
            p[max_priority_index].Start_Time = current_time;
            p[max_priority_index].Completion_Time = p[max_priority_index].Start_Time + p[max_priority_index].Burst_Time;
            p[max_priority_index].Turnaround_ime = p[max_priority_index].Completion_Time - p[max_priority_index].Arrival_Time;
            p[max_priority_index].Waiting_Time = p[max_priority_index].Turnaround_ime - p[max_priority_index].Burst_Time;
            p[max_priority_index].Response_Time = p[max_priority_index].Start_Time - p[max_priority_index].Arrival_Time;

            total_turnaround_time += p[max_priority_index].Turnaround_ime;
            total_waiting_time += p[max_priority_index].Waiting_Time;

            is_completed[max_priority_index] = 1;
            completed++;
            current_time = p[max_priority_index].Completion_Time;
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
        int max_priority_index = -1;
        int max_priority_value = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (p[i].Arrival_Time <= current_time && is_completed[i] == 0)
            {
                if (p[i].Priority < max_priority_value)
                {
                    max_priority_value = p[i].Priority;
                    max_priority_index = i;
                }
                if (p[i].Priority == max_priority_value)
                {
                    if (p[i].Arrival_Time < p[max_priority_index].Arrival_Time)
                    {
                        max_priority_value = p[i].Priority;
                        max_priority_index = i;
                    }
                }
            }
        }
        if (max_priority_index != -1)
        {
            if (burst_time_remaining[max_priority_index] == p[max_priority_index].Burst_Time)
            {
                p[max_priority_index].Start_Time = current_time;
            }
            burst_time_remaining[max_priority_index] -= 1;
            current_time++;
            prev = current_time;
            if (burst_time_remaining[max_priority_index] == 0)
            {
                p[max_priority_index].Completion_Time = current_time;
                p[max_priority_index].Turnaround_ime = p[max_priority_index].Completion_Time - p[max_priority_index].Arrival_Time;
                p[max_priority_index].Waiting_Time = p[max_priority_index].Turnaround_ime - p[max_priority_index].Burst_Time;
                p[max_priority_index].Response_Time = p[max_priority_index].Start_Time - p[max_priority_index].Arrival_Time;

                total_turnaround_time += p[max_priority_index].Turnaround_ime;
                total_waiting_time += p[max_priority_index].Waiting_Time;

                is_completed[max_priority_index] = true;

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
void roundrobin(process p[], int n)
{
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
        cout << "Priority :";
        cin >> p[i].Priority;
        cout << endl;
    }
    cout << "\nAT - Arrival Time of the process\nBT - Burst time of the process\nST - Start time of the process\nCT - Completion time of the process\nTAT - Turnaround time of the process\nWT - Waiting time of the process\nRT - Response time of the process";
    int choice = 0;
    cout << "\n\n";
    while (choice != 3)
    {
        cout << "Enter Choice \n1.Preemptive \n2.NonPremptive \n3.Exit \n->";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            cout << "\nPreemptive Priority Scheduling\n";
            preemptive(p, n);
            cout << "\n";
        }
        break;
        case 2:
        {
            cout << "\nNon-Preemptive Priority Scheduling\n";
            NonPremptive(p, n);
            cout << "\n";
        }
        break;
        case 3:
        {
            exit(0);
        }
        default:
        {
            cout << "Wrong Choice";
        }
        break;
        }
    }
    NonPremptive(p, n);
    return 0;
}