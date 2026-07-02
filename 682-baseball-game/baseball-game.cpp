class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> record;
        int top = -1;
        for(string op : operations) {
            if (op == "+") {
                record.push_back(record[top] + record[top - 1]);
                top++;
            } else if (op == "D") {
                int num = record[top] * 2;
                record.push_back(num);
                top++;
            } else if (op == "C") {
                record.pop_back();
                top--;
            } else {
                record.push_back(stoi(op));
                top++;
            }
        }

        int sum = 0;
        for (int num : record) {
            sum += num;
        }

        return sum;

        
    }
};