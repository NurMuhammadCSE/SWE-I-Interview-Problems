#include<bits/stdc++.h>
using namespace std;

vector<int> BFS(vector<vector<int>> adj){
    vector<int> vis(adj.size(), 0);
    vector<int> ans;
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push(adjNode);
            }
        }
    }
    return ans;
}


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    vector<int> ans = BFS(adj);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}