class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int current_max_index = 0;
        int current_max = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (i == current_max_index) {
                current_max = 0;
                for (int j = i + 1; j < arr.size(); j++) {
                    if (arr[j] > current_max) {
                        current_max = arr[j];
                        current_max_index = j;
                    }
                }
            } 
            arr[i] = current_max;
        }
        
        arr[arr.size() - 1] = -1;
        return arr;
    }
};