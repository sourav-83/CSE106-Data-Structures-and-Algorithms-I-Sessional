#include <iostream>
#include "MaxHeap.h"

using namespace std;

int main ()
{
    MaxHeap q;
    int N,K;
    cin>>N>>K;
    if (N<0 || K<0) 
    {
        cout<<"Error: Invalid Input"<<endl;
        return -1;
    }
    for (int i=0; i<N; i++)
    {
        int x;
        cin>>x;
        q.insert(x);

    }
    int ans = 0;
    for (int i=0; i<K; i++)
    {
        int x = q.extractMax();
        q.insert(x/2);
        ans += x;
    }
    cout<<ans;

    return 0;
    
}