// max width= max. no. of nodes in a level

// level order traversal
// we will index every node O based, then formula= (last index-first index+1) for max width
// solve the issue of overfloweing

//using 0 based indexing

//tc=O(N)     sc=O(N)



// class Solution
// {
// public:
//     int widthOfBinaryTree(TreeNode *root)
//     {
//         if (root == NULL)
//             return 0;

//         int ans = 0;
//         queue<pair<TreeNode *, int>> qu;    (node,indexing)
//         qu.push({root, 0});

//         while (!qu.empty())
//         {
//             int size = qu.size();
//             int mini = qu.front().second;
//             int first, last;
//             for (int i = 0; i < size; i++)
//             {
//                 auto it = qu.front();
//                 qu.pop();
//                 TreeNode *nod = it.first;
//                 int ind = it.second - mini;      //modified index
//                 if (i == 0)
//                     first = ind;
//                 if (i == size - 1)
//                     last = ind;
//                 if (nod->left)
//                     qu.push({nod->left, 2LL * ind + 1});
//                 if (nod->right)
//                     qu.push({nod->right, 2LL * ind + 2});
//             }
//             ans = max(ans, last - first + 1);
//         }
//         return ans;
//     }
// };