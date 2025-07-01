// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Explanation:
// 1 + 2 + 4 = 7
// There are no other valid combinations.

// Only numbers 1 through 9 are used.
// Each number is used at most once.

//tc=O(2^9)

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void f(vector<int> &v, int k, int sum, int cnt, int ind)
    {
        if (cnt == k)
        {
            if (sum == 0)
                ans.push_back(temp);
            return;
        }

        if (ind == v.size() || sum < 0)
            return;
        temp.push_back(v[ind]);
        f(v, k, sum - v[ind], cnt + 1, ind + 1);
        temp.pop_back();
        
        f(v, k, sum, cnt, ind + 1);
    }


    
    vector<vector<int>> combinationSum3(int k, int sum)
    {
        int ind = 0, cnt = 0;
        vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        f(v, k, sum, cnt, ind);
        return ans;
    }
};