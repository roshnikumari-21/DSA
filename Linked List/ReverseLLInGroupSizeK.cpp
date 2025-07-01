//steps:
//figure out kth node
//store the nextNode
//reverse the current group
//either update the head or connect prevnode to currnode
//store the prevNode


//tc=O(2n)   sc=O(n)

// class Solution
// {
// public:
//     ListNode *reverse(ListNode *head)
//     {
//         if (head == NULL || head->next == NULL)
//             return head;
//         ListNode *nwnod = reverse(head->next);
//         ListNode *front = head->next;
//         front->next = head;
//         head->next = NULL;
//         return nwnod;
//     }

//     ListNode *findk(ListNode *temp, int k)
//     {
//         k--;
//         while (temp != NULL && k > 0)
//         {
//             temp = temp->next;
//             k--;
//         }
//         if (k > 0)
//             return NULL;  //grp size is less than k
//         return temp;
//     }

//     ListNode *reverseKGroup(ListNode *head, int k)
//     {
//         if (head == NULL || k == 1)
//             return head;
//         ListNode *temp = head;
//         ListNode *prevnod = NULL;
//         ListNode *nextnod = NULL;

//         while (temp != NULL)
//         {
//             ListNode *knod = findk(temp, k);
//             if (knod == NULL)
//             {
//                 if (prevnod)
//                     prevnod->next = temp;
//                 break;   
//             }

//             nextnod = knod->next;
//             knod->next = NULL;
//             knod = reverse(temp);
//             if (temp == head)
//                 head = knod;
//             else
//             {
//                 prevnod->next = knod;
//             }
//             prevnod = temp;
//             temp = nextnod;
//         }

//         return head;
//     }
// };