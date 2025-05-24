#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

tuple<int, int, int> f(vector<int> &arr, int left, int right)
{
   if (left == right)
      return {arr[left], left, right};
   int mid = (left + right) / 2;
   tuple<int, int, int> l = f(arr, left, mid);
   int left_max = get<0>(l);
   int left_start = get<1>(l);
   int left_end = get<2>(l);
   tuple<int, int, int> r = f(arr, mid + 1, right);
   int right_max = get<0>(r);
   int right_start = get<1>(r);
   int right_end = get<2>(r);
   int temp_l = arr[mid];
   int temp_r = arr[mid + 1];
   int current_l = arr[mid];
   int current_r = arr[mid + 1];
   int cross_start = mid;
   int cross_end = mid + 1;
   for (int i = mid - 1; i >= left; i--)
   {
      current_l += arr[i];
      if (current_l > temp_l)
      {
         temp_l = current_l;
         cross_start = i;
      }
   }
   for (int i = mid + 2; i <= right; i++)
   {
      current_r += arr[i];
      if (current_r > temp_r)
      {
         temp_r = current_r;
         cross_end = i;
      }
   }
   int cross_sum = temp_l + temp_r;
   int left_length = left_end - left_start + 1;
   int right_length = right_end - right_start + 1;
   int cross_length = cross_end - cross_start + 1;
   if (cross_sum > left_max && cross_sum > right_max)  return {cross_sum, cross_start, cross_end};
   else if (left_max > cross_sum && left_max > right_max) return {left_max, left_start, left_end};
   else if (right_max > cross_sum && right_max > left_max) return {right_max, right_start, right_end};
   else if (cross_sum >= left_max && cross_sum >= right_max && (!(left_max==cross_sum && left_length<cross_length)) && (!(right_max==cross_sum && right_length<cross_length))) return {cross_sum, cross_start, cross_end};
   else if (left_max >= cross_sum && left_max >= right_max && (!(cross_sum==left_max && cross_length<left_length)) && (!(right_max==left_max && right_length<left_length))) return {left_max, left_start, left_end};
   else return {right_max, right_start, right_end};



}
int main()
{
   int n;
   cin >> n;
   vector<int> arr(n);
   for (int i = 0; i < n; i++)
      cin >> arr[i];
   tuple<int, int, int> ans = f(arr, 0, n - 1);
   cout << "[" << get<1>(ans) << ", " << get<2>(ans)<<"]" << " with a sum of " << get<0>(ans);

   return 0;
}