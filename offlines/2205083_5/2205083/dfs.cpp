#include <iostream>
#include <vector>
#include <utility>

using namespace std;

void dfs (int i, vector<int>&visited, vector<vector<int>>&adj_list)
{
    visited[i]=1;
    for (int it: adj_list[i])
    {
       if (!visited[it])
       {

        dfs(it,visited,adj_list);
        
       }
    }
}
int main ()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj_list(n);
    vector<int>visited(n,0);
    for (int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj_list[a-1].push_back(b-1);
        adj_list[b-1].push_back(a-1);

    }
    vector<pair<int, int>> tunnels;
    for (int i=0; i<n; i++)
    {
       if (!visited[i])
       {
        tunnels.push_back({1,i});
        dfs(i,visited,adj_list);
        
       }
    }
    cout<<tunnels.size()-1<<endl;
    for (int i=1; i<tunnels.size(); i++)
    {
        cout<<tunnels[i].first<<" "<<tunnels[i].second+1<<endl;
    }
    return 0;
}
