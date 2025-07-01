
// Given the head of a linked list, return the list after sorting it in ascending order.

// brute force--->tc=O(NlogN)   sc=O(N)

// class Solution {
//     public:
//         ListNode* sortList(ListNode* head) {
//             ListNode* temp=head;
//             vector<int>v;
//             while(temp!=NULL){
//               v.push_back(temp->val);
//               temp=temp->next;
//             }
//             sort(v.begin(),v.end());
//             temp=head;
//             int i=0;
//             while(temp!=NULL){
//                 temp->val=v[i];
//                 temp=temp->next;
//                 i++;
//             }
//             return head;
//         }
//     };



// optimal_____________________________________________________________________
// merge sort algorithm
// tc=O(Nlog(N+n/2))          sc=O(n)--->recursive (auxilliary stack space)

// class Solution {
//     public:
//     ListNode* findMiddle(ListNode *head) {     //n/2 for finding the middle
//         ListNode* slow = head;
//         ListNode* fast = head->next;
//         while(fast != NULL && fast->next != NULL) {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         return slow;
//     }


//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         ListNode* dummyNode = new ListNode(-1);
//         ListNode* temp = dummyNode;

//         while(list1 != NULL && list2 != NULL) {
//             if(list1->val < list2->val) {
//                 temp->next = list1;
//                 temp = list1;
//                 list1 = list1->next;
//             } else {
//                 temp->next = list2;
//                 temp = list2;
//                 list2 = list2->next;
//             }
//         }

//         if(list1) temp->next = list1;
//         else temp->next = list2;

//         return dummyNode->next;
//     }


//         ListNode* sortList(ListNode* head) {
//             if(head == NULL || head->next == NULL) return head;

//         ListNode* middle = findMiddle(head);
//         ListNode* right = middle->next;
//         middle->next = NULL;
//         ListNode* left = head;

//         left = sortList(left);
//         right = sortList(right);

//         return mergeTwoLists(left, right);
//         }
//     };