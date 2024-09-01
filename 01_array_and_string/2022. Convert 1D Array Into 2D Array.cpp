/*
https://leetcode.com/problems/convert-1d-array-into-2d-array/description/
*/

// Approach # 01
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res(m, vector<int>(n));

        if(original.size() != m*n)
            return {};

        int idx = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                res[i][j] = original[idx];
                idx++;
            }
        }

        return res;
    }
};

// Approach # 02
class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> res(m, vector<int>(n));

        if(original.size() != m*n)
            return {};

        for(int i=0; i<original.size(); i++) {
            int row = i/n;
            int col = i%n;
            res[row][col] = original[i];
        }

        return res;
    }
};
