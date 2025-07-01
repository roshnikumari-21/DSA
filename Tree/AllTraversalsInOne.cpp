// using of one stack....

// store (node,num)...
// tc=O(3n)   sc=O(4n)

// here we have to store preorder,inorder and postorder in one ans vector , and return it...
//_____________________________________________________________________________________________________

// vector<vector<int>> getTreeTraversal(TreeNode *root){
//     vector<vector<int>>ans;
//     vector<int>pre,ino,post;

//     if(root==NULL) return ans;    //early return

//     stack<pair<TreeNode*,int>>st;
//     st.push({root,1});
//     while(!st.empty()){
//         auto it=st.top();
//         st.pop();

//         //part of pre...first store in pre vector...increment num...push left node

//         if(it.second==1){
//             pre.push_back(it.first->data);
//             it.second++;
//             st.push(it);
//             if(it.first->left!=NULL){
//                 st.push({it.first->left,1});
//             }
//         }

//          //part of in...first store in IN vector...increment num...push right node

//         else if(it.second==2){
//             ino.push_back(it.first->data);
//             it.second++;
//             st.push(it);
//             if(it.first->right!=NULL){
//                 st.push({it.first->right,1});
//             }
//         }
//         //don't push it back again..

//         else if(it.second==3){
//             post.push_back(it.first->data);
//         }

//     }

//      ans.push_back(ino);
//         ans.push_back(pre);
//         ans.push_back(post);

//         return ans;

// }