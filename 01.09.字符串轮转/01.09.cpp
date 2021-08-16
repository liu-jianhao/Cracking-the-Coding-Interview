class Solution {
public:
    bool isFlipedString(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        s1 += s1;
        if (s1.find(s2) != -1) {
            return true;
        }

        return false;
    }
};