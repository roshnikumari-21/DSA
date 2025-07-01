
//tc=O(n)
//sc=O(log(n)) or worst can be O(N)---->recursion depth

// class Solution
// {
// public:
//     bool check(TreeNode *le, TreeNode *ri)
//     {
//         if (le == NULL && ri == NULL)
//             return true;
//         if (le == NULL || ri == NULL)
//             return false;
//         if (le->val != ri->val)
//             return false;

//         return (check(le->left, ri->right) && check(le->right, ri->left));
//     }

//     bool isSymmetric(TreeNode *root)
//     {
//         if (root == NULL)
//             return true;   //return true;
//         
//         return check(root->left, root->right);
//     }
// };