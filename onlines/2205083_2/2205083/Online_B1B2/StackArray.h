#include <iostream>
using namespace std;

class Stack
{
private:
    int *array;
    //write your code here. Add additional private variables if necessary
    int size;
    int capacity;

public:
    // Constructor
    Stack()
    {
        array = new int[1]; 
        //write your code here. Initialize additional private variables if necessary
        size = 0;
        capacity = 1;
    }
    Stack(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
        size = 0;
        capacity = initialCapacity;
    }

    // Destructor
    ~Stack()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array
        
        //write your code here. Copy the elements from the old array to the new array
        for (int i=0; i<size; i++)
        {
            *(newArray+i)=*(array+i);
        }
        capacity = newCapacity;
        delete[] array; // Free old memory
        array = newArray;
        //write your code here. Update the capacity and array pointers
    }

    // Push an element onto the stack
    void push(int x)
    {
        //write your code here. Check if the array is full and resize if necessary.
        //push the element onto the stack
        if (size==capacity)
        {
            resize(size*2);
        }
        *(array+size)=x;
        size++;

    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       //pop the top element and return it
       //resize the array if necessary
       if (size==0) return -1;
       if ((size-1)*4<capacity)
       {
        resize(max(1,capacity/2));
       }
       int val = *(array+size-1);
       size--;
       return val;
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
        if (size==0) return -1;
        return *(array+size-1);
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return size;
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        if (size==0) return 1;
        else return 0;
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack. resize the array to 1
        size=0;
        resize(1);
        
    }
};
