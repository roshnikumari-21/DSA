#include <bits/stdc++.h>
using namespace std;



// ListNode swapPairs(ListNode *a)
// {
//     if (a == NULL || a->next == NULL)
//         return a;
//     ListNode *head;
//     ListNode *fir = a;
//     ListNode *sec = a->next;
//     ListNode *prev = NULL;
//     while (fir != NULL && sec != NULL)
//     {
//         ListNode *thi = sec->next;
//         sec->next = fir;
//         fir->next = thi;
//         if (prev != NULL)
//             prev->next = sec;
//         else
//             head = sec;
//         prev = fir;
//         fir = thi;
//         if (thi != NULL)
//             sec = thi->next;
//     }
//     return head;
// }