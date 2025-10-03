#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    vector<int> heap;

    void heapifyUp(int index)
    { // parent se cmpare
        while (index != 0 && heap[parent(index)] > heap[index])
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index)
    { // bachoo se cmpare
        int leftChild = left(index);
        int rightChild = right(index);
        int smallest = index;

        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

    int parent(int i) { return (i - 1) / 2; } // 0 based indexing
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

public:
    // Insert a new element
    void insert(int key)
    {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Get the minimum element
    int getMin()
    {
        if (!heap.empty())
            return heap[0];
        return -1;
    }

    // Remove and return the minimum element
    int extractMin()
    {
        if (heap.empty())
            return -1;
            
        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);
        return root;
    }

    // Delete element at index i
    void deleteKey(int i)
    {
        if (i < 0 || i >= heap.size())
            return;
            
        decreaseKey(i, INT_MIN);
        extractMin();
    }

    // Decrease value at index i to new_val
    void decreaseKey(int i, int new_val)
    {
        heap[i] = new_val;
        heapifyUp(i);
    }

    // Display the heap
    void displayHeap()
    {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};