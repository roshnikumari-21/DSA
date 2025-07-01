#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *reverse(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    ListNode *nw = reverse(head->next);
    ListNode *front = head->next;
    front->next = head;
    head->next = NULL;
    return nw;
}

ListNode* solve(ListNode *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    ListNode *even = head->next;
    ListNode *odd = head;
    ListNode *evhead = even;
    while (odd != NULL && odd->next != NULL && even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = NULL;   // critical

    evhead = reverse(evhead);

    ListNode *curr = head;
    ListNode *evenCurr = evhead;

    while (curr && evenCurr)
    {
        ListNode *currNext = curr->next;
        ListNode *evenNext = evenCurr->next;

        curr->next = evenCurr;
        evenCurr->next = currNext;

        curr = currNext;
        evenCurr = evenNext;
    }

    return head;
}
