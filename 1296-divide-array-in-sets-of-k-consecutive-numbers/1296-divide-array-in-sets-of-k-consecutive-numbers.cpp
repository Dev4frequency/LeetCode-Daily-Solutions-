
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n = nums.size();
        if (n % k != 0) return false;

        map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        for (auto& [num, count] : freq) {
            if (count > 0) {
                for (int i = 1; i < k; ++i) {
                    int next = num + i;
                    if (freq[next] < count) {
                        return false;
                    }
                    freq[next] -= count;
                }
            }
        }

        return true;
    }
};