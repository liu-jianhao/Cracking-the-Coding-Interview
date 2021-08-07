class Solution {
public:
    bool isUnique(string astr) {
        std::unordered_set<char> uset;
        for (char c : astr) {
            if (uset.count(c) > 0) {
                return false;
            }
            uset.insert(c);
        }
        return true;
    }
};