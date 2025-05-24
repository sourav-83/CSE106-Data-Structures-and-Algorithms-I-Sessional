# include <iostream>
#include "StackUsingQueue.h"

using namespace std;

int main ()
{
    int t;
    cout<<"Please enter number of test cases:"<<endl;
    cin>>t;
    while (t--)
    {
        int n;
        cout<<"Please enter number of elements:"<<endl;
        cin>>n;
        if (n<=0) {cout<<"Invalid number of elements!"<<endl; continue;}
        Stack s;
        Queue q;
        for (int i=0; i<n; i++)
        {
            char c;
            cin>>c;
            s.push(c-'a');
            q.enqueue(c-'a');
        }
        int temp = 0;
        for (int i=0; i<n; i++)
        {
            if (s.top()!= q.peek()) {temp=1; break;}
            q.dequeue();
            s.pop();
        }
        if (temp==0) cout<<"True"<<endl;
        else cout<<"False"<<endl;
    }
    return 0;
}
