// brute_______________________________________

#include <bits/stdc++.h>
using namespace std;

// tc=O(N*K)Log(N*K)

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        for (auto it : arr)
        {
            for (auto i : it)
            {
                ans.push_back(i);
            }
        }

        sort(ans.begin(), ans.end());
        return ans;
    }
};

// optimal______________________________
// using minHeap

//O(K*N * log K),   k is number of arrays, n is no. of elements per array
//sc=O(k*n)

class Solution
{
public:
    // Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        // Min-heap: {value, {row, col}}
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            minHeap;

        // Push the first element of each array into the min heap
        for (int i = 0; i < K; ++i)
        {
            if (!arr[i].empty())
                minHeap.push({arr[i][0], {i, 0}});
        }

        vector<int> result;

        while (!minHeap.empty())
        {
            auto it = minHeap.top();
            minHeap.pop();

            int val = it.first;
            int row = it.second.first;
            int col = it.second.second;

            result.push_back(val);

            // Push the next element from the same row, if it exists
            if (col + 1 < arr[row].size())
            {
                minHeap.push({arr[row][col + 1], {row, col + 1}});
            }
        }

        return result;
    }
};
