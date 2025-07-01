// u have to sort them all vertically

// brute_________________________
// store all nodes in vector, sort them and then convert into vertical linked list
// tc=O(N*M)+ xlogx where x=N*M
// sc=O(2*(N*M))

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node *next;
    Node *child;

    Node(int value) : val(value), next(nullptr), child(nullptr) {}
};

void flattenToArray(Node *head, std::vector<int> &arr)
{
    Node *temp = head;

    while (temp != nullptr)
    {
        Node *t2 = temp; // Pointer to traverse the child nodes

        while (t2 != nullptr)
        {
            arr.push_back(t2->val); // Add the value of the current node to the array
            t2 = t2->child;         // Move to the child
        }
        temp = temp->next; // Move to the next node
    }
}

// Function to convert an array to a flattened linked list
Node *convertArrayToLinkedList(const std::vector<int> &arr)
{
    if (arr.empty())
        return nullptr; // Return if the array is empty

    Node *head = new Node(arr[0]); // Create the head of the new list
    Node *temp = head;

    // Create the linked list from the array
    for (size_t i = 1; i < arr.size(); ++i)
    {
        Node *newNode = new Node(arr[i]);
        temp->child = newNode; // Set the child of the previous node
        temp = temp->child;    // Move to the new node
    }

    return head; // Return the head of the newly created linked list
}

// optimal_______________________________________

// solve using merging two ll but in vertical order
// using recursion to merge all the lists


//tc=O(2*N*M)_____sc=O(N)------>recurssive

Node *merge(Node *list1, Node *list2)   //O(N+M)
{
    Node *dummyNode = new Node(-1); // Dummy node to simplify merging
    Node *current = dummyNode;      // Pointer to the current node in the merged list

    while (list1 != nullptr && list2 != nullptr)
    {
        if (list1->val < list2->val)
        {
            current->child = list1; // Link to the smaller node
            list1 = list1->child;   // Move to the next node in list1
        }
        else
        {
            current->child = list2; // Link to the smaller node
            list2 = list2->child;   // Move to the next node in list2
        }
        current = current->child; // Move to the new end of the merged list
    }

    // If there are remaining nodes in either list, attach it
    if (list1 != nullptr)
    {
        current->child = list1;
    }
    else
    {
        current->child = list2;
    }

    Node *mergedHead = dummyNode->child; // Get the head of the merged list
    delete dummyNode;                   // Clean up the dummy node
    return mergedHead;                  // Return the head of the merged list
}

Node *flatten(Node *head)     
{
    if (head==NULL || (head->next==NULL && head->child==NULL))   return head;
    

    // Recursively flatten the next level
    Node *mergedHead = flatten(head->next);

    // Merge the current level with the flattened next level
    return merge(head, mergedHead);
}