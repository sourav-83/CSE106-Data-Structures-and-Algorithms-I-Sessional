#include <iostream>
#include <vector>


using namespace std;

int counts = 0;
int n,m;
vector<int>x={1,-1,0,0};
vector<int>y={0,0,1,-1};

void dfs (int r, int c, vector<vector<char>>&grid, vector<vector<int>>&visited)
{
   if (grid[r][c]=='E') counts++;
   for (int i=0; i<4; i++)
   {
    int newr = r+x[i];
    int newc = c+y[i];
    if (newr>=0 && newr<n && newc>=0 && newc<m && visited[newr][newc]==0)
    {
        if (grid[newr][newc]=='E' || grid[newr][newc]=='.')
        {
            visited[newr][newc]=1;
            dfs(newr,newc,grid,visited);
        }
    }
   }


}
int main ()
{
    
    cin>>n>>m;
    vector<vector<char>>grid(n,vector<char>(m));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            char c;
            cin>>c;
            grid[i][j]=c;
        }
    }
    vector<vector<int>>visited(n,vector<int>(m,0));
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            if (grid[i][j]=='S') {visited[i][j]=1; dfs(i,j,grid,visited);}
        }
    }
    cout<<counts<<endl;

    return 0;

}