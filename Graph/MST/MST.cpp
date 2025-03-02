#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    class DisjointSet
    {
        vector<int> parent, rank, size;

    public:
        // Constructor
        DisjointSet(int n)
        {
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1, 1); // Initially, each node is its own set
            for (int i = 0; i <= n; i++)
            {
                parent[i] = i; // Each node is its own parent initially
            }
        }

        // Find function with path compression
        int find(int u)
        {
            if (u == parent[u])
                return u;
            return parent[u] = find(parent[u]); // Path compression
        }

        // Union by rank
        void unionByRank(int u, int v)
        {
            int rootU = find(u);
            int rootV = find(v);

            if (rootU != rootV)
            {
                if (rank[rootU] < rank[rootV])
                {
                    parent[rootU] = rootV;
                }
                else if (rank[rootU] > rank[rootV])
                {
                    parent[rootV] = rootU;
                }
                else
                {
                    parent[rootV] = rootU;
                    rank[rootU]++;
                }
            }
        }

        // Union by size
        void unionBySize(int u, int v)
        {
            int rootU = find(u);
            int rootV = find(v);

            if (rootU != rootV)
            {
                if (size[rootU] < size[rootV])
                {
                    parent[rootU] = rootV;
                    size[rootV] += size[rootU];
                }
                else
                {
                    parent[rootV] = rootU;
                    size[rootU] += size[rootV];
                }
            }
        }
    };
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 0; i < V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it[0];
                int wt = it[1];
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mst = 0;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.find(u) != ds.find(v))
            {
                mst += wt;
                ds.unionBySize(u, v);
            }
        }

        return mst;
    }
};

int main()
{
    int V = 5;
    vector<vector<int>> adj[V];
    adj[0].push_back({1, 2});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 3});
    adj[2].push_back({1, 3});
    adj[0].push_back({3, 6});
    adj[3].push_back({0, 6});
    adj[3].push_back({2, 3});
    adj[2].push_back({3, 3});
    adj[3].push_back({4, 1});
    adj[4].push_back({3, 1});
    adj[2].push_back({4, 3});
    adj[4].push_back({2, 3});
    Solution obj;
    cout << obj.spanningTree(V, adj) << endl;
    return 0;
}