class Solution {
public:
    bool isValid(string s) {
       vector<char> stack;
       int top = -1;
       map<char, char> map = {{')', '('}, {']', '['}, {'}', '{'}};
       for (char c : s) {
        if (c == '(' || c == '['  || c == '{') {
            stack.push_back(c);
            top++;
        } else {
            if (!stack.empty() && stack[top] == map[c]) {
                stack.pop_back();
                top--;
            } else {
                return false;
            }
        }
       }

       if (!stack.empty()) {
        return false;
       }

       return true;
    }
};