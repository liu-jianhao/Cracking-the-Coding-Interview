class Solution {
public:
    bool oneEditAway(string first, string second) {
        if (first.size() > second.size()) {
            string tmp = first;
            first = second;
            second = tmp;
        }
        if (second.size() - first.size() > 1) {
            return false;
        }

        for (int i = 0; i < first.size(); ++i) {
            if (first[i] != second[i]) {
                if (first.substr(i) == second.substr(i+1)) {
                    return true;
                }
                if (first.substr(i+1) == second.substr(i+1)) {
                    return true;
                }
                return false;
            }
        }

        return true;
    }
};