class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        std::stack<std::pair<int, int>> stack;
        int og = image[sr][sc];
        if (og == color) {
            return image;
        }
        stack.push(std::pair(sr, sc));
        while (!stack.empty()) {
            //color top element and pop it off
            //for each direction: if valid index -> if == og num -> push onto stack
            int row = stack.top().first;
            int col = stack.top().second;
            stack.pop();
            image[row][col] = color;
            if (row - 1 > -1 && image[row - 1][col] == og) {
                stack.push(std::pair(row-1, col));
            }
            if (row + 1 < image.size() && image[row + 1][col] == og) {
                stack.push(std::pair(row+1, col));
            }
            if (col - 1 > -1 && image[row][col - 1] == og) {
                stack.push(std::pair(row, col-1));
            }
            if (col + 1 < image[0].size() && image[row][col + 1] == og) {
                stack.push(std::pair(row, col+1));
            }


        }

        return image;
    }
};