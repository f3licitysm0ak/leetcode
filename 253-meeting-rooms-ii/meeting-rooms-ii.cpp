#include <vector>
#include <algorithm>

class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        std::vector<int> starts;
        std::vector<int> ends;
        
        // Extract start (index 0) and end (index 1) times
        for (const auto& interval : intervals) {
            starts.push_back(interval[0]);
            ends.push_back(interval[1]);
        }

        std::sort(starts.begin(), starts.end());
        std::sort(ends.begin(), ends.end());

        int curr_start = 0;
        int curr_end = 0;

        int curr_count = 0;
        int max_count = 0;

        while (curr_start < intervals.size()) {
            if (starts[curr_start] < ends[curr_end]) {
                curr_count++;
                if (curr_count > max_count) {
                    max_count = curr_count;
                }
                curr_start++;
            } else {
                curr_count--;
                curr_end++;
            }
        }

        return max_count;
    }
};