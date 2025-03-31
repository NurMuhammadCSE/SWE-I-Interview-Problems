#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, 
    int src) {
        int v = adj.size();
        vector<int> dist(v, -1);
        queue<int> q;
        
        dist[src] = 0;
        q.push(src);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for (int adjNode : adj[node]) {
                if (dist[adjNode] == -1) { // If not visited
                    dist[adjNode] = dist[node] + 1;
                    q.push(adjNode);
                }
            }
        }
        return dist;
    }
};
/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), for the distance array and the queue used in BFS.
*/