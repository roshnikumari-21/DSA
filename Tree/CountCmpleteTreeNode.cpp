//tc=O(N)

//This C++ code defines a solution to count the number of nodes in a binary tree.

// class Solution {
//     public:
//        int cnt(TreeNode* root){
//            if(root==NULL) return 0;
//            int le=  cnt(root->left);
//            int ri= cnt(root->right);
//            return 1+le+ri ;
//        }
//         int countNodes(TreeNode* root) {
//           if(root==NULL ) return 0;
//           return cnt(root);
            
//         }
//     };