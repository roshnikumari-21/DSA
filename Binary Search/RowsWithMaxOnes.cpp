#include <bits/stdc++.h>
using namespace std;

//brute___________________
//to count number of ones in all rows...


//better_________________________

//find lower_bound of one on each row--count number of ones and compare----->binary search solution...



class Solution
{
public:
    int rowWithMax1s(vector<vector<int>> &arr)
    {
        int n = arr.size();
        int m = arr[0].size();
        for (int j = 0; j < m; j++)
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i][j] == 1)
                    return i;
            }
        }
        return -1;
    }
};