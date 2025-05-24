#include <iostream>
#include <vector>
#include <string>
#include <cstring>


using namespace std;

string x,y;
int n,m;
int dp[100][100];

int func(int i, int j)
{
   if (i>=n && j>=m) return 0;
   if (dp[i][j]!=-1) return dp[i][j];
   if (i>=0 && i<n && j>=0 && j<m && x[i]==y[j])
   {
      return dp[i][j] = func(i+1,j+1);
   }
   
   int candidate1 = INT_MAX;
   if (i<j) candidate1 = 1 + func(i,j+1);

   int candidate2 = INT_MAX;
   if (i>j) candidate2 = 1 + func(i+1,j);
   int candidate3 = 1 + func(i+1,j+1);
   dp[i][j] = min(candidate1,min(candidate2,candidate3));
   // cout<<i<<" "<<j<<" "<<dp[i][j]<<endl;
   return dp[i][j];
}

int main ()
{
    memset(dp,-1,sizeof(dp));
    
    cin>>x>>y;
    n = x.size();
    m = y.size();
    cout<<func(0,0)<<endl;

   // vector<vector<int>>dp(n+1,vector<int>(m+1),0);



    return 0;
}