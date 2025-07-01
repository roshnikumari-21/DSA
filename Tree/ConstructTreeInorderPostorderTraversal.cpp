#include <bits/stdc++.h>
using namespace std;

// Metric	Complexity
// Time	O(N²)
// Time (optimized)	O(N) with hash map--->unordered map for O(1) lookup
// Space	O(N)

//from postorder_______________________

// class Solution
// {
// public:
//     int search(int val, vector<int> &inorder)   //O(N)
//     {
//         int n = inorder.size();
//         for (int i = 0; i < n; i++)
//         {
//             if (inorder[i] == val)
//                 return i;
//         }
//         return -1;
//     }

//     TreeNode *build(vector<int> &postorder, vector<int> &inorder, int &postInd,
//                     int instart, int inend)
//     {
//         int n = inorder.size();
//         if (postInd >= n)
//             return NULL;
//         if (instart > inend)
//             return NULL;

//         int vall = postorder[postInd];
//         postInd--;
//         int inInd = search(vall, inorder);
//         TreeNode *nod = new TreeNode(vall);
//         nod->right = build(postorder, inorder, postInd, inInd + 1, inend);
//         nod->left = build(postorder, inorder, postInd, instart, inInd - 1);

//         return nod;
//     }

//     TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
//     {
//         int n = inorder.size();
//         int postInd = n - 1;

//         return build(postorder, inorder, postInd, 0, n - 1);
//     }
// };