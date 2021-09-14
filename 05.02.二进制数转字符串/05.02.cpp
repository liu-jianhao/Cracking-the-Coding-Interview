class Solution {
public:
    string printBin(double num) {
        string res = "0.";
        while (num != 0) {
            num *= 2;
            if (num >= 1) {
                res += "1";
                num -= 1;
            } else {
                res += "0";
            }

            if (res.size() > 32) {
                return "ERROR";
            } 
        }
        return res;
    }
};