#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool dfs(int node, vector<int> &vis, vector<int> &pathVis,
             vector<vector<int>> &pre) {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto adjNode : pre[node]) {
            if (!vis[adjNode]) {
                if (dfs(adjNode, vis, pathVis, pre)) {
                    return true;
                }
            } else if (pathVis[adjNode]) {
                return true;
            }
        }
        pathVis[node] = 0;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);

        for (auto adjNode : prerequisites) {
            adj[adjNode[1]].push_back(adjNode[0]);
        }

        vector<int> vis(numCourses, 0);
        vector<int> pathVis(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (dfs(i, vis, pathVis, adj)) {
                    return false;
                }
            }
        }
        return true;
    }
};
/*
Time Complexity: O(V + E), where V is the number of vertices and E is the number of edges in the graph.
Space Complexity: O(V), for the visited array and the path visited array.
*/