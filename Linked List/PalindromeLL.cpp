// Given the head of a singly linked list, return true if it is a palindrome or false otherwise.
// create a stack and push all elements of ll, then again traverse from begin and match the elements


// class Solution {
//     public:
//         bool isPalindrome(ListNode* head) {
//             if(head==NULL) return true;
//             stack<int>st;
//             ListNode* temp=head;
//             while(temp!=NULL){
//                 st.push(temp->val);
//                 temp=temp->next;
//             }


//             temp=head;
//             while(!st.empty()){
//                 if(temp->val!=st.top()) return false;
//                 st.pop();
//                 temp=temp->next;
//             }
//             return true;
//         }
//     };



//tc=O(N)


// class Solution
// {
// public:
//     ListNode *reverse(ListNode *head)
//     {
//         if (head == NULL || head->next == NULL)
//             return head;
//         ListNode *nw = reverse(head->next);
//         ListNode *front = head->next;
//         front->next = head;
//         head->next = NULL;
//         return nw;
//     }

//     bool isPalindrome(ListNode *head)
//     {
//         ListNode *temp = head;
//         ListNode *fast = head->next;         //dhyan dena.....
//         ListNode *slow = head;
//         while (fast != NULL && fast->next != NULL)
//         {
//             slow = slow->next;
//             fast = fast->next->next;
//         }
//         ListNode *nwhd = slow->next;
//         slow->next = NULL;
//         nwhd = reverse(nwhd);
//         fast = head;
//         slow = nwhd;
//         while (fast != NULL && slow != NULL)
//         {
//             if (fast->val != slow->val)
//                 return false;
//             fast = fast->next;
//             slow = slow->next;
//         }
//         return true;
//     }
// };
