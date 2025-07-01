// solve using bfs traversal
// first we will create a parent map

// again do a bfs traversasl---> queue,visited

// if any tree is burned in a particular level--->time will incresased

// tc=O(N)+O(N)->for two times bfs
// sc=O(N)




// class Solution
// {
// public:
//     TreeNode *search(int tar, TreeNode *root)
//     {
//         // Base case: if the current node is null or the target is found
//         if (!root)
//             return NULL;
//         if (root->val == tar)
//             return root;

//         // Recursively search in the left subtree
//         TreeNode *leftResult = search(tar, root->left);
//         if (leftResult)
//             return leftResult; // If found in the left subtree, return it

//         // Otherwise, recursively search in the right subtree
//         return search(tar, root->right);
//     }

//     void markp(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &mp)
//     {
//         queue<TreeNode *> qu;
//         qu.push(root);
//         while (!qu.empty())
//         {
//             TreeNode *nod = qu.front();
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

//     int amountOfTime(TreeNode *root, int tar)
//     {
//         TreeNode *tarr = search(tar, root);

//         unordered_map<TreeNode *, TreeNode *> mp;
//         markp(root, mp);

//         unordered_map<TreeNode *, bool> vis;
//         queue<TreeNode *> qu;
//         int cur = 0;
//         qu.push(tarr);
//         vis[tarr] = 1;

//         while (!qu.empty())
//         {
//             int size = qu.size();

//             cur++;
//             for (int i = 0; i < size; i++)
//             {
//                 TreeNode *nod = qu.front();
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