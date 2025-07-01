//Given a sorted doubly linked list of positive distinct elements, 
//the task is to find pairs in a doubly-linked list whose sum is equal to given value target.

//1 <-> 2 <-> 4 <-> 5 <-> 6 <-> 8 <-> 9
// target = 7
// Output: (1, 6), (2,5)


//brute___________tc=O(N^2)________________________________________________

//like double for loop  check for all pairs


// vector<pair<int, int>> findPairsWithSum(Node* head, int sum) {
//     Node* temp1 = head;
//     vector<pair<int, int>> ds;

//     while (temp1 != NULL) {
//         Node* temp2 = temp1->next;

//         while (temp2 != NULL && (temp1->val + temp2->val) <= sum) {
//             if (temp1->val + temp2->val == sum) {
//                 ds.push_back({temp1->val, temp2->val});
//             }
//             temp2 = temp2->next;
//         }

//         temp1 = temp1->next;
//     }

//     return ds;
// }



//optimal_________tc=O(N)____________sc=O(n)_>for storing pairs_______________________________________
//like two pointers

// Node* findTail(Node* head) {
//     Node* tail = head;
//     while (tail->next != NULL) {
//         tail = tail->next;
//     }
//     return tail;
// }


// vector<pair<int, int>> findPairs(Node* head, int k) {
//     vector<pair<int, int>> ans;
//     if (head == NULL) return ans;

//     Node* left = head;
//     Node* right = findTail(head);

//     while (left != NULL && right != NULL && left->data < right->data) {
//         int sum = left->data + right->data;

//         if (sum == k) {
//             ans.push_back({left->data, right->data});
//             left = left->next;
//             right = right->prev;
//         } else if (sum < k) {
//             left = left->next;
//         } else {
//             right = right->prev;
//         }
//     }

//     return ans;
// }