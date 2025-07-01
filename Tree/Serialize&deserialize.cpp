// return a string
//we are using level wise traversal i.e . maintain a queue
//tc= O(n)   //sc=O(n)


#include <bits/stdc++.h>
using namespace std;



    // class Codec
    // {
    // public:
    //     // Encodes a tree to a single string.
    //     string serialize(TreeNode *root)
    //     {
    //         string str = "";
    //         if (root == NULL)
    //             return str;

    //         queue<TreeNode *> qu;
    //         qu.push(root);
    //         while (!qu.empty())
    //         {
    //             TreeNode *nod = qu.front();
    //             qu.pop();
    //             if (nod == NULL)
    //                 str.append("#,");
    //             else
    //             {
    //                 str.append(to_string(nod->val) + ',');
    //             }
    //             if (nod != NULL)
    //             {
    //                 qu.push(nod->left);
    //                 qu.push(nod->right);
    //             }
    //         }
    //         return str;
    //     }

    //     // Decodes your encoded data to tree.
    //     TreeNode *deserialize(string data)
    //     {
    //         if (data.size() == 0)
    //             return NULL;                    //if string is empty, null tree
    
    //         stringstream s(data);
    //         string str;
    //         getline(s, str, ',');
    //         TreeNode *root = new TreeNode(stoi(str));

    //         queue<TreeNode *> q;
    //         q.push(root);
    //         while (!q.empty())
    //         {
    //             TreeNode *nod = q.front();
    //             q.pop();
    //             getline(s, str, ',');                   //for left
    //             if (str == "#")
    //             {
    //                 nod->left = NULL;
    //             }
    //             else
    //             {
    //                 TreeNode *nwnod = new TreeNode(stoi(str));
    //                 nod->left = nwnod;
    //                 q.push(nwnod);
    //             }

    //             getline(s, str, ',');                 //for right
    //             if (str == "#")
    //             {
    //                 nod->right = NULL;
    //             }
    //             else
    //             {
    //                 TreeNode *nwnod2 = new TreeNode(stoi(str));
    //                 nod->right = nwnod2;
    //                 q.push(nwnod2);
    //             }
    //         }

    //         return root;
    //     }
    // };
