class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int num_islands = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1' && !visited[i][j]) {
                    markIsland(grid, visited, i, j);
                    num_islands++;
                }
            }
        }
        return num_islands;
        
    }
    void markIsland(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return;
        }
        if (grid[row][col] == '0' || visited[row][col]) {
            return;
        }

        visited[row][col] = true;

        markIsland(grid, visited, row-1, col);
        markIsland(grid, visited, row+1, col);
        markIsland(grid, visited, row, col-1);
        markIsland(grid, visited, row, col+1);
    }

};