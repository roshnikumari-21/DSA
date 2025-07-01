// convert the subtree into string and compare
//duplicate means the structure should also be same

// tc=O(N^2)
// use map to store the string

#include <bits/stdc++.h>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution
{
public:
    string getSubTreeString(TreeNode *root, unordered_map<string, int> &mp, vector<TreeNode *> &res)
    {
        if (root == NULL)
            return "N";

        string s = to_string(root->val) + "," +
                   getSubTreeString(root->left, mp, res) + "," +
                   getSubTreeString(root->right, mp, res);

        if (mp[s] == 1)   //this string is already present
        {
            res.push_back(root);
        }

        mp[s]++;
        return s;
    }

    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        unordered_map<string, int> mp;
        vector<TreeNode *> res;
        getSubTreeString(root, mp, res);
        return res;
    }
};