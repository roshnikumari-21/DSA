//commented code bcoz it give errors

//Delete all the nodes having data equal to ‘k’.


#include <bits/stdc++.h>
using namespace std;



// Node *deleteAllOccurrences(Node *head, int k)
// {

//     Node *temp;
//     temp = head;

//     while (temp != NULL)
//     {
//         if (temp->data == k)
//         {
//             Node *prevnod = temp->prev;
//             Node *nextnod = temp->next;
//             if (prevnod)
//                 prevnod->next = nextnod;
//             if (nextnod)
//                 nextnod->prev = prevnod;
//             if (temp == head)  head = nextnod;   //updated head
//                
//             temp = nextnod;
//         }
//         else
//         {
//             temp = temp->next;
//         }
//     }

//     return head;
// }