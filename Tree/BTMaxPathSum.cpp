//Given the root of a binary tree, return the maximum path sum of any non-empty path

// Given a binary tree T, find the maximum path sum.
// The path may start and end at any node in the tree.



// Complexity Type	Value
// Time	O(N)
// Space	O(H) → O(N) worst case

// class Solution
// {
// public:
//     int fxn(TreeNode *root, int &maxi)
//     {
//         if (root == NULL)
//             return 0;

//         // Recursively calculate left and right subtree contributions
//         int lh = max(0, fxn(root->left, maxi));  // Ignore negative paths
//         int rh = max(0, fxn(root->right, maxi)); // Ignore negative paths

//         // Update the maximum path sum with the current node's value as root of the path
//         maxi = max(maxi, lh + rh + root->val);

//         // Return the maximum path sum "including" this node (either left or right subtree + current node)
//         return max(lh, rh) + root->val;
//     }

//     int maxPathSum(TreeNode *root)
//     {
//         int maxi = INT_MIN; // Initialize to the smallest possible value
//         fxn(root, maxi);
//         return maxi;   //maxi is globally the maximum
//     }
// };