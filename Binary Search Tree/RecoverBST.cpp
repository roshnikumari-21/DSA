// brute force
// any traversal-->then sort the values---->then compare each value--->and modify
// tc=O(2N+NlogN)          sc=O(N)

// optimal_________tc=O(N)_______________sc=O(1)________________________________
// swap can have two cases--->
// a inorder traversal--->left root right



// class Solution
// {
// private:
//     TreeNode *first;    //global
//     TreeNode *last;
//     TreeNode *mid;
//     TreeNode *prev;

// private:
//     void inorder(TreeNode *root)
//     {
//         if (root == NULL)
//             return;
//         inorder(root->left);
//         if ((prev->val) > (root->val))
//         {
//             if (first == NULL)   //mark first violation
//             {
//                 first = prev;
//                 mid = root;
//             }
//             else
//                 last = root;     //mark second violation
//         }
//         prev = root;
//         inorder(root->right);
//     }


// public:
//     void recoverTree(TreeNode *root)
//     {
//         first = NULL;
//         last = NULL;
//         mid = NULL;
//         prev = new TreeNode(INT_MIN);
//         
//         inorder(root);
//         if (first != NULL && last != NULL)
//             swap(first->val, last->val);
//         else
//             swap(first->val, mid->val);
//     }
// };