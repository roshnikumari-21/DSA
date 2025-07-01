//bfs traversal   
//  maintain a visited array too
//since we cant move upward, we have to maintain a parent pointer too
//radial outward direction movement




// class Solution {
//     public:
//         void markp(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
//             queue<TreeNode*> qu;
//             qu.push(root);
//             while (!qu.empty()) {
//                 TreeNode* nod = qu.front();
//                 qu.pop();
    
//                 if (nod->left) {
//                     qu.push(nod->left);
//                     mp[nod->left] = nod;
//                 }
    
//                 if (nod->right) {
//                     qu.push(nod->right);
//                     mp[nod->right] = nod;
//                 }
//             }
//         }
    


//         vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) {
//             unordered_map<TreeNode*, TreeNode*> mp;  //to store parent pointers
//             markp(root, mp);
    
//             unordered_map<TreeNode*, bool> vis;
//             queue<TreeNode*> qu;
//             int cur = 0;
//             qu.push(tar);
//             vis[tar] = 1;
//             while (!qu.empty()) {
//                 int size = qu.size();
//                 if (cur == k)
//                     break;
//                 cur++;


//                 for (int i = 0; i < size; i++) {
//                     TreeNode* nod = qu.front();
//                     qu.pop();
//                     if (nod->left && vis[nod->left] == 0) {
//                         qu.push(nod->left);
//                         vis[nod->left] = 1;
//                     }
    
//                     if (nod->right && vis[nod->right] == 0) {
//                         qu.push(nod->right);
//                         vis[nod->right] = 1;
//                     }
    
//                     if (mp[nod] && vis[mp[nod]] == 0) {
//                         qu.push(mp[nod]);
//                         vis[mp[nod]] = 1;
//                     }
//                 }
//             }
    

//             vector<int> ans;
//             while (!qu.empty()) {
//                 int val = qu.front()->val;
//                 ans.push_back(val);
//                 qu.pop();
//             }
//             return ans;
//         }
//     };