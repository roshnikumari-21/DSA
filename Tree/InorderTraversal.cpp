// most basic recursive approach

// tc=O(N)
// sc=O(N)


//left   root   right

// class Solution {
//     public:
//         vector<int>ans;

//         void inorder(TreeNode* root){
//             if(root==NULL) return ;
//             inorder(root->left);
//             ans.push_back(root->val);
//               inorder(root->right);
//         }

//         vector<int> inorderTraversal(TreeNode* root) {
//             inorder(root);
//             return ans;
//         }
//     };

// iterative solution_______________________________________________________________________________________
//tc=O(n) sc=O(n)


// class Solution
// {
// public:
//     vector<int> inorderTraversal(TreeNode *root)
//     {
//         vector<int> ans;
//         stack<TreeNode *> st;

//         TreeNode *node = root;
//         while (1)
//         {

//             if (node != NULL)
//             {
//                 st.push(node);
//                 node = node->left;
//             }
//             else
//             {
//                 if (st.empty())
//                     break;

//                 node = st.top();
//                 st.pop();
//                 ans.push_back(node->val);
//                 node = node->right;
//             }
//         }
//         return ans;
//     }
// };


//morrris traversal__________________________________________________________________________________
//concept of threaded binary tree
//tc= O(n)   sc=O(1)

