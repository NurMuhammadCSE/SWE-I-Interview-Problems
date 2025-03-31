#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (int i = 0; i < adj.size(); i++) {
            if (!vis[i] and adj[node][i] == 1) {
                dfs(i, vis, adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int v = isConnected.size();
        int provinces = 0;
        vector<int> vis(v, 0);
        
        for (int i = 0; i < v; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, vis, isConnected);
            }
        }
        return provinces;
    }
};
/*
Time Complexity: O(V^2), where V is the number of vertices in the graph.
Space Complexity: O(V), for the visited array.
*/
    