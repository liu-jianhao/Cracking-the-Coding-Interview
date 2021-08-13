class Solution {
public:
    string compressString(string S) {
        int i = 0;
        string res;
        while (i < S.size()) {
            int j = i;
            while (j < S.size() && S[i] == S[j]) {
                ++j;
            }
            res += S[i];
            res += to_string(j-i);
            i = j;
        }

        if(res.size() >= S.size()) {
            return S;
        }
        return res;
    }
};