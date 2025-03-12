#include<bits/stdc++.h>
using namespace std;

//? BFS
vector<int> BFS(vector<vector<int>> adj){
    vector<int> vis(adj.size(), 0);
    vector<int> ans;
    queue<int> q;

    vis[0] = 1;
    q.push(0);

    while(!q.empty()){
        int node = q.front();
        ans.push_back(node);
        q.pop();

        for(auto adjNode:adj[node]){
            if(!vis[adjNode]){
                vis[adjNode] = 1;
                q.push(adjNode);
            }
        }
    }
    return ans;
}


//? DFS

void DFS(int node, vector<vector<int>> adj, vector<int> vis, vector<int> ans){
    vis[node] = 1;
    ans.push_back(node);

    for(auto adjNode : adj[node]){
        if(!vis[adjNode]){
            DFS(adjNode, adj, vis, ans);
        }
    }
}

vector<int> traversal(vector<vector<int>> adj){
    vector<int> vis(adj.size(), 0);
    vector<int> ans;
    DFS(0, adj,vis, ans);
    return ans;
}


//? Number of Provinces

class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<int>& vis) {
        vis[city] = 1;
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[city][i] == 1 and !vis[i]) {
                dfs(i, isConnected, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int provinces = 0;

        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                provinces++;
                dfs(i, isConnected, vis);
            }
        }
        return provinces;
    }
};


//? Number of Island
class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j) {
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0') 
            return;

        grid[i][j] = '0'; // Visited mark
        
        // 4-Direction DFS
        dfs(grid, i+1, j); // নিচে
        dfs(grid, i-1, j); // উপরে
        dfs(grid, i, j+1); // ডানে
        dfs(grid, i, j-1); // বামে
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    count++; // নতুন দ্বীপ পাওয়ায় Counter বাড়াও
                }
            }
        }
        return count;
    }
};
 
//? Clone Graph
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node(int _val) {
        val = _val;
    }
};

// Solution Class
class Solution {
public:
    unordered_map<Node*, Node*> cloneMap; // পুরাতন নোড -> নতুন নোড স্টোর করার জন্য

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr; // যদি গ্রাফ খালি থাকে

        // যদি নোড আগেই ক্লোন করা হয়ে থাকে, তাহলে সেটাই ফেরত দেই
        if (cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        }

        if (cloneMap.count(node)) {
            return cloneMap[node];
        }

        // নতুন নোড তৈরি করি
        Node* cloneNode = new Node(node->val);
        cloneMap[node] = cloneNode; // ম্যাপে রেখে দেই

        // সকল নোডের জন্য DFS কল করি এবং সংযুক্ত করি
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return cloneNode;
    }
};


//? Course Schedule

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

        vector<int> inDegree(n, 0);
        for (int i = 0; i < n; i++)
        {
            for (auto it : adj[i])
            {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++)
        {
            if (inDegree[i] == 0)
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
                inDegree[it]--;
                if (inDegree[it] == 0)
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

//? Topological Sort

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


//? Topological Kahn's
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


//? Dijkstra Algorithm
class Solution {
public:
// Function to find the shortest distance of all the vertices from the source vertex src.
    vector<int> dijkstra(vector<vector<pair<int, int>>> &adj, int src) {
        priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
        vector<int> dist(adj.size(), INT_MAX);
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjNode = it.first;
                int wt = it.second;
                
                if(wt + distance < dist[adjNode]){
                    dist[adjNode] = wt + distance;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }
        return dist;
    }
};


//? Bellman Form Algorithm
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


//? Floyd Warshall Algorithm
class Solution {
public:
    void shortestDistance(vector<vector<int>>& mat) {
        int n = mat.size();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == -1){
                    mat[i][j] = 1e9;
                }
                if(i == j) mat[i][j] = 0;
            }
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j = 0; j<n; j++){
                    mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(mat[i][j] == 1e9){
                    mat[i][j] = -1;
                }
            }
        }
    }
};


