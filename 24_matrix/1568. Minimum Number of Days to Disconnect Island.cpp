/*
https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/description/?envType=daily-question&envId=2024-08-11
*/

class Solution {
private:
    int m, n;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited)
    {
        if(i<0 || i>=m || j<0 || j>=n || visited[i][j] || grid[i][j] == 0)
            return ;

        visited[i][j] = true;

        dfs(grid, i+1, j, visited);
        dfs(grid, i-1, j, visited);
        dfs(grid, i, j+1, visited);
        dfs(grid, i, j-1, visited);
    }

    int numOfIslandUtil(vector<vector<int>>& grid)
    {
        int islands = 0;
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    dfs(grid, i, j, visited);
                    islands++;
                }
            }
        }

        return islands;
    }

public:
    int minDays(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        int islands = numOfIslandUtil(grid);
        if(islands > 1 || islands == 0)
            return 0;

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    grid[i][j] = 0;     // convert into water

                    islands = numOfIslandUtil(grid);
                    if(islands > 1 || islands == 0)
                        return 1;

                    grid[i][j] = 1;     // convert back to land
                }
            }
        }

        return 2;

    }
};
