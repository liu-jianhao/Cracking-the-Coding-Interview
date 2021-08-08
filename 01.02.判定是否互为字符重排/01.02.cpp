// 解法1：两个map
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }

        unordered_map<char, int> map1;
        unordered_map<char, int> map2;
        
        for (char c : s1) {
            if (map1[c] > 0) {
                map1[c]++;
            } else {
                map1[c] = 1;
            }
        }

        for (char c : s2) {
            if (map2[c] > 0) {
                map2[c]++;
            } else {
                map2[c] = 1;
            }
        }

        return map1 == map2;
    }
};

// 解法2：字符串排序
class Solution {
public:
    bool CheckPermutation(string s1, string s2) {
        if (s1.size() != s2.size()) {
            return false;
        }
        
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};