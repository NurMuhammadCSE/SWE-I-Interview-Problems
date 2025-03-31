#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>>& adj) {
        int v = adj.size();
        vector<int> vis(v, 0);
        vector<int> ans;
        queue<int> q;

        q.push(0);
        vis[0] = 1;

        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);

            for (auto adjNode : adj[node]) {
                if (!vis[adjNode]) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
        return ans;
    }
};
/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), for the visited array and the queue used in BFS.
*/
