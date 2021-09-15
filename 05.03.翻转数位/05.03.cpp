class Solution {
public:
    int reverseBits(int num) {
        bitset<32> b(num);
        int i = 0;
        int j = 0;
        int res = 0;
        int count = 0;
        while (j < 32) {
            if (b[j] == 0) {
                ++count;
            }
            while (i <= j && count > 1) {
                if (b[i] == 0) {
                    --count;
                }
                ++i;
            }
            res = max(res, j-i+1);
            ++j;
        }
        return res;
    }
};