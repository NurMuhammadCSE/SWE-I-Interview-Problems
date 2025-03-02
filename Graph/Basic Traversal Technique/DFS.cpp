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