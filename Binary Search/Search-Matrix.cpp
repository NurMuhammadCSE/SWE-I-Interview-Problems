#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        // 🔹 Traverse the entire matrix
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == target) return true;
            }
        }

        return false;
    }
};
    

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int row = 0, col = cols - 1;

        while (row < rows and col > -1) {
            int curr = matrix[row][col];
            if (curr == target) {
                return true;
            }
            if (target > curr) {
                row++;
            } else {
                col--;
            }
        }
        return false;
    }
};
    