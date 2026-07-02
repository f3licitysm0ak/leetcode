class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if (nums.empty()) {
            return 0;
        }
        int curr = 0;
        int back = nums.size() - 1;
        if (nums[back] == val) {
            back--;
        }

        while (curr <= back) {
            if (nums[curr] == val) {
                int temp = nums[back];
                nums[back] = nums[curr];
                nums[curr] = temp;
                back--;

            } else {
                curr++;
            }
        }

        return curr;
    }
};