#include <bits/stdc++.h>
using namespace std;


//Given the root of a binary tree, invert the tree, and return its root.
//tc=O(N)   sc=O(logn) and O(n) for skewed tree (recursion depth)

// class Solution {
// public:
//    void solve(TreeNode* root){
//     if(root==NULL) return ;
//     solve(root->left);
//     solve(root->right);
//     TreeNode* temp=root->left;
//     root->left=root->right;
//     root->right=temp;
//     return ;
//    }

//     TreeNode* invertTree(TreeNode* root) {
//        solve(root);
//        return root;
        
//     }
// };