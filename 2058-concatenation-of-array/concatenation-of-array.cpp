class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> result(nums.size() * 2);
        for (int i = 0; i < result.size(); i++) {
            if (i < nums.size()) {
                result[i] = nums[i];
            } else {
                result[i] = nums[i-nums.size()];
            }
            
            
        }
        return result;
        
    }
};