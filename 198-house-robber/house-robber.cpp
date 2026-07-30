class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> money;
        money.push_back(nums[0]);

        int temp_max;
        int greatest_before;
        for (int i = 1; i < nums.size(); i++) {
            if (i-2 < 0) {
                greatest_before = 0;
            } else {
                greatest_before = money[i-2];
            }
            temp_max = std::max(nums[i] + greatest_before, money[i-1]);
            money.push_back(temp_max);
        }

        return money.back();

    }
};