// Input: root = [5,3,6,2,4,null,7], k = 9
//  Output: true

// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false

// brute force-> do inorder traversal ...and find sum using two pointers..using concept of bst iterator
// tc=O(2n)___________sc=O(n)

//it is best practise to code like this , using single class for both next and before functionality
//code quality matters for top companiess...write better code...



// class BSTIterator
// {
//     stack<TreeNode *> st;
//     bool rev = true;  //true for before, false for next

// public:
//     void pushAll(TreeNode *root)
//     {

//         while (root != NULL)
//         {
//             st.push(root);
//             if (rev)     //rev is true
//                 root = root->right;
//             else
//                 root = root->left;
//         }
//     }

//     BSTIterator(TreeNode *root, bool isrev)
//     {
//         rev = isrev;
//         pushAll(root);
//     }

//     int next()
//     {
//         TreeNode *nod = st.top();
//         int x = nod->val;
//         st.pop();
//         if (rev==false)
//             pushAll(nod->right);
//         else
//             pushAll(nod->left);
//         return x;
//     }
// };

// class Solution
// {
// public:
//     bool findTarget(TreeNode *root, int k)
//     {
//         if (root == NULL)
//             return false;
//         BSTIterator r(root, true);  // before
//         BSTIterator l(root, false); // after

//         int i = l.next();
//         int j = r.next();
//         while (i < j)
//         {
//             if (i + j == k)
//                 return true;
//             else if (i + j > k)
//                 j = r.next();
//             else
//                 i = l.next();
//         }
//         return false;
//     }
// };
