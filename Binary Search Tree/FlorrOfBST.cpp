// Given a binary search tree and an integer.Find the floor value of a key in a binary search tree .

// basically predecessor



// void solve(BinaryTreeNode<int> *node, int k, int &ans)
// {
//     if (node == NULL)   
//         return;

//     if (node->data > k)
//     {
//         solve(node->left, k, ans);
//     }
//     else if (node->data <= k)
//     {
//         ans = max(node->data, ans);
//         solve(node->right, k, ans);
//     }
// }

// int Floor(BinaryTreeNode<int> *node, int k)
// {
//     int ans = INT_MIN;
//     solve(node, k, ans);
//     return ans;
// }
