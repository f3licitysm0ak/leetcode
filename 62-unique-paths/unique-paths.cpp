class Solution {
public:
    int uniquePaths(int m, int n) {
        if (m == 1 || n == 1) {
            return 1;
        } 
        vector<vector<int>> grid(m, vector<int>(n, 0));

        grid[m-1][n-1] = 1;
        int sum = 0;
        
        for(int i = m-1; i > -1; i--) {
            for (int j = n-1; j > -1; j--) {
                sum = grid[i][j];
                if (j+1 < n) {
                    sum += grid[i][j+1];
                }
                if (i+1 < m) {
                    sum += grid[i+1][j];
                }
                grid[i][j] = sum;
            }
        }

        return grid[0][0];
    }
};