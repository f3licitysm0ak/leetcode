class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();

        if (obstacleGrid[m-1][n-1] == 1 || obstacleGrid[0][0] == 1) {
            return 0;
        }
        
        if (m == 1 && n == 1) {
            return obstacleGrid[0][0] == 1 ? 0 : 1;
        }

        vector<vector<long>> grid(m, vector<long>(n, 0));
        grid[m-1][n-1] = 1;

        int sum = 0;
        for(int i = m-1; i > -1; i--) {
            for (int j = n-1; j > -1; j--) {
                sum = 0;
                if (i == m-1 && j == n-1) {
                    grid[i][j] = 1;
                    continue;
                }
                if (obstacleGrid[i][j] == 1) {
                    //we just hit an obstacle
                    grid[i][j] = sum;
                    continue;
                }

                if (j+1 < n) {
                    sum += grid[i][j+1];
                }
                if (i+1 < m) {
                    sum += grid[i+1][j];
                }

                grid[i][j] = sum;

            }

        }

        return (int)grid[0][0];
        


    }
};