//tc=O(N)...visiting each node once

// class Solution {
//     public:
//         vector<vector<int>> levelOrder(TreeNode* root) {
//              vector<vector<int>>ans;
//              if(root==NULL) return ans;
//              vector<int>temp;
//              queue<TreeNode*>qu;
//              qu.push(root);

//              while(!qu.empty()){
//                 int len=qu.size();
//                 for(int i=0; i<len; i++){
//                     TreeNode* cur=qu.front();
//                     temp.push_back(cur->val);
//                     qu.pop();
//                     if(cur->left) qu.push(cur->left);
//                     if(cur->right) qu.push(cur->right);
//                 }
//                 ans.push_back(temp);
//                 temp.clear();  
//              }
//              return ans;
//         }
//     };