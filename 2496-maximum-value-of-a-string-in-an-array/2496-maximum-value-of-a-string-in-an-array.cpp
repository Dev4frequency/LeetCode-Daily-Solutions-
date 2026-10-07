class Solution {
public:
    bool isNum(string str) {
        for (int i = 0; i < str.length(); i++) {
            if (!isdigit(str[i])) {
                return false;
            }
        }
        return true;
    }

    int maximumValue(vector<string>& strs) {
        int maxval = INT_MIN;

        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];

            if (isNum(temp)) {
                maxval = max(maxval, stoi(temp));
            } else {
                maxval = max(maxval, (int)temp.length());
            }
        }

        return maxval;
    }
};