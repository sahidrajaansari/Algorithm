#include <bits/stdc++.h>
using namespace std;
void LRU(string referencestring, int totalframes, int refrencestringsize)
{
    vector<int> framecontents(totalframes, -1);
    int flag, hit = 0, fault = 0, current_index = 0, isfull = 0;
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
        if (flag)
        {
            if (isfull)
            {
                int check=refrencestringsize;
                int position=0;
                for(int j=0;j<totalframes;j++){
                    for(int k=i-1;k>=0;k--){
                        if(k<check){
                            k=check;
                            position=j;
                        }
                        framecontents[position]=referencestring[i];
                    }
                }
            }
            else
            {
                fault++;
                framecontents[current_index] = referencestring[i];
                current_index++;
                if (current_index == totalframes)
                {
                    isfull = 1;
                }
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