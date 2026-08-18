//using level order traversal



// Metric	Complexity
// Time   	O(N log N)
// Space     	O(N)




//multiset bcoz node can be of same value

// class Solution
// {
// public:
//     vector<vector<int>> verticalTraversal(TreeNode *root)
//     {
//         vector<vector<int>> ans;
//         if (root == NULL)
//             return ans;

//         map<int, map<int, multiset<int>>> mp;         //vertical,level-->all nodes
//         queue<pair<TreeNode *, pair<int, int>>> q;      
//         q.push({root, {0, 0}});         //node,(vertical,level)

//         while (!q.empty())
//         {
//             auto p = q.front();
//             q.pop();
//             TreeNode *nod = p.first;
//             int x = p.second.first;      //vertical
//             int y = p.second.second;        //level
//             mp[x][y].insert({nod->val});    //O(log(m))
//             if (nod->left != NULL)
//             {
//                 q.push({nod->left, {x - 1, y + 1}});
//             }
//             if (nod->right != NULL)
//             {
//                 q.push({nod->right, {x + 1, y + 1}});
//             }
//         }


//         for (auto p : mp)    p->representing verticals
//         {
//             vector<int> col;
//             for (auto q : p.second)
//             {
//                 col.insert(col.end(), q.second.begin(), q.second.end());   //keep in mind
//             }
//             ans.push_back(col);
//         }

//         return ans;
//     }
// };