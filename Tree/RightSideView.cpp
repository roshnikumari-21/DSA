//last node of every level will be included in answer

//we will use recursive solution here(short and crisp code)

//root right left  ----> reverse pre-order
//tc=O(N)           sc=O(H)


// class Solution {
//     public:
//         vector<int> ans;
//         void solve(TreeNode* root, int level) {
//             if (root == NULL)
//                 return;

//             if (level == ans.size())
//                 ans.push_back(root->val);
//             solve(root->right, level + 1);
//             solve(root->left, level + 1);
//         }
//         vector<int> rightSideView(TreeNode* root) {
//             solve(root, 0);
//             return ans;
//         }
//     };