#include <bits/stdc++.h>
using namespace std;

// brute_______________________________________________

class StockSpanner
{
public:
    vector<int> arr;
    StockSpanner()
    {
        vector<int> arr;
    }

    int next(int val)
    {
        int cnt = 1;
        arr.push_back(val);
        for (int i = arr.size() - 2; i >= 0; i--)
        {
            if (arr[i] <= val)
                cnt++;
            else
                break;
        }
        return cnt;
    }
};

// ooptimised one______________________________________________
// using pge

// Metric	Complexity
// Time (per next())	O(1) amortized
// Time (total for n)	O(n)
// Space	O(n)



class StockSpanner
{
public:
    vector<int> arr;
    stack<int> st;
    int i = -1;
    StockSpanner()
    {
    }

    int next(int val)
    {
        i++;
        arr.push_back(val);
        int ind = -1;
     
        while (!st.empty() && arr[st.top()] <= val)
            st.pop();

        if (st.empty())
            ind = -1;
        else
            ind = st.top();

        int cnt = i - ind;    //dhyan do...
        st.push(i);

        return cnt;
    }
};