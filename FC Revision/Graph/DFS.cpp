#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int>& ans,
                vector<vector<int>>& adj) {
        vis[node] = 1;
        ans.push_back(node);
        for (auto it : adj[node]) {
            if (!vis[it]) {
                dfs(it, vis, ans, adj);
            }
        }
    }
    vector<int> dfsOfGraph(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> vis(v, 0);
        vector<int> ans;
        dfs(0, vis, ans, adj);
        return ans;
    }
};
/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), for the visited array and the answer vector.
*/