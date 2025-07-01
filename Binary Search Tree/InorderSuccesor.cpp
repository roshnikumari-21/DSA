#include <bits/stdc++.h>
using namespace std;

//inorder->left, node, right

// brute way----> store the inorder in vector, find the just greater element (sorted)
// tc=O(n)   sc=O(n)

//_________________________________________________________________________________________
// second way-----> while traversing inorder, find the successor
// tc=O(n)   sc=O(1)

// int pre, suc;
// void inorder(TreeNode *root, int key)
// {
//     if (root == NULL)
//         return;

//     inorder(root->left, key);
//     if (root->data > key)
//         suc = min(suc, root->data);
//     if (root->data < key)
//         pre = max(pre, root->data);

//     inorder(root->right, key);
// }

// pair<int, int> predecessorSuccessor(TreeNode *root, int key)
// {
//     pre = -1, suc = INT_MAX;
//     inorder(root, key);
//     if (suc == INT_MAX)
//         suc = -1;
//     return {pre, suc};
// }

//________________________________________________________________________________________________
// third one most optimal
// tc=O(logn)   sc=O(1)

//finding both successor and predecessor



// int findsuc(TreeNode *root, int key)
// {
//     TreeNode *suc = NULL;
//     while (root != NULL)
//     {
//         if (root->data <= key)
//             root = root->right;
//         else
//         {
//             suc = root;
//             root = root->left;
//         }
//     }
//     if (suc == NULL)
//         return -1;
//     else
//         return suc->data;
// }

// int findpre(TreeNode *root, int key)
// {
//     TreeNode *pre = NULL;
//     while (root != NULL)
//     {
//         if (root->data >= key)
//             root = root->left;
//         else
//         {
//             pre = root;
//             root = root->right;
//         }
//     }
//     if (pre == NULL)
//         return -1;
//     else
//         return pre->data;
// }

// pair<int, int> predecessorSuccessor(TreeNode *root, int key)
// {

//     int a, b;
//     a = findsuc(root, key);
//     b = findpre(root, key);
//     return {b, a};
// }


//this is also the code for ceil and floor value in a bst...