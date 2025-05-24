#include <iostream>
using namespace std;


                                                   

class Queue
{
private:
    int *array;
    //write your code here. Add additional private variables if necessary
    int start;
    int last;
    int capacity;
public:
    // Constructor
    Queue()
    {
        array = new int[1];
        //write your code here. Initialize additional private variables if necessary
        last=0;
        capacity=1;
        start=0;
    }
    Queue(int initialCapacity)
    {
        array = new int[initialCapacity]; // Allocate initial memory
        //write your code here. Initialize additional private variables if necessary
        last=0;
        capacity=initialCapacity;
    }

    // Destructor
    ~Queue()
    {
        delete[] array; // Free dynamically allocated memory
    }

    // Helper function to resize the array when full
    void resize(int newCapacity)
    {
        int *newArray = new int[newCapacity]; // Allocate new array

        //write your code here. Copy the elements from the old array to the new array
        int j=0;
        int total = last-start;
        for (int i=start; i<last; i++) {newArray[j]=array[i]; j++;}
        delete[] array; // Free old memory
        array=newArray;
        capacity=newCapacity;
        start=0;
        last=total;
        //write your code here. Update the capacity and array pointers
    }

    // Enqueue an element onto the queue
    void enqueue(int x)
    {
        //write your code here. Check if the array is full and resize if necessary.
        if (last==capacity) resize(capacity*2);
        array[last]=x;
        last++;
    }

    // Remove and return the peek element
    int dequeue()
    {
       //write your code here. Check if the stack is empty and return -1 if it is.
       //remove the peek element and return it
       //resize the array if necessary
       if (last==start) return -1;

       int val = array[start];
       
       start++;
       if (capacity>1 && ((last-1)*4)<capacity) resize(capacity/2);
       
       return val;
    }

    // Return the peek element without removing it
    int peek()
    {
        //write your code here. Check if the queue is empty and return -1 if it is.
        //return the peek element
        if (start==last) return -1;
        else return array[start];
    }

    // Return the number of elements in the queue
    int length()
    {
        //write your code here. Return the number of elements in the queue
        return last-start;
    }

    // Check if the queue is empty
    bool isEmpty()
    {
        //write your code here. Return true if the queue is empty, false otherwise
        if (start==last) return true;
        return false;
    }

    // Clear the queue
    void clear()
    {
        //write your code here. Clear the queue. resize the array to 1
        resize(1);
        start=0;
        last=0;
    }
};
