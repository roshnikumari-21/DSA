// mark parent pointers first
// if node value is not given---->first search it

//tc=O(N)+O(N)

// class Solution
// {
// public:
//     Node *search(int tar, Node *root)
//     {
//         // Base case: if the current node is null or the target is found
//         if (!root)
//             return NULL;
//         if (root->data == tar)
//             return root;

//         // Recursively search in the left subtree
//         Node *leftResult = search(tar, root->left);
//         if (leftResult)
//             return leftResult; // If found in the left subtree, return it

//         // Otherwise, recursively search in the right subtree
//         return search(tar, root->right);
//     }

//     void markp(Node *root, unordered_map<Node *, Node *> &mp)
//     {
//         queue<Node *> qu;
//         qu.push(root);
//         while (!qu.empty())
//         {
//             Node *nod = qu.front();
//             qu.pop();

//             if (nod->left)
//             {
//                 qu.push(nod->left);
//                 mp[nod->left] = nod;
//             }

//             if (nod->right)
//             {
//                 qu.push(nod->right);
//                 mp[nod->right] = nod;
//             }
//         }
//     }


//     int minTime(Node *root, int tar)
//     {
//         Node *tarr = search(tar, root);

//         unordered_map<Node *, Node *> mp;
//         markp(root, mp);

//         unordered_map<Node *, bool> vis;
//         queue<Node *> qu;
//         int cur = 0;
//         qu.push(tarr);
//         vis[tarr] = 1;

//         while (!qu.empty())
//         {
//             int size = qu.size();
//                
//             cur++;
//             for (int i = 0; i < size; i++)
//             {
//                 Node *nod = qu.front();
//                 qu.pop();
//                 if (nod->left && vis[nod->left] == 0)
//                 {
//                     qu.push(nod->left);
//                     vis[nod->left] = 1;
//                 }

//                 if (nod->right && vis[nod->right] == 0)
//                 {
//                     qu.push(nod->right);
//                     vis[nod->right] = 1;
//                 }

//                 if (mp[nod] && vis[mp[nod]] == 0)
//                 {
//                     qu.push(mp[nod]);
//                     vis[mp[nod]] = 1;
//                 }
//             }
//         }

//         return cur - 1;
//     }
// };