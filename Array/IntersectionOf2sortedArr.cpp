#include <bits/stdc++.h>
using namespace std;

// A: [1 2 3 3 4 5 6]
// B: [3 3 5]
//Output 1: [3 3 5]


//tc=O(m+n)

vector<int> intersect(const vector<int> &a, const vector<int> &b)
{
    int n = a.size();
    int m = b.size();
    vector<int> arr;
    int i = 0, j = 0, k = 0;
    while (i < n && j < m)
    {
        if (a[i] == b[j])
        {
            arr.push_back(a[i]);
            i++;
            j++;
        }
        else if (a[i] < b[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
    return arr;
}
