#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited){
        visited[node] = true;
        for(auto it: adj[node]){
            if(!visited[it]){
                dfs(it, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>> &edges){
        vector<vector<int>> adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<bool> visited(n, false);
        int cnt = 0;
        for(int i=0; i<n;i++){
            if(!visited[i]){
                dfs(i, adj,visited);
                cnt++;
            }
        }
        return cnt;
    }
};

int main(){
    Solution obj;
    // vector<vector<int>> edges = {{0,1},{1,2},{3,4}};
    // cout<<obj.countComponents(5, edges);
    vector<vector<int>> edges = {{0,1},{1,2},{3,5},{6,}};
    cout<<obj.countComponents(8, edges);
    return 0;
}