// for balanced----> height(left)-hegit(right)<=1

// brute solution_______________________________________________________________________________
// tc=O(N^2)

// int find(TreeNode *root)
// {
//     if (root == NULL)
//         return 0;
//     int left = find(root->left);
//     int right = find(root->right);
//     return 1 + max(left, right);   //returning height
// }

// class Solution
// {
// public:
//     bool isBalanced(TreeNode *root)
//     {
//         if (root == NULL)
//             return true;
//         int lh = find(root->left);
//         int rh = find(root->right);
//         if (abs(lh - rh) > 1)
//             return false;

//         bool left = isBalanced(root->left);
//         bool right = isBalanced(root->right);
//         if (left == false || right == false)
//             return false;
//         return true;
//     }
// };

// optimal________tc=O(N)___________________sc=O(N)->recursive stack space_____________________________________________





// class Solution
// {
// public:
//     int check(TreeNode *node)
//     {
//         if (node == NULL)
//             return 0;

//         int lh = check(node->left);
//         int rh = check(node->right);

//         if (lh == -1 || rh == -1)
//             return -1;

//         if (abs(lh - rh) > 1)
//             return -1;

//         return max(lh, rh) + 1;    //return height
//     }


//     bool isBalanced(TreeNode *node)
//     {
//         if (check(node) != -1)
//             return true;
//         else
//             return false;
//     }
// };