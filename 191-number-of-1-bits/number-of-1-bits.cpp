class Solution {
public:
    int hammingWeight(int n) {
        int result = 0;
        //uint32_t num = static_cast<uint32_t>(n);
        int num = n;
        while (num > 0) {
            if ((num & 1) == 1) {
                result++;
            }
            num >>= 1; //chop off the last bit
        }

        return result;  
    }
};