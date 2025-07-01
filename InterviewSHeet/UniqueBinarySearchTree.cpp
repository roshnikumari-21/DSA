//Given A, generate all structurally unique BST's (binary search trees) that store values 1...A.




// vector<TreeNode *> solve(int st, int end)
// {
//     vector<TreeNode *> ans;
//     if (st > end)
//     {
//         ans.push_back(NULL);
//         return ans;
//     }

//     for (int i = st; i <= end; i++)
//     {
//         vector<TreeNode *> left = solve(st, i - 1);
//         vector<TreeNode *> right = solve(i + 1, end);

//         for (auto it : left)
//         {
//             for (auto it2 : right)
//             {
//                 TreeNode *nod = new TreeNode(i);
//                 nod->left = it;
//                 nod->right = it2;
//                 ans.push_back(nod);
//             }
//         }
//     }
//     return ans;
// }

// vector<TreeNode *> Solution::generateTrees(int n)
// {
//     return solve(1, n);
// }
