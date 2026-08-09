#include <bits/stdc++.h>
using namespace std;

//brute________________tc=O(N*Q)->for q queries_____________________________________________
// Input: arr[] = [1, 2, 3, 4, 1], queries = 2, indices[] = [0, 3]
// Output:  [3, 0]
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
