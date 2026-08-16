class Solution {
public:
    bool prime(int n) {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        vector<int> ind;
        for (int i = 0; i < nums.size(); i++) {
            if (prime(nums[i])) {
                ind.push_back(i);
            }
        }
        return ind.back() - ind.front();
    }
};