#include <bits/stdc++.h>
using namespace std;

// Metric	Complexity
// Time	O(N²)
// Time (optimized)	O(N)____________ with hash map--->unordered map for O(1) lookup
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



//_________________________________________________________________________
//with map tc=O(N) faster lookup



// class Solution {
// public:
//     TreeNode* solve(vector<int>& ino, vector<int>& post, int& postind, int inst,
//                     int inend, unordered_map<int, int>& mp) {
//         if (inst > inend)
//             return NULL;
//         int val = post[postind--];
//         TreeNode* nod = new TreeNode(val);
//         int inind = mp[val];

//         nod->right = solve(ino, post, postind, inind + 1, inend, mp);
//         nod->left = solve(ino, post, postind, inst, inind - 1, mp);
//         return nod;
//     }

//     TreeNode* buildTree(vector<int>& ino, vector<int>& post) {
//         int n = post.size();
//         int postind = n - 1;
//         unordered_map<int, int> mp;
//         for (int i = 0; i < n; i++) {
//             mp[ino[i]] = i;
//         }
//         return solve(ino, post, postind, 0, n - 1, mp);
//     }
// };