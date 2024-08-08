/*
https://leetcode.com/problems/spiral-matrix-iii/description/?envType=daily-question&envId=2024-08-08
*/

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> directions = {
            {0, 1},     // East
            {1, 0},     // South
            {0, -1},    // West
            {-1, 0}     // North
        };

        int dir = 0;
        int steps = 0;
        vector<vector<int>> res;
        res.push_back({rStart, cStart});

        while(res.size() < rows*cols) {
            if(dir == 0 || dir == 2)
                steps++;

            for(int count=0; count<steps; count++) {
                rStart += directions[dir][0];
                cStart += directions[dir][1];

                if(rStart>=0 && rStart<rows && cStart>=0 && cStart<cols)
                    res.push_back({rStart, cStart});
            }

            dir = (dir+1)%4;
        }

        return res;
    }
};
