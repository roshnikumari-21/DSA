#include <bits/stdc++.h>
using namespace std;




// Time   	O(N)--->processing all nodes
// Space	O(1)


// class Solution
// {
// public:
//     Node *connect(Node *root)
//     {
//         if (root == NULL)
//             return root;

//         Node *cur = root;
//         while (cur->left)
//         {
//             Node *nextlevel = cur->left;
//             while (cur)
//             {
//                 cur->left->next = cur->right;
//                 if (cur->next)
//                 {
//                     cur->right->next = cur->next->left;
//                 }
//                 cur = cur->next;
//             }
//             cur = nextlevel;
//         }

//         return root;
//     }
// };
