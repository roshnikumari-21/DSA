// Time	    O(n log n)
// Space	O(n)



//class Solution
// {
// public:
//     vector<int> bottomView(Node *root)
//     {
//         vector<int> ans;
//         if (root == NULL)          //edge case
//             return ans;


//         map<int, int> mp;    //line,data
//         queue<pair<Node *, int>> qu;


//         qu.push({root, 0});
//         while (!qu.empty())
//         {
//             auto it = qu.front();
//             qu.pop();
//             Node *nod = it.first;
//             int line = it.second;
//             mp[line] = nod->data;
//             if (nod->left)
//                 qu.push({nod->left, line - 1});
//             if (nod->right)
//                 qu.push({nod->right, line + 1});
//         }


//         for (auto it : mp)
//         {
//             ans.push_back(it.second);
//         }
//         return ans;
//     }
// };
