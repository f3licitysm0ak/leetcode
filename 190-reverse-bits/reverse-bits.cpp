class Solution {
public:
    int reverseBits(int n) {
        size_t bits = sizeof(n) * CHAR_BIT;
        int result = 0;

        for (int i = bits - 1; i >= 0; i--) {
            if((n >> i) & 1 == 1) {
                result += 1U << (31 - i);
            } 
        }

        return result;


    }
};