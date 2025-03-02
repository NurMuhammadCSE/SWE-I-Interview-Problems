#include<bits/stdc++.h>
using namespace std;



// KAHN'S ALGORITHM
class Solution {
    public:
      // Function to return list containing vertices in Topological order.
      vector<int> topologicalSort(vector<vector<int>>& adj) {
          int n = adj.size();
          int indegree[n] = {0};
          
          for(int i=0; i<n; i++){
              for(auto it: adj[i]){
                  indegree[it]++;
              }
          }
          
          queue<int> q;
          for(int i=0; i<n; i++){
              if(indegree[i] == 0){
                  q.push(i);
              }
          }
          
          vector<int> ans;
          while(!q.empty()){
              int node = q.front();
              ans.push_back(node);
              q.pop();
              
              for(auto it:adj[node]){
                  indegree[it]--;
                  if(indegree[it] == 0){
                      q.push(it);
                  }
              }
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