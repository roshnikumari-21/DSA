#include <bits/stdc++.h>
using namespace std;





// int findlen(Node *slow, Node *fast)
// {
//     int cnt = 1;
//     fast = fast->next;
//     while (slow != fast)
//     {
//         fast = fast->next;
//         cnt++;
//     }
//     return cnt;
// }


// int lengthOfLoop(Node *head)
// {
//     Node *fast = head;
//     Node *slow = head;

//     while (fast != NULL && fast->next != NULL)
//     {

//         fast = fast->next->next;
//         slow = slow->next;
//         if (fast == slow)
//             return findlen(slow, fast);   //loop is present
//     }
//     return 0;
// }
