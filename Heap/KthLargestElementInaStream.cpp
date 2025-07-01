// brute____________________
// sort every time and find answer......

// we will take min heap to remove extra smaller elements

//optimised
//tc=O(log(N))

#include <bits/stdc++.h>
using namespace std;

class KthLargest
{
public:
    int K;
    priority_queue<int, vector<int>, greater<int>> pq;  //minpq

    KthLargest(int k, vector<int> &nums)
    {
        K = k;

        for (int &num : nums)
        {
            pq.push(num);

            if (pq.size() > k)
                pq.pop(); // min element will be popped
        }
    }

    int add(int val)
    {
        pq.push(val);

        if (pq.size() > K)
            pq.pop();

        return pq.top(); // kth largest is the smallest in the min-heap
    }
};
