// always connect the smallest two ropes first
#include <bits/stdc++.h>
using namespace std;

int minCost(vector<int> &a)
{
    priority_queue<int, vector<int>, greater<int>> pq;   //min-heap

    for (int i = 0; i < a.size(); i++)
    {
        pq.push(a[i]);
    }

    int ans = 0;

    while (pq.size() > 1)
    {
        int first = pq.top();
        pq.pop();
        int second = pq.top();
        pq.pop();

        int sum = first + second;
        ans += sum;

        pq.push(sum);
    }

    return ans;
}