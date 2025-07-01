// min distance between any of the two cows is maximum

// example
// arr=[0,3,4,7,10,9]
// cows=4

// computing consecutive distance stalls will be enough...coz we just need minimum

// range is between 1 and (max-min)

// brute___________linear search_______________

// binary search_____________________________________________________
// tc=O(nlogn)+log(n)+O(n)



#include <bits/stdc++.h>
using namespace std;



bool canWePlace(vector<int> &stalls, int dist, int cows)
{
    int cntCows = 1, last = stalls[0];
    for (int i = 1; i < stalls.size(); i++)
    {
        if (stalls[i] - last >= dist)
        {
            cntCows++;
            last = stalls[i];
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}

int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = stalls[n - 1] - stalls[0];
    while (low <= high)
    {
        int mid = (low + high) / 2;    //here mid represents dist.
        if (canWePlace(stalls, mid, k) == true)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}
