#include <bits/stdc++.h>
using namespace std;




class MedianFinder
{
public:
    priority_queue<int> left;                             // Max heap (stores smaller half)
    priority_queue<int, vector<int>, greater<int>> right; // Min heap (stores larger half)

    MedianFinder() {}

    void addNum(int num)
    {
        if (left.empty() || num <= left.top())
            left.push(num);
        else
            right.push(num);

        // Maintain left's size exactly 1 greater than right's size
        if (left.size() > right.size() + 1)
        {
            right.push(left.top());
            left.pop();
        }
        else if (right.size() > left.size())
        {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian()
    {
        if (left.size() == right.size())
        {
            return (left.top() + right.top()) / 2.0;
        }
        else
        {
            return left.top();
        }
    }
};
