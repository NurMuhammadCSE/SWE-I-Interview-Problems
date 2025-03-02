#include<bits/stdc++.h>
using namespace std;

void DFS(int node, vector<vector<int>> adj, vector<int> vis, vector<int> ans){
    vis[node] = 1;
    ans.push_back(node);

    for(auto adjNode : adj[node]){
        if(!vis[adjNode]){
            DFS(adjNode, adj, vis, ans);
        }
    }
}

vector<int> traversal(vector<vector<int>> adj){
    vector<int> vis(adj.size(), 0);
    vector<int> ans;
    DFS(0, adj,vis, ans);
    return ans;
}


// https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
class Solution {
    public:
    
    void dfs(int node, vector<vector<int>> &adj, 
    vector<int> &vis, vector<int> &ans){
        vis[node] = 1;
        ans.push_back(node);
        
        for(auto adjNode : adj[node]){
            if(!vis[adjNode]){
                dfs(adjNode, adj, vis, ans);
            }
        }
    }
    
      // Function to return a list containing the DFS traversal of the graph.
      vector<int> dfsOfGraph(vector<vector<int>>& adj) {
          vector<int> vis(adj.size(), 0);
          vector<int> ans;
          dfs(0, adj, vis, ans);
          return ans;
      }
  };


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
    vector<int> ans = traversal(adj);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}