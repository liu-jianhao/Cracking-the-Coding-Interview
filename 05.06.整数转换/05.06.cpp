class Solution {
public:
    int convertInteger(int A, int B) {
        unsigned int n = A ^ B;
        int cnt = 0;
        while (n != 0) {
            n = n & (n-1);
            ++cnt;
        }
        return cnt;
    }
};