// Given the heads of two singly linked-lists headA and headB,
//  return the node at which the two lists intersect. If the two linked lists have no
//   intersection at all, return null.


//brute___________tc=O(nlog(N))_________________sc=O(N)_____________________________________
//using hashing  to store the nodes, traverse through one list first and store,
//then compare it with other list


//better_____________________tc=O(N1+N2)________________sc=O(1)____________
//figure out the length of both the lists---->n1, n2
//then using a function, align both lists, and start comparing, if reached on same node, return ans


//most optimal___________tc=O(N1+n2 )_____________________________________________

// class Solution
// {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
//     {
//         if (headA == NULL || headB == NULL)
//             return NULL;

//         ListNode *head1 = headA;
//         ListNode *head2 = headB;
//         while (headA != headB)
//         {

//             headA = headA->next;
//             headB = headB->next;
//             if (headA == headB)
//                 return headA;

//             if (headA == NULL)
//                 headA = head2;
//             if (headB == NULL)
//                 headB = head1;
//         }
//         return headA;
//     }
// };