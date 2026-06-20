// Given an integer array nums where the elements are sorted in ascending order,
// convert it to a height-balanced binary search tree.

// from  inorder traversal----sorted for bst

// as it process all nodes once, tc=O(N)
// recursive call stack= sc=O(logn)

//preorder= root, left, right

// class Solution
// {
// public:
//     TreeNode *solve(int left, int right, vector<int> &nums)
//     {
//         if (left > right)
//             return NULL;

//         int mid = (left + right) / 2;           // index hai
//         TreeNode *nw = new TreeNode(nums[mid]);
//         nw->left = solve(left, mid - 1, nums);
//         nw->right = solve(mid + 1, right, nums);

//         return nw;
//     }
//     TreeNode *sortedArrayToBST(vector<int> &nums)
//     {
//         int n = nums.size();
//         return solve(0, n - 1, nums);
//     }
// };

// from preorder traversal______________________________________________________________________



//brute approach--convert the array to sorted, then using both inorder and preorder u can generate a unique bst

// tc=O(N)
// sc=O(1)


//here bound is the upper bound

// class Solution
// {
// public:
//     TreeNode *build(vector<int> &pre, int &i, int &bound)
//     {
//         if (i == pre.size() || pre[i] > bound)
//             return NULL;

//         TreeNode *root = new TreeNode(pre[i++]);
//         root->left = build(pre, i, root->val);
//         root->right = build(pre, i, bound);
//         return root;
//     }

//     TreeNode *bstFromPreorder(vector<int> &pre)
//     {
//         
//         int bound = 10000;
//         int i = 0;
//         TreeNode *root = build(pre, i, bound);
//         return root;
//     }
// }
