#include <bits/stdc++.h>
using namespace std;


#include <bits/stdc++.h>
using namespace std;

class MaxHeap
{
    vector<int> heap;

    void heapifyUp(int index)
    { // Compare with parent
        while (index != 0 && heap[parent(index)] < heap[index])
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index)
    { // Compare with children
        int leftChild = left(index);
        int rightChild = right(index);
        int largest = index;

        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

    int parent(int i) { return (i - 1) / 2; } // 0-based indexing
    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }

public:
    // Insert a new element
    void insert(int key)
    {
        heap.push_back(key);
        heapifyUp(heap.size() - 1);
    }

    // Get the maximum element
    int getMax()
    {
        if (!heap.empty())
            return heap[0];
        return -1;
    }

    // Remove and return the maximum element
    int extractMax()
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
        increaseKey(i, INT_MAX);
        extractMax();
    }

    // Increase value at index i to new_val
    void increaseKey(int i, int new_val)
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
