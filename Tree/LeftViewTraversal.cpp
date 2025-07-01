//recursive code are shorter and cleaner than iterative ones....

//left View 
//first left then right....
//tc=O(n)__________sc=O(h)__________

//kind of preorder 

// class Solution {
//     public:
//     vector<int>ans;
//     void solve(Node* root,int level){
//         if(root==NULL) return;

//         if(ans.size()==level) ans.push_back(root->data);
//         solve(root->left,level+1);
//         solve(root->right,level+1);
//     }
//       vector<int> leftView(Node *root) {
//           solve(root,0);
//           return ans;
          
//       }
//   };


//Right side view of bt____________________________________________
//first right then left...


// class Solution {
//     public:
//     vector<int>ans;
//     void solve(Node* root,int level){
//         if(root==NULL) return;

//         if(ans.size()==level) ans.push_back(root->data);
//         solve(root->right,level+1);
//         solve(root->left,level+1);
//     }
//       vector<int> leftView(Node *root) {
//           solve(root,0);
//           return ans;
          
//       }
//   };