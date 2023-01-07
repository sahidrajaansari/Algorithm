#include <bits/stdc++.h>
using namespace std;
void fifo(string referencestring, int totalframes, int refrencestringsize)
{
    vector<int> framecontents(totalframes, -1);
    int flag, hit = 0, fault = 0,current_index=0;
    for (int i = 0; i < refrencestringsize; i++)
    {
        flag = 1;
        for (int j = 0; j < totalframes; j++)
        {
            if (referencestring[i] == framecontents[j])
            {
                hit++;
                flag = 0;
                break;
            }
        }
        if(flag){
            fault++;
            framecontents[current_index]=referencestring[i];
            current_index++;
            if(current_index==totalframes){
                current_index=0;
            }
        }
    }
}
int main()
{
    int totalframes;
    string referencestring;
    cin >> totalframes;
    cin >> referencestring;
    return 0;
}