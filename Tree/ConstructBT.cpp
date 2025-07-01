#include <bits/stdc++.h>
using namespace std;



// Time Complexity: O(n) – each node is inserted once.

// Space Complexity: O(n) – due to the queue.

//only make a binary tree.....not a binary search tree.

// class Solution
// {
// public:
//     void create_tree(node *root, vector<int> &vec)
//     {
//         int n = vec.size();
//         if (n == 0)
//             return;

//         queue<node *> q;
//         int i = 1;
//         q.push(root);
//         while (!q.empty() && i < n)
//         {
//             node *curr = q.front();
//             q.pop();

//             if (i < n)
//             {
//                 curr->left = newNode(vec[i]);
//                 q.push(curr->left);
//                 i++;
//             }

//             if (i < n)
//             {
//                 curr->right = newNode(vec[i]);
//                 q.push(curr->right);
//                 i++;
//             }
//         }
//     }
// };
