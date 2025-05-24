#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main ()
{
    string t,p;
    cin>>t;
    cin>>p;
    int m = t.size();
    int n = p.size();
    vector<vector<bool>>dp(m+1,vector<bool>(n+1,false));
    dp[0][0] = true;
    if (p[0] == '*' || p[0] == '+') {
    cout << "False";
    return 0;
    }

for (int j=1; j<=n; j++)
{
    if (p[j-1] == '*')
    {
        dp[0][j] = dp[0][j-2];
    }
}
//cout<<"dp" <<dp[0][2]<<"\n";

    for (int i=1; i<=m; i++)
    {
        for (int j=1; j<=n; j++)
        {
            if (p[j-1] == '*')
            {
                dp[i][j] = dp[i][j-2] || ((t[i-1] == p[j-2] || p[j-2] == '.') && dp[i-1][j]);
            }
            else if (p[j-1] == '+')
            {
                dp[i][j] = dp[i][j-1] || (dp[i-1][j] && (t[i-1] == p[j-2] || p[j-2] == '.'));
            }
            else if (p[j-1] == '.' || p[j-1] == t[i-1])
            {
                
                dp[i][j] = dp[i-1][j-1];
            }
            // cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
        }
    }
    
    if (dp[m][n]) cout<<"True";
    else cout<<"False";

    return 0;
}