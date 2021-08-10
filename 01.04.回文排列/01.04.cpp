class Solution {
public:
    bool canPermutePalindrome(string s) {
        std::unordered_map<char, int> m;
        int count = 0;
        for (char c : s) {
            m[c]++;
            if (m[c] % 2 == 1) {
                count++;
            } else {
                count--;
            }
        }
        return count <= 1;
    }
};