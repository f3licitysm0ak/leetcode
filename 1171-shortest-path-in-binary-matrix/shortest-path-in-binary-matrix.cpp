class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int length = grid.size(); 

        std::queue<std::pair<int, int>> queue; 
        std::vector<std::pair<int, int>> directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};


        if (grid[0][0] == 1 || grid[length - 1][length - 1] == 1) {
            return -1;
        }


        queue.push({0,0});
        grid[0][0] = 1;

        int row;
        int col;
        int len;

        while(!queue.empty()) {
            row = queue.front().first;
            col = queue.front().second;
            len = grid[row][col];
            queue.pop();

            if (row == length - 1 && col == length - 1) {
                return len;
            }



            for (const auto& d : directions) {
                int next_row = row + d.first;
                int next_col = col + d.second;

                if (next_row >= 0 && next_row < length && next_col >= 0 && next_col < length && grid[next_row][next_col] == 0) {
                    grid[next_row][next_col] = len + 1;
                    queue.push({next_row, next_col});
                }
            }
        }

        return -1;


    }
};