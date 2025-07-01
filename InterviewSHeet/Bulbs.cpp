#include <bits/stdc++.h>
using namespace std;

//  https://www.interviewbit.com/problems/interview-questions/

int bulbs(vector<int> &arr)
{
    int n = arr.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 1 && ans % 2 == 1)
            ans++;
        else if (arr[i] == 0 && ans % 2 == 0)
            ans++;
    }
    return ans;
}
