// Complexity Type	Value
// Time	O(N)
// Space	O(N)
//each node is traversed almost once



// class Solution
// {
// public:
//     vector<vector<int>> zigzagLevelOrder(TreeNode *root)
//     {
//         vector<vector<int>> ans;
//         if (root == NULL)
//             return ans;

//         bool flag = 1;
//         queue<TreeNode *> q;
//         q.push(root);
//         while (!q.empty())
//         {
//             int len = q.size();
//             vector<int> temp(len);

//             for (int i = 0; i < len; i++)
//             {
//                 TreeNode *node = q.front();
//                 q.pop();
//                 int ind;
//                 if (flag)
//                 {
//                     ind = i;
//                 }
//                 else
//                     ind = (len - i - 1);
//                 temp[ind] = (node->val);
//                 if (node->left != NULL)
//                     q.push(node->left);
//                 if (node->right != NULL)
//                     q.push(node->right);
//             }
//             flag = (!flag);
//             ans.push_back(temp);
//         }

//         return ans;
//     }
// };