//tc=O(N)   sc=O(1)--->speciality of morris traversal
//concept of threaded binary tree


//"If no left, visit and go right. If left exists, build thread and go left.
// If thread exists, break it, visit, and go right."


// class Solution {
//     public:
//         vector<int> inorderTraversal(TreeNode* root) {
//             vector<int> ans;
    
//             if (root == NULL)
//                 return ans;     //early return

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
//                         cur = cur->left;
//                     } else {
//                         prev->right = NULL;      //destroying thread
//                         ans.push_back(cur->val);
//                         cur = cur->right;
//                     }
//                 }
//             }
//             return ans;
//         }
//     };