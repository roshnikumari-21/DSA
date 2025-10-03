

//brute____________tc=O(N^2)______________________________________________________________
//using validate bst at every node


//optimal_________________tc=O(N)______________________sc=O(1)__________________________
//using postorder traversal


// class Nodeval
// {
// public:
//     int mini, maxi, size;
//     Nodeval(int mini, int maxi, int size)   //constructor...
//     {
//         this->mini = mini;   //minimum value in subtree
//         this->maxi = maxi;    //maximum value in subtree
//         this->size = size;
//     }
// };

// class Solution
// {
// public:
//     Nodeval help(Node *root)
//     {
//         if (root == NULL)
//             return Nodeval(INT_MAX, INT_MIN, 0);
//         auto left = help(root->left);
//         auto right = help(root->right);
//         if (left.maxi < root->data && root->data < right.mini)
//         {
//             return Nodeval(min(left.mini, root->data), max(right.maxi, root->data), left.size + right.size + 1);
//         }
//         return Nodeval(INT_MIN, INT_MAX, max(left.size, right.size));  //not a valid bst
//     }

//     int largestBst(Node *root)
//     {
//         return help(root).size;
//     }
// };
