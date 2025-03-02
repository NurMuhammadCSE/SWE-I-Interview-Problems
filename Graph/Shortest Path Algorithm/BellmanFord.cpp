#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
      vector<int> bellmanFord(int V, vector<vector<int>>& edges, 
      int src) {
          vector<int> dist(V, 1e8);
          dist[src] = 0;
          
          for(int i=0;i<V-1; i++){
              for(auto it : edges){
                  int u = it[0];
                  int v = it[1];
                  int wt = it[2];
                  
                  if(dist[u] != 1e8 and dist[u] + wt < dist[v]){
                      dist[v] = dist[u] + wt;
                  }
              }
          } 
          for(auto it:edges){
              int u = it[0];
              int v = it[1];
              int wt = it[2];
              if(dist[u] != 1e8 and dist[u] + wt < dist[v]){
                  return {-1};
              }
          }
          return dist;
      }
  };


  int main()
  {
      int n, m;
      cin >> n >> m;
      vector<vector<int>> edges;
      for (int i = 0; i < m; i++)
      {
          int u, v, wt;
          cin >> u >> v >> wt;
          edges.push_back({u, v, wt});
      }
      int src;
      cin >> src;
      Solution obj;
      vector<int> ans = obj.bellmanFord(n, edges, src);
      for (auto x : ans)
      {
          cout << x << " ";
      }
      return 0;
  }