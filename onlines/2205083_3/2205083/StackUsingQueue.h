#include <iostream>
#include "QueueLinkedList.h"
using namespace std;

class Stack
{
private:
    
    //write your code here. Add additional private variables if necessary
    Queue q;
    

public:
    // Constructor
    Stack()
    {
        //write your code here. Initialize additional private variables if necessary
    }
    Stack(int initialCapacity)
    {
        //write your code here. Initialize additional private variables if necessary
    }

    // Destructor
    ~Stack()
    {
    }

    
    // Push an element onto the stack
    void push(int x)
    {
        //write your code here.
        //push the element onto the stack
        q.enqueue(x);
        for (int i=0; i<q.length()-1; i++)
        {
            q.enqueue(q.dequeue());
        }
    }

    // Remove and return the top element
    int pop()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       //pop the top element and return it
       if (q.isEmpty()) return -1;
       return q.dequeue();
    }

    // Return the top element without removing it
    int top()
    {
        //write your code here. Check if the stack is empty and return -1 if it is.
        //return the top element
       return q.peek();
       
       
    }

    // Return the number of elements in the stack
    int length()
    {
        //write your code here. Return the number of elements in the stack
        return q.length();
    }

    // Check if the stack is empty
    bool isEmpty()
    {
        //write your code here. Return true if the stack is empty, false otherwise
        return q.isEmpty();
    }

    // Clear the stack
    void clear()
    {
        //write your code here. Clear the stack.
        q.clear();
    }
};
