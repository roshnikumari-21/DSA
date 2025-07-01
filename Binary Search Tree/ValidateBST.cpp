// Given the root of a binary tree, determine if it is a valid binary search tree (BST).


//tc=O(N)
//sc=O(H)


// class Solution
// {
// public:
//     bool f(TreeNode *root, long long start, long long end)
//     {
//         if (root == NULL)
//             return true;

//         int val = root->val;
//         if (val <= start || val >= end)
//             return false;

//         return (f(root->left, start, val) && f(root->right, val, end));
//     }


//     bool isValidBST(TreeNode *root)
//     {

//         return f(root, LLONG_MIN, LLONG_MAX);
//     }
// };