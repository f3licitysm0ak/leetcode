class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        vector<int> sol;
        vector<vector<int>> result;

        backtrack(i, n, sol, result, nums);
        return result;
        
    }

    void backtrack(int i, int n, vector<int>& sol, vector<vector<int>>& result, const vector<int>& nums) {
        if (i == n) {
            result.push_back(sol);
            return;
        }

        backtrack(i + 1, n, sol, result, nums);

        sol.push_back(nums[i]);
        backtrack(i + 1, n, sol, result, nums);
        sol.pop_back();

    }
};