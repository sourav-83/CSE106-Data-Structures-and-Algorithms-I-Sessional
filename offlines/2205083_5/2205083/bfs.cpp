#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

void bfs (int x, vector<int>&visited, vector<vector<int>>&adj_matrix)
{
    queue<int>q;
    q.push(x);
    while (!q.empty())
    {
        int n = q.front();
        q.pop();
        visited[n]=1;
        for (int i=0; i<adj_matrix.size(); i++)
        {
            if (adj_matrix[n][i]==1 && !visited[i])
            {
                q.push(i);
            }
        }

    }
}
int main ()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>>adj_matrix(n,vector<int>(n,0));
    vector<int>visited(n,0);
    for (int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj_matrix[a-1][b-1]=1;
        adj_matrix[b-1][a-1]=1;

    }
    vector<pair<int, int>> tunnels;
    for (int i=0; i<n; i++)
    {
       if (!visited[i])
       {
        tunnels.push_back({1,i});
        bfs(i,visited,adj_matrix);
        
       }
    }
    cout<<tunnels.size()-1<<endl;
    for (int i=1; i<tunnels.size(); i++)
    {
        cout<<tunnels[i].first<<" "<<tunnels[i].second+1<<endl;
    }
    return 0;
}
