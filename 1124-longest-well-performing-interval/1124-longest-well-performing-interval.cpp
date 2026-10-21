class Solution {
public:
    int longestWPI(vector<int>& hours) {

        vector<int> p = {0};
        unordered_map<int, int> m;

        m[0] = -1;

        for (int i = 0; i < hours.size(); i++) {
            int hour = hours[i];
            int sum = p[p.size() - 1];

            if (hour > 8) {
                sum++;
            } else {
                sum--;
            }

            p.push_back(sum);

            if (!m.contains(sum)) {
                m[sum] = i;
            }
        }

        int max = 0;
        for (int i = 1; i < p.size(); i++) {
            int sum = p[i];

            if (sum > 0) {
                sum = 0;
            } else {
                sum--;
            }

            if (m.contains(sum)) {
                int count = i - m[sum] - 1;
                if (count > max) {
                    max = count;
                }
            }
        }

        return max;
    }
};