//using a recursive solution---->takes only auxilliary space

//tc=O(N)---->going through each node
//sc=O(N)--->worst case, if skew tree


// class Solution {
//     public:
//         int maxDepth(TreeNode* root) {
//             if(root==NULL) return 0;
//             int left=maxDepth(root->left);
//             int right=maxDepth(root->right);
//             return 1+max(left,right);
            
//         }
//     };