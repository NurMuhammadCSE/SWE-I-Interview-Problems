#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& vis,
             vector<int>& pathVis, stack<int>& st) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjNode : adj[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, adj, vis, pathVis, st)) {
                    return true;
                }
            } else if (pathVis[adjNode]) {
                return true;
            }
        }
        pathVis[node] = 0;
        st.push(node);
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(n);
        for (auto adjNode : prerequisites) {
            adj[adjNode[1]].push_back(adjNode[0]);
        }

        vector<int> vis(n, 0), pathVis(n, 0);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis, st)) {
                    return {};
                }
            }
        }

        vector<int> ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};
/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), for the visited array, path visited array, and the stack used for topological sorting.
*/