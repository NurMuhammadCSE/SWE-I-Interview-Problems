#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    // Function to find the shortest distance of all the vertices
    // from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, 
    int src) {
        int v = adj.size();
        vector<int> dist(v, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, 
        greater<pair<int, int>>> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int edgeW = it.second;
                
                if(edgeW + dis < dist[adjNode]){
                    dist[adjNode] = edgeW + dis;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};
/*
Time Complexity: O((V + E) * log(V)), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), for the distance array and the priority queue used in Dijkstra's algorithm.
*/