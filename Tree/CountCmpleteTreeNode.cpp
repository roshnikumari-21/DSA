//usually for cmplete b.t no of nodes=(2^h-1)

//tc=O(N)___________sc=O(h)

//This C++ code defines a solution to count the number of nodes in a binary tree.

// class Solution {
//     public:
//        int cnt(TreeNode* root){
//            if(root==NULL) return 0;
//            int le=  cnt(root->left);
//            int ri= cnt(root->right);
//            return 1+le+ri ;
//        }
//         int countNodes(TreeNode* root) {
//           if(root==NULL ) return 0;
//           return cnt(root);
            
//         }
//     };

//_________________________tc=O((logn)^2)_______


// class Solution {
// public:
//     int countNodes(TreeNode* root) {
//         if (root == NULL) return 0;

//         int lh = findHeightLeft(root);
//         int rh = findHeightRight(root);

//         if (lh == rh) 
//             return (1 << lh) - 1; // Perfect binary tree

//         return 1 + countNodes(root->left) + countNodes(root->right);
//     }

//     int findHeightLeft(TreeNode* node) {
//         int hght = 0;
//         while (node) {
//             hght++;
//             node = node->left;
//         }
//         return hght;
//     }

//     int findHeightRight(TreeNode* node) {
//         int hght = 0;
//         while (node) {
//             hght++;
//             node = node->right;
//         }
//         return hght;
//     }
// };

