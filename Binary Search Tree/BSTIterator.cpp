// gives the order in inorder format when next() is called

// brute force--->store inorder in a vector, then just traverse through it to give next, next

// optimised---> do a kind of iterative inorder using stack
// tc=O(1)___________sc=O(h)



// class BSTIterator
// {

// public:
//     stack<TreeNode *> st;
//     void pushAll(TreeNode *root)
//     {
//         while (root != NULL)
//         {
//             st.push(root);
//             root = root->left;
//         }
//     }

//     BSTIterator(TreeNode *root)   //constructor
//     {
//         pushAll(root);
//     }

//     int next()
//     {
//         TreeNode *nod = st.top();
//         int x = nod->val;
//         st.pop();
//         pushAll(nod->right);
//         return x;
//     }

//     bool hasNext()
//     {
//         if (!st.empty())
//             return true;
//         else
//             return false;
//     }
// };

//we can get similary the before() function also, by doing right root left, so we can get descending order
//of nodes......thus push first right, then pop it then left...