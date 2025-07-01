#include <bits/stdc++.h>
using namespace std;

//level order traversal
//line concept


//tc=O(N)___________     sc=O(N)

// class Solution
// {
// public:
//     // Function to return a list of nodes visible from the top view
//     // from left to right in Binary Tree.
//     vector<int> topView(Node *root)
//     {
//         vector<int> ans;
//         if (root == NULL)
//             return ans;


//         map<int, int> mp;        //line,node----->as line will be in sorted order
//         queue<pair<Node *, int>> qu;            //node,line


//         qu.push({root, 0});
//         while (!qu.empty())
//         {
//             auto it = qu.front();
//             qu.pop();
//             Node *nod = it.first;
//             int line = it.second;
//             if (mp.find(line) == mp.end())     //check condition
//                 mp[line] = nod->data;
//             if (nod->left != NULL)
//                 qu.push({nod->left, line - 1});
//             if (nod->right != NULL)
//                 qu.push({nod->right, line + 1});
//         }

//         for (auto it : mp)
//         {
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };

//dont prefer the recursive way--->bcoz that will be complicated...