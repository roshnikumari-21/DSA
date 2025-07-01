// Given the head of a linked list, return the node where the cycle begins.
//  If there is no cycle, return null.



// class Solution {
//     public:
//         ListNode *detectCycle(ListNode *head) {
//             set<ListNode*>st;
//             ListNode* temp=head;
//             while(temp!=NULL){
//                 if(!st.empty() && st.find(temp)!=st.end()) return temp;
//                 st.insert(temp); 
//                 temp=temp->next;
//             }
//             ListNode *nw=new ListNode(-1);
//             return NULL;
//         }
//     };


//optimised___________________________________________________________________



// class Solution {
// public:
//     ListNode *detectCycle(ListNode *head) {
//         ListNode* slow = head;
//         ListNode* fast = head;

//         while (fast && fast->next) {
//             slow = slow->next;
//             fast = fast->next->next;

//             if (slow == fast) break;       //first collision
//         }

//         if (!fast || !fast->next) return nullptr;

//         fast = head;
//         while (fast != slow) {               //second collision
//             fast = fast->next;
//             slow = slow->next;
//         }

//         return slow;        
//     }
// };