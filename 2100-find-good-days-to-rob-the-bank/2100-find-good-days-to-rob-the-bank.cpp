class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<int> result;
        if (time == 0) {
            for (int i = 0; i < n; i++) {
                result.push_back(i);
            }
            return result;
        }
        vector<int> nonIncreasing(n, 0);
        vector<int> nonDecreasing(n, 0);
        for (int i = 1; i < n; i++) {
            if (security[i] <= security[i - 1]) {
                nonIncreasing[i] = nonIncreasing[i - 1] + 1;
            }
        }
        for (int i = n - 2; i >= 0; i--) {
            if (security[i] <= security[i + 1]) {
                nonDecreasing[i] = nonDecreasing[i + 1] + 1;
            }
        }
        for (int i = time; i < n - time; i++) {
            if (nonIncreasing[i] >= time && nonDecreasing[i] >= time) {
                result.push_back(i);
            }
        }
        return result;
    }
};