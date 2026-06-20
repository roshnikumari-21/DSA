#include <bits/stdc++.h>
using namespace std;

// brute--->store all nodes in vector--->sort it----------> take kth element
// tc=O(nLogN)

// property--->inorder is always sorted for a BST
// do inorder traversal



// class Solution
// {
// public:
//     void inorder(TreeNode *root, int k, int &cnt, int &ans)
//     {
//         if (root == NULL)
//             return;
//         inorder(root->left, k, cnt, ans);
//         cnt++;
//         if (cnt == k)
//         {
//             ans = root->val;
//             return;
//         }
//         inorder(root->right, k, cnt, ans);
//         return;
//     }


//     int kthSmallest(TreeNode *root, int k)
//     {
//         int cnt = 0, ans = 0;
//         inorder(root, k, cnt, ans);
//         return ans;
//     }
// };


//for kth largest=(n-k+1)th smallest