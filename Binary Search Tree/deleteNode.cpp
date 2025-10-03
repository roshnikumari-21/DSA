#include <bits/stdc++.h>
using namespace std;


//tc and sc=O(logn)
//worst case= O(N)

// class Solution {
//     public:
    
//        TreeNode* inorderS(TreeNode* root){   //inorder successor
//             while(root->left!=NULL){
//                 root=root->left;
//             }
//             return root;
//        }


//         TreeNode* deleteNode(TreeNode* root, int key) {
//            if(root==NULL) return root;

//             if(root->val > key) root->left=deleteNode(root->left,key);
//             else if(root->val < key) root->right=deleteNode(root->right,key);
//             else{
//                 if(root->left==NULL){
//                     TreeNode* temp=root->right;
//                     delete root;
//                     return temp;
                    
//                 }
    
//                  if(root->right==NULL){
//                     TreeNode* temp=root->left;
//                     delete root;
//                     return temp;
                    
//                 }
//                 TreeNode* temp=inorderS(root->right);
//                 root->val=temp->val;
//                 root->right= deleteNode(root->right,temp->val);
    
//             }
//             return root;
            
//         }
//     };