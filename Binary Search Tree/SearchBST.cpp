// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.

//tc =O(log(N))  sc=O(log(N))

 #include <bits/stdc++.h>
 using namespace std;
 

//  class Solution {
//     public:
//         TreeNode* searchBST(TreeNode* root, int val) {
//             if(root==NULL) return root;
//              if(root->val==val) return root;
//             if(root->val>val) return searchBST(root->left,val);
//             if(root->val<val) return searchBST(root->right,val);
//            return NULL;
            
//         }
//     };