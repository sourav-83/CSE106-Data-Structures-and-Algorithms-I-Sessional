#ifndef MAXHEAP_H
#define MAXHEAP_H

#include <iostream>
#include <fstream>
#include <stdexcept>


#define MAX_CAPACITY 100 // Defines the maximum capacity of the heap

class MaxHeap
{
private:
    int heap[MAX_CAPACITY]; // Array to store heap elements
    int size;               // Current number of elements in the heap

    // Sifts up the node at index i to maintain heap property
    void siftUp(int index)
    {
        /**Write your code here**/
        while (index)
        {
           int parent = (index-1)/2;
           if (heap[index]>heap[parent])
           {
            int temp = heap[index];
            heap[index] = heap[parent];
            heap[parent] = temp;
            index = parent;
           }
           else break;
        }
    }

    // Sifts down the node at index i to maintain heap property
    void siftDown(int index)
    {
        /**Write your code here**/
        int toswap = index;
        int leftchild = index * 2 + 1;
        int rightchild = index * 2 + 2;
        if (leftchild < size && heap[leftchild] > heap[toswap])
            toswap = leftchild;
        if (rightchild < size && heap[rightchild] > heap[toswap])
            toswap = rightchild;
        if (toswap != index)
        {
            int temp = heap[index];
            heap[index] = heap[toswap];
            heap[toswap] = temp;
            siftDown(toswap);
        }
    }

  

public:
    // Constructor initializes an empty heap
    MaxHeap() : size(0) {}

    // Inserts a new element x into the heap
    void insert(int x)
    {
        if (size == MAX_CAPACITY)
        {
            throw std::length_error("insert() called, but the heap is full.");
        }

        /**Write your code here**/
        heap[size++] = x;
        siftUp(size-1);
    }

    // Returns the maximum element without removing it
    int findMax()
    {
        if (size == 0)
        {
            throw std::runtime_error("findMax() called, but the heap is empty.");
        }

        /**Write your code here**/
        return heap[0];
    }

    // Removes and returns the maximum element from the heap
    int extractMax()
    {
        if (size == 0)
        {
            throw std::runtime_error("extractMax() called, but the heap is empty.");
        }

        /**Write your code here**/
        int ans = heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size)
        {
            siftDown(0);
        }
        return ans;
    }

    // Returns the number of elements in the heap
    int getSize()
    {
        /**Write your code here**/
        return size;
    }

    // Checks if the heap is empty. Returns true if the heap is empty, false otherwise.
    bool isEmpty()
    {
        /**Write your code here**/
        return size==0;
    }

    // Increases the value of the element at index i to new_value
    void increaseKey(int i, int newValue)
    {
        if (i < 0 || i >= size || heap[i] >= newValue)
        {
            throw std::invalid_argument("increaseKey() called with invalid index or invalid new value.");
        }
        
        heap[i]=newValue;
        siftUp(i);

        /**Write your code here**/
    }

    // Deletes the element at index i
    void deleteKey(int i)
    {
        /**Write your code here**/
        if (i<0 || i>size) throw std::invalid_argument("deleteKey() called with invalid index or invalid new value.");

        
        heap[i] = heap[size - 1];
        size--;
        if (size)
        {
            siftDown(i);
        }

    }

    // Prints the heap's content to the output file
    void printHeap(std::ofstream &outfile)
    {
        /**Write your code here**/
        for (int i=0; i<size; i++) outfile<<heap[i]<<" ";
        outfile<<std::endl;

    }

    // Checkes whether the Max Heap property is preserved or not. Returns true if the Max Heap property is valid and returns false otherwise.
    bool isValidMaxHeap()
    {
        /**Write your code here**/
        for (int i=0; i<(size-1)/2; i++)
        {
           int leftchild = i*2+1;
           int rightchild = i*2+2;
           if (leftchild<size && heap[i]<heap[leftchild]) return false;
           if (rightchild<size && heap[i]<heap[rightchild]) return false;
        }
        return true;
    }
};

#endif // MAXHEAP_H
