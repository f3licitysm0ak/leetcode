#include <vector>
#include <algorithm>

class Solution {
public:
    bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
        // Sort intervals based on their start time (index 0)
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });

        // Check for overlaps: if the previous end time is greater than the current start time
        for (size_t i = 1; i < intervals.size(); i++) {
            if (intervals[i - 1][1] > intervals[i][0]) {
                return false;
            }
        }

        return true;
    }
};