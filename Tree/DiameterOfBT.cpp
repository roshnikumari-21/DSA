// The diameter of a binary tree is the length of the longest path between any
//  two nodes in a tree. This path may or may not pass through the root.

// brute way_________________tc=O(N^2)_________________________________________________________

// class Solution {
//     public:
//         int maxi = 0;   //global variable

//         int tothei(TreeNode* root) {
//             if (root == nullptr)
//                 return 0;

//             int lh = tothei(root->left);
//             int rh = tothei(root->right);
//             return 1 + max(lh, rh);
//         }

//         void solve(TreeNode* root) {
//             if (root == NULL)
//                 return;
//             int left = tothei(root->left);
//             int right = tothei(root->right);

//             maxi = max(maxi, left + right);
//             solve(root->left);
//             solve(root->right);
//         }

//         int diameterOfBinaryTree(TreeNode* root) {
//             solve(root);
//             return maxi;
//         }
//     };

// optimised_______________tc=O(N)___________________________________________________________________________




// class Solution
// {
// public:
//     int maxi = 0;   //global variable

//     int tothei(TreeNode *root)
//     {
//         if (root == NULL)
//             return 0;

//         int left = tothei(root->left);
//         int right = tothei(root->right);
       
//         maxi = max(maxi, left + right);
//         return 1 + max(left, right);
//     }


//     int diameterOfBinaryTree(TreeNode *root)
//     {
//         tothei(root);
//         return maxi;
//     }
// };