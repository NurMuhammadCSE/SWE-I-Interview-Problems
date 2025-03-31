#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool dfs(int node, int parent, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, node, vis, adj)) {
                    return true;
                }
            } else if (adjNode != parent) {
                return true;
            }
        }
        return false;
    }
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> vis(v, 0);

        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                if (dfs(i, -1, vis, adj)) {
                    return true;
                }
            }
        }
        return false;
    }
};
/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), for the visited array.
*/