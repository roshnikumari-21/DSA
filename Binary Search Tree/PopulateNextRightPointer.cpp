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



//__________level order traversal style__________(apna college)_______________________________________________________




// class Solution {
// public:
//     Node* connect(Node* root) {

//         if (root == NULL || root->left == NULL)
//             return root;

//         queue<Node*> q;
//         q.push(root);
//         q.push(NULL); // mark the end of a level
//         Node* prev = NULL;

//         while (!q.empty()) {

//             Node* curr = q.front();
//             q.pop();

//             if (curr == NULL) {

//                 if (q.size() == 0)
//                     break;

//                 q.push(NULL);
//             } else {
//                 if (curr->left != NULL) {
//                     q.push(curr->left);
//                 }

//                 if (curr->right != NULL) {
//                     q.push(curr->right);
//                 }

//                 if (prev != NULL) {
//                     prev->next = curr;
//                 }
//             }

//             prev = curr;
//         }

//         return root;
//     }
// };