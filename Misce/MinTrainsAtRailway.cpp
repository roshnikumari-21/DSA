// Your task is to determine the minimum number of platforms required at the station to
//  ensure that no train is kept waiting.

// Input: arr[] = [900, 1235, 1100], dep[] = [1000, 1240, 1200]
// Output: 1

// brute force...tc=O(n^2)__________________________
//by counting the number of intersections for each train...and calculating the maximum among them.....

// optimal____________________________________________________________________________________

// as the time passes by, i observe trains coming and going thus maintainging a count ...of platform needed

//tc= 2* O(nlogn + n)  
//sc=O(1)

//but we are distorring the original array...so we can take a thrid array put every time in it (arr+dpt)
//and sort it using vector of pair

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPlatform(vector<int> &arr, vector<int> &dep)
    {
        int n = dep.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int i = 0, j = 0;
        int cnt = 0, maxi = 0;
        while (i < n)
        {
            if (arr[i] <= dep[j])
            {
                cnt++;
                i++;
            }
            else if (arr[i] > dep[j])
            {
                cnt--;
                j++;
            }
            maxi = max(maxi, cnt);
        }
        return maxi;
    }
};