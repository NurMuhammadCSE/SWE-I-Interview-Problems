#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>> &prerequisites)
    {
        vector<vector<int>> adj(n);
        for (auto it : prerequisites)
        {
            adj[it[1]].push_back(it[0]);
        }

        vector<int> indegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();

            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                {
                    q.push(it);
                }
            }
        }

        if (ans.size() == n)
        {
            return true;
        }

        return false;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> prerequisites(m, vector<int>(2));
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        prerequisites[i][0] = u;
        prerequisites[i][1] = v;
    }
    Solution obj;
    cout << obj.canFinish(n, prerequisites);
}