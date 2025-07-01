//anticlockwise---->first left , then leaf nodes, then right in stack 

//first put root node in ds


//tc=O(N)    sc=O(N)

// bool isLeaf(Node* root) {
//    if(root->left==NULL && root->right==NULL) return true;
//       else return false;
// }

// void addLeftBoundary(Node* root, vector<int> &res) {
//     Node* cur = root->left;
//     while (cur) {
//         if (!isLeaf(cur)) res.push_back(cur->data);
//         if (cur->left) cur = cur->left;
//         else cur = cur->right;
//     }
// }

// void addRightBoundary(Node* root, vector<int> &res) {
//     Node* cur = root->right;
//     vector<int> tmp;
//     while (cur) {
//         if (!isLeaf(cur)) tmp.push_back(cur->data);
//         if (cur->right) cur = cur->right;
//         else cur = cur->left;
//     }
//     for (int i = tmp.size() - 1; i >= 0; --i) {  //to get reversed nodes
//         res.push_back(tmp[i]);
//     }
// }

// void addLeaves(Node* root, vector<int> &res) {    //preorder kind of
//     if (isLeaf(root)) {
//         res.push_back(root->data);
//         return;
//     }
//     if (root->left) addLeaves(root->left, res);
//     if (root->right) addLeaves(root->right, res);
// }

// vector<int> printBoundary(Node *root) {
//     vector<int> res;                //our ds
//     if (!root) return res;
//     if (!isLeaf(root)) res.push_back(root->data);    //put root first

//     addLeftBoundary(root, res);
//     addLeaves(root, res);
//     addRightBoundary(root, res);

//     return res;
// }
