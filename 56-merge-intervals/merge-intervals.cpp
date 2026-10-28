class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        std::sort(intervals.begin(), intervals.end());
        vector<vector<int>> result;
        int j = 1;

        for (int i = 0; i < intervals.size();) {
            int start = intervals[i][0];
            int latest_end = intervals[i][1];
            for (j = i + 1; j < intervals.size(); j++) {
                int curr_start = intervals[j][0];
                int curr_end = intervals[j][1];
                if (curr_end <= latest_end) {
                    //continue, don't change the latest end
                } else if (curr_end > latest_end && curr_start <= latest_end) {
                    //continue, do change the latest end
                    latest_end = curr_end; 
                } else {
                    break;
                }
            }

            result.push_back({start, latest_end});
            i = j;//go to the next unmerged one 
        }

        return result;
    }
};