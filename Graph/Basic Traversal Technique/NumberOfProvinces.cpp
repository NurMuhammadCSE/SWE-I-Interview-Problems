#include<bits/stdc++.h>
using namespace std;

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

int main(){
    vector<vector<int>> isConnected = {{1,1,0},{1,1,0},{0,0,1}};
    Solution obj;
    cout<<obj.findCircleNum(isConnected)<<endl;
    return 0;
}