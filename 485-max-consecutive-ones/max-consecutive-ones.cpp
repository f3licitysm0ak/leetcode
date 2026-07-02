class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_streak = 0;
        int current_streak = 0;
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == 1) {
                current_streak++;
            } else {
                if (current_streak > max_streak) {
                    max_streak = current_streak;
                }
                current_streak = 0;
            }
            i++;
        }
        if (current_streak > max_streak) {
            max_streak = current_streak;
        }
        return max_streak;
        
    }
};