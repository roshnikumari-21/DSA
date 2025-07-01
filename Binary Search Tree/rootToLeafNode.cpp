#include <bits/stdc++.h>
using namespace std;


//using inorder traversal

//each node visited once--->O(N)
//tc=O(N+L⋅H),  where l is no. of path and h is length of each path


// vector<int> temp;         //global declarations
// vector<string> ans;

// void solve(BinaryTreeNode<int> *root)
// {
//     temp.push_back(root->data);
//     if (root->left == NULL && root->right == NULL)     //base case-->leaf node
//     {
//         string s = "";
//         for (int i = 0; i < temp.size(); i++)
//         {
//             string a = to_string(temp[i]);
//             s += a;
//             s += " ";
//         }

//         ans.push_back(s);
//         return;
//     }



//     if (root->left)
//     {
//         solve(root->left);
//         temp.pop_back();
//     }
//     if (root->right)
//     {
//         solve(root->right);
//         temp.pop_back();
//     }
// }

// vector<string> allRootToLeaf(BinaryTreeNode<int> *root)
// {

//     solve(root);
//     return ans;
