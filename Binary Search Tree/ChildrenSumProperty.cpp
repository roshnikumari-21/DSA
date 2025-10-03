// we can increase the value as many times as i want to satisfy the children sum property
// while going down increase the nodes value

#include <bits/stdc++.h>
using namespace std;

//tc=O(N)

// class Solution
// {
// public:
//     void changeTree(BinaryTreeNode<int> *root)
//     {
//         if (root == NULL)    //base case
//             return;

//         int child = 0;
//         if (root->left)
//         {
//             child += root->left->data;
//         }
//         if (root->right)
//         {
//             child += root->right->data;
//         }

//         if (child >= root->data)
//         {
//             root->data = child;
//         }
//         else    ---->left , right child me root ka data daaldo
//         {
//             if (root->left)
//                 root->left->data = root->data;
//             else if (root->right)
//                 root->right->data = root->data;
//         }

//         changeTree(root->left);
//         changeTree(root->right);

//         int tot = 0;
//         if (root->left)
//             tot += root->left->data;
//         if (root->right)
//             tot += root->right->data;

//         if (root->left || root->right)   //if not a leaf node
//             root->data = tot;
//     }
// };
