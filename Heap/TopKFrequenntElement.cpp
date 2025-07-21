// Given an integer array nums and an integer k, return the k most frequent elements.
//  You may return the answer in any order.

// we will use a min-heap ds..

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        map<int, int> mp;
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
            pq.push({it.second, it.first});
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

//___using bucket sort_________tc=O(n)______________________

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<vector<int>> buc(n + 1);
        map<int, int> mp;
        vector<int> ans;

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (auto it : mp)
        {

            buc[it.second].push_back(it.first);
        }

        for (int i = n; i >= 0; i--)
        {
            if (buc[i].size() != 0)
            {
                for (auto it : buc[i])
                {
                    ans.push_back(it);
                    if (ans.size() == k)
                        break;
                }
            }

            if (ans.size() == k)
                break;
        }

        return ans;
    }
};
