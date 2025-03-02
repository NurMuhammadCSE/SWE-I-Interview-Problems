#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
// Function to find the shortest distance of all the vertices from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
        vector<int> dist(adj.size(), INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                if(wt + distance < dist[adjNode]){
                    dist[adjNode] = wt + distance;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        adj[u].push_back({v, wt});
    }
    int src;
    cin >> src;
    Solution obj;
    vector<int> ans = obj.dijkstra(adj, src);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    return 0;
}