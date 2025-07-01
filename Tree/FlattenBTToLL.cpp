// Given the root of a binary tree, flatten the tree into a "linked list":
//The "linked list" should be in the same order as a pre-order traversal of the binary tree.

//right, left, root


//tc=O(N)
//sc=O(n), but for best case O(log(N))

// class Solution {
// public:

//   void f(TreeNode* nod,TreeNode* &prev){
//     if(nod==NULL) return;

//     f(nod->right,prev);
//     f(nod->left,prev);
//      nod->right=prev;
//     nod->left=NULL;
   
//     prev=nod;

//   }
//     void flatten(TreeNode* root) {
//         TreeNode* prev=NULL;
//         TreeNode* nod=root;
//         f(nod,prev);
//         return;
        
//     }
// };

//do believe in recursion..