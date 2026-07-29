class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> mem(text1.length() + 1, vector<int>(text2.length() + 1, 0));

        //starting at [1][1] so we dont have do to out of bounds check every time, and it's 1 bigger in length and width. that way we store the match result of text1[i-1] and text2[j-1] in [i][j].
        for (int i = 1; i < mem.size(); i++) {
            for (int j = 1; j < mem[0].size(); j++) {
                if (text1[i-1] == text2[j-1]) {
                    mem[i][j] = mem[i-1][j-1] + 1;
                } else {
                    mem[i][j] = max(mem[i-1][j], mem[i][j-1]);
                }
            }
        }

        return mem[text1.length()][text2.length()];
        
    }
};