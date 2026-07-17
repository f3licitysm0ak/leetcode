class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        std::map<int, std::vector<int>> map;
        std::set<int> safe_nodes;
        int first;
        int second;
        for(int i = 0; i < prerequisites.size(); i++) {
            first = prerequisites[i][0];
            second = prerequisites[i][1];
            if (!map.contains(second)) {
                map[second]={};
            }
            if (first == second) {
                return false;
            }
            map[second].push_back(first);
        }

        std::set<int> current_path = {};

        for(const auto [key, value] : map) {
            bool result = canFinishHelper(key, map, current_path, safe_nodes);
            if (!result) {
                return false;
            }
        }

        return true;

    }

    bool canFinishHelper(int course, std::map<int, std::vector<int>>& map, std::set<int>& current_path, std::set<int>& safe_nodes) {
        if (safe_nodes.contains(course)) {
            return true;
        }
        if (current_path.contains(course)) {
            return false;
        }

        current_path.insert(course);

        for (int neighbor : map[course]) {
            if (!canFinishHelper(neighbor, map, current_path, safe_nodes)) {
                return false;
            }
        }

        //if we made it this far it means we checked all neighbors and none of them led to a cycle
        safe_nodes.insert(course);

        current_path.erase(course);

        return true;

    }
};
