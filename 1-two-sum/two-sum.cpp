class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> visited_indexes;
        int current_complement; 
        for (int i = 0; i < nums.size() ; i++){
            current_complement = target - nums[i];
            if (visited_indexes.contains(current_complement)) {
                return std::vector<int>({visited_indexes[current_complement], i});
            }
            visited_indexes[nums[i]] = i;
        }

        return {};

    }
};