class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        bool noRottenOranges = true;
        bool noFreshOranges = true;
        std::queue<std::pair<int,int>> queue;
        int totalFreshOranges = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    noRottenOranges = false;
                    queue.push(std::pair(i,j));
                    
                    
                }
                if (grid[i][j] == 1) {
                    noFreshOranges = false;
                    totalFreshOranges++;
                }
            }
        }

        if (noRottenOranges && noFreshOranges) {
            return 0;
        }

        if (noRottenOranges){
            return -1;
        }

        
        int minutes = 0;

        
        int size_snapshot = 0;

        while(!queue.empty()) {
            bool noMoreRotten = true;
            size_snapshot = queue.size();
            for (int i = 0; i < size_snapshot; i++) {
                int row = queue.front().first;
                int col = queue.front().second;
                queue.pop();

                if (row-1 > -1 && grid[row-1][col] == 1) {
                    grid[row-1][col] = 2;
                    totalFreshOranges--;
                    queue.push(std::pair(row-1,col));
                    noMoreRotten = false;
                }
                if (row+1 < grid.size() && grid[row+1][col] == 1) {
                    grid[row+1][col] = 2;
                    totalFreshOranges--;
                    queue.push(std::pair(row+1,col));
                    noMoreRotten = false;
                }
                if (col-1 > -1 && grid[row][col-1] == 1) {
                    grid[row][col-1] = 2;
                    totalFreshOranges--;
                    queue.push(std::pair(row,col-1));
                    noMoreRotten = false;
                }
                if (col+1 < grid[0].size() && grid[row][col+1] == 1) {
                    grid[row][col+1] = 2;
                    totalFreshOranges--;
                    queue.push(std::pair(row,col+1));
                    noMoreRotten = false;
                }



            }

            if (!noMoreRotten) {
                minutes++;
            }
            


            
        }

        if (totalFreshOranges > 0) {
            return -1;
        }
        return minutes;

    }
};