// Input : arr[] = [4, 3, 1, 5, 6]
// Output : 11


//Given an array of integers, find the maximum sum of any pair of adjacent elements in the array.

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find pair with maximum sum
    int pairWithMaxSum(vector<int> &arr)
    {
        int n = arr.size();
        int maxi = -1;
        for (int i = 0; i < n - 1; i++)
        {
            int sum = arr[i] + arr[i + 1];
            maxi = max(sum, maxi);
        }
        return maxi;
    }
};