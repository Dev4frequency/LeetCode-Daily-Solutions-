class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> res;
        string s = "123456789";

        for (int len = 2; len <= 9; len++) {
            for (int start = 0; start + len <= 9; start++) {

                string cur = s.substr(start, len);
                int num = stoi(cur);

                if (num >= low && num <= high)
                    res.push_back(num);
            }
        }

        return res;
    }
};