#include <iostream>
#include <vector>

using namespace std;

// int call = 0;

int f(vector<int> &arr, int start, int end)
{   
    // call++;
    if (start == end)
        return 1;
    int mid = (start + end) / 2;
    int l = f(arr, start, mid);
    int r = f(arr, mid + 1, end);
    if (arr[mid] == arr[mid + 1])
    { // cout<<start<<" "<<end<<" "<<l+r-1<<endl;
        return l + r - 1;
    }
    // cout << start << " " << end << " " << l + r << endl;
    return l + r;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << f(arr, 0, n - 1);
    // cout<<endl<<"call: "<<call;
    return 0;
}