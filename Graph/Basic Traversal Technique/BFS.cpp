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