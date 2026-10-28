class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
         bool m = false;
        for (int i = 0; i < size(num); ++i) {
            int d = num[i] - '0';
            if (change[d] < d) {
                if (m) {
                    break;
                }
            } else if (change[d] > d) {
                num[i] = '0' + change[d];
                m = true;
            }
        }
        return num;
    }
};