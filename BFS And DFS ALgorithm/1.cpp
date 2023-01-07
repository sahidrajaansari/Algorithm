#include <bits/stdc++.h>
using namespace std;

int printDistinct(string str)
{
    unordered_set<char> s;
    int count = 0;
    for (int i = 0; i < str.size(); i++)
    {
        s.insert(str[i]);
        if (i % 2 == 0)
        {
            int x = s.size();
            if (x <= 1)
            {
                break;
            }
            for (int i = 2; i <= sqrt(x); i++)
                if (x % i == 0)
                {
                    count++;
                    break;
                }
        }
    }
    return count;

    // Return Answer
    return s.size();
}

// Driver code
int main()
{
    string str = "GeeksforGeeks";
    printDistinct(str);
    return 0;
}
