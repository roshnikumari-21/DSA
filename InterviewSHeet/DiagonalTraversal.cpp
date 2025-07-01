#include <bits/stdc++.h>
using namespace std;


//  https://www.interviewbit.com/problems/diagonal-traversal/


// void diagT(TreeNode *a, map<int, vector<int>> &mp, int diag)
// {
//     if (a == NULL)
//         return;
//     mp[diag].push_back(a->val);
//     diagT(a->left, mp, diag + 1);
//     diagT(a->right, mp, diag);
// }

// vector<int> Solution::solve(TreeNode *a)
// {
//     map<int, vector<int>> mp;
//     int diag = 0;
//     diagT(a, mp, diag);
//     vector<int> ans;
//     for (auto it : mp)
//     {
//         for (auto i : it.second)
//             ans.push_back(i);
//     }
//     return ans;
// }