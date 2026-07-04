class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int sum = 0;
        vector<int> sol;
        vector<vector<int>> res;
        int i = 0;
        backtrack(candidates, target, sum, sol, res, i);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int& sum, vector<int>& sol, vector<vector<int>>& res, int i) {
        //put the "overshoot" base case here so we don't have to "undo" the addition bc we didn't add the current value yet
        if (sum > target) {
            return;
        }
        //also moved this b4 the size check bc no matter where we are if it's a valid combination
        if (sum == target) {
            res.push_back(sol);
            //sum = 0;  don't need this bc the recursion will like handle the undoing all the way up ig?
            return;
        }
        if (i == candidates.size()) {
            if (sum == target) {
            res.push_back(sol);
            }

            return;
        }

        //moving this "pick" choice first because the vector wll allocate enough memory for these large combinations, and then later doesn't have to re-allocate more and more for the "don't pick" case
        sol.push_back(candidates[i]);
        sum += candidates[i];

        backtrack(candidates, target, sum, sol, res, i);//changed from i+1 so we can reuse. it is looping over but will eventually have too big of a sum and go to the "dont pick" case

        sum-= candidates[i];
        sol.pop_back();


        backtrack(candidates, target, sum, sol, res, i+1);





    }
};