/*
https://leetcode.com/problems/lucky-numbers-in-a-matrix/description/?envType=daily-question&envId=2024-07-19
*/


// Solution # 01
class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> rowMin(m);
        vector<int> colMax(n);
        vector<int> res;

        for(int row=0; row<m; row++) {
            int minElem = INT_MAX;
            for(int col=0; col<n; col++) {
                if(matrix[row][col] < minElem)
                    minElem = matrix[row][col];
            }
            rowMin[row] = minElem;
        }

        for(int col=0; col<n; col++) {
            int maxElem = INT_MIN;
            for(int row=0; row<m; row++) {
                maxElem = max(maxElem, matrix[row][col]);
            }
            colMax[col] = maxElem;
        }

        for(int row=0; row<m; row++) {
            for(int col=0; col<n; col++) {
                if(matrix[row][col] == rowMin[row] && matrix[row][col] == colMax[col])
                    res.push_back(matrix[row][col]);
            }
        }

        return res;
    }
};
