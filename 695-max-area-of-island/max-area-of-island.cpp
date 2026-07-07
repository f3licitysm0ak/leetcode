class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int curr_island_size = 0;
        int max_island_size = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    curr_island_size = processIsland(grid, visited, i, j);
                    if (curr_island_size > max_island_size) {
                        max_island_size = curr_island_size;
                    }
                    
                }
            }
        }

        return max_island_size;
    }
    int processIsland(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row, int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size()) {
            return 0;
        }
        if (grid[row][col] == 0 || visited[row][col]) {
            return 0;
        }

        visited[row][col] = true;
        
        return 1 + processIsland(grid, visited, row + 1, col) + processIsland(grid, visited, row - 1, col) + processIsland(grid, visited, row, col - 1) + processIsland(grid, visited, row, col + 1);
        

    }
    
};