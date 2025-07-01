
//if inorder done, just 1 lines of code changes



// class Solution {
//     public:
//         vector<int> inorderTraversal(TreeNode* root) {
//             vector<int> ans;
    
//             if (root == NULL)
//                 return ans;          //early return;

//             TreeNode* cur = root;
//             while (cur != NULL) {
//                 if (cur->left == NULL) {
//                     ans.push_back(cur->val);   //1st case
//                     cur = cur->right;
//                 }
    
//                 else {
//                     TreeNode* prev = cur->left;
//                     while (prev->right && prev->right != cur) {
//                         prev = prev->right;
//                     }
    
//                     if (prev->right == NULL) {
//                         prev->right = cur;     //creating thread
//                          ans.push_back(cur->val);   //yhi pr change hai...
//                         cur = cur->left;
//                     } else {
//                         prev->right = NULL;      //destroying thread
//                        
//                         cur = cur->right;
//                     }
//                 }
//             }
//             return ans;
//         }
//     };