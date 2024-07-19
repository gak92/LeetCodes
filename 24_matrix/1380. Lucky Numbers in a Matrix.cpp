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



// ============= Solution # 02 ==============

/*

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int rowMinMax = INT_MIN;
        for(int row=0; row<m; row++) {
            int rowMin = INT_MAX;
            for(int col=0; col<n; col++) {
                rowMin = min(rowMin, matrix[row][col]);
            }
            rowMinMax = max(rowMinMax, rowMin);
        }

        int colMaxMin = INT_MAX;
        for(int col=0; col<n; col++) {
            int colMax = INT_MIN;
            for(int row=0; row<m; row++) {
                colMax = max(colMax, matrix[row][col]);
            }
            colMaxMin = min(colMaxMin, colMax);
        }

        if(rowMinMax == colMaxMin)
            return {rowMinMax};

        return {};
    }
};



*/
