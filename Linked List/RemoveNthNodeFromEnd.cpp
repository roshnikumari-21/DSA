//tc=O(len)
//sc=O(1)


// class Solution
// {
// public:
//     ListNode *removeNthFromEnd(ListNode *head, int n)
//     {
//         if (head == NULL)
//             return head;
//         ListNode *fast = head;
//         ListNode *slow = head;

//         while (n--)                  
//         {
//             fast = fast->next;
//         }

//         if (fast == NULL)   //means delete the first node
//             return head->next;

//         while (fast->next != NULL)         
//         {
//             slow = slow->next;    //slow will point to just delete ke pehle wala node
//             fast = fast->next;
//         }

//         slow->next = slow->next->next;    //modify the pointers
//         return head;
//     }
// };