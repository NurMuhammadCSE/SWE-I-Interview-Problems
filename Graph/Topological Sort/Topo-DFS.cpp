#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    void dfs(int node, vector<vector<int>> &adj,
             vector<int> &vis, stack<int> &st)
    {
        vis[node] = true;
        for (auto adjNode : adj[node])
        {
            if (!vis[adjNode])
            {
                dfs(adjNode, adj, vis, st);
            }
        }
        st.push(node);
    }

    // Function to return list containing vertices in Topological order.
    vector<int> topologicalSort(vector<vector<int>> &adj)
    {
        vector<int> vis(adj.size(), 0);
        stack<int> st;

        for (int i = 0; i < adj.size(); i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis, st);
            }
        }

        vector<int> ans;
        while (!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        return ans;
    }
};


int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }
    Solution obj;
    vector<int> ans = obj.topologicalSort(adj);
    for (auto x : ans)
    {
        cout << x << " ";
    }
    cout << endl;
    return 0;
}