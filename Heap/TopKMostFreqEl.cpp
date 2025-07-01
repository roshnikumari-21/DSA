// Given an integer array nums and an integer k, return the k most frequent elements.
// You may return the answer in any order.


//sc=O(N)
//tc=O(nlogn)--->less than that....

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;     //O(nlogn)
        vector<int> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++)     
        {
            mp[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        // minimum pq

        for (auto it : mp)           
        {
            pq.push({it.second, it.first});         //O(nlogn)
            if (pq.size() > k)
                pq.pop();
        }

        while (!pq.empty())
        {
            //  auto it=pq.top();
            int val = pq.top().second;
            ans.push_back(val);
            pq.pop();
        }

        return ans;
    }
};