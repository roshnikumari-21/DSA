// recursive_______________________________________________________________
//left right root



// class Solution
// {
// public:
//     vector<int> ans;

//     void post(TreeNode *root)
//     {
//         if (root == NULL)
//             return;


//         post(root->left);
//         post(root->right);
//         ans.push_back(root->val);
//     }
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         post(root);
//         return ans;
//     }
// };




// iterative using two stack_________________________

// class Solution
// {
// public:
//     vector<int> postorderTraversal(TreeNode *root)
//     {
//         vector<int> ans;
//         if (root == NULL)
//             return ans;
//         stack<TreeNode *> st1, st2;
//         st1.push(root);
//         while (!st1.empty())
//         {
//             root = st1.top();
//             st1.pop();
//             st2.push(root);
//             if (root->left != NULL)
//                 st1.push(root->left);
//             if (root->right != NULL)
//                 st1.push(root->right);
//         }

//         while (!st2.empty())
//         {
//             ans.push_back(st2.top()->val);
//             st2.pop();
//         }
//         return ans;
//     }
// };



// iterative using 1 stack_____________________________________________

//tc=O(2*n)


//left right root......


// class Solution {
//     public:
//         vector<int> postorderTraversal(TreeNode* root) {
//             vector<int> post;
//             if (root == NULL)
//                 return post;
    
//             stack<TreeNode*> st;
//             TreeNode* curr = root;
//             TreeNode* temp;
    
//             while (curr != NULL || !st.empty()) {
//                 if (curr != NULL) {
//                     st.push(curr);
//                     curr = curr->left;
//                 } else {
//                     temp = st.top()->right;
//                     if (temp == NULL) {
//                         temp = st.top();
//                         st.pop();
//                         post.push_back(temp->val);
//                         while (!st.empty() && temp == st.top()->right) {
//                             temp = st.top();
//                             st.pop();
//                             post.push_back(temp->val);
//                         }
//                     } else {
//                         curr = temp;
//                     }
//                 }
//             }
    
//             return post;
//         }
//     };


