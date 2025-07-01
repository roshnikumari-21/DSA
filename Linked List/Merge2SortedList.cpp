//tc=O(m+n)
//sc=O(1)



// class Solution
// {
// public:
//     ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
//     {
//         ListNode *temp1 = list1;
//         ListNode *temp2 = list2;

//         ListNode *dumnod = new ListNode(-1);
//         ListNode *t = dumnod;
//         while (temp1 != NULL && temp2 != NULL)
//         {
//             if (temp1->val < temp2->val)
//             {
//                 t->next = temp1;
//                 temp1 = temp1->next;
//             }
//             else
//             {
//                 t->next = temp2;
//                 temp2 = temp2->next;
//             }
//             t = t->next;
//         }
//         if (temp1)
//             t->next = temp1;
//         else if (temp2)
//             t->next = temp2;
//         return dumnod->next;
//     }
// };