
// #include <bits/stdc++.h>
// using namespace std;


//    https://www.interviewbit.com/problems/sum-root-to-leaf-numbers/
 
// int solve(TreeNode *root, int sum)
// {
//     if (root == NULL)
//         return 0;

//     sum = ((sum * 10) + (root->val)) % 1003;

//     if (root->left == NULL && root->right == NULL)
//     {

//         return sum;
//     }

//     int left = solve(root->left, sum);
//     int right = solve(root->right, sum);

//     return (left + right) % 1003;
// }

// int sumNumbers(TreeNode *root)
// {
//     return solve(root, 0);
// }
