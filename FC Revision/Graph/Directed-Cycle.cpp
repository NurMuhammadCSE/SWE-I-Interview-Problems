#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool dfs(int node, int parent, vector<int>& vis, vector<int>& pathVis,
        vector<vector<int>>& adj) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, node, vis, pathVis, adj)) {
                    return true;
                }
            } else if (pathVis[adjNode]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> vis(v, 0);
        vector<int> pathVis(v, 0);

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, pathVis, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};
/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), for the visited array and the path visited array.
*/