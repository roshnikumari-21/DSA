// Given a binary search tree (BST), find the lowest common ancestor (LCA) node of two given
//  nodes in the BST.


// Complexity Type	Value
// Time	O(log N) avg, O(N) worst
// Space	O(log N) avg, O(N) worst



// class Solution {
//     public:
//         TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//             if(root==NULL) return NULL;


//             int temp=root->val;
//             if(p->val<temp && q->val<temp){
//                 return lowestCommonAncestor(root->left,p,q);
//             }

//              if(p->val>temp && q->val>temp){
//                 return lowestCommonAncestor(root->right,p,q);
//             }
//              return root;

//         }
//     };