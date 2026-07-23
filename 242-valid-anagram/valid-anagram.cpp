class Solution {
public:
    bool isAnagram(string s, string t) {
        //again make map of both and check if all frequencies match 
        map<char, int> s_map;
        map<char, int> t_map;

        for (char c : s) {
            if (s_map.contains(c)) {
                s_map[c]++;
            } else {
                s_map[c] = 1;
            }
        }
        for (char c : t) {
            if (t_map.contains(c)) {
                t_map[c]++;
            } else {
                t_map[c] = 1;
            }
        }

        if (s_map.size() != t_map.size()) {
            return false;
        }
        for (const auto& [key, value] : s_map) {
            if (value != t_map[key]) {
                return false;
            }
        }

        return true;  
    }
};