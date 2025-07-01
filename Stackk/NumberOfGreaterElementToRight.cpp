#include <bits/stdc++.h>
using namespace std;

//brute________________tc=O(N*Q)->for q queries_____________________________________________

class Solution
{
public:
    vector<int> count_NGE(int n, vector<int> &arr, int qu, vector<int> &indices)
    {
        vector<int> ans(n, 0);

        for (int i = n - 2; i >= 0; i--)
        {
            int cnt = 0;
            for (int j = i + 1; j < n; j++)
            {
                if (arr[j] > arr[i])
                    cnt++;
            }
            ans[i] = cnt;
        }
        vector<int> res;
        for (int i = 0; i < qu; i++)
        {
            res.push_back(ans[indices[i]]);
        }
        return res;
    }
};
