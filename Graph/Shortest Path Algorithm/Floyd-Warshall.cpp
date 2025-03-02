#include<bits/stdc++.h>
using namespace std;

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

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<n; j++){
            cin >> mat[i][j];
        }
    }
    Solution obj;
    obj.shortestDistance(mat);
    for (int i = 0; i < n; i++)
    {
        for(int j=0; j<n; j++){
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}