class Solution {
public:
    vector<int> recoverArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size() / 2;

        for (int start = 1; start < nums.size(); ++start) {
            int potential_k = (nums[start] - nums[0]) / 2;

            if (potential_k <= 0 || (nums[start] - nums[0]) % 2 != 0) {
                continue;
            }

            unordered_map<int, int> count;
            for (int num : nums) {
                count[num]++;
            }

            bool valid = true;
            vector<int> tempArray;

            for (int num : nums) {
                if (count[num] == 0) continue;
                if (count[num + 2 * potential_k] == 0) {
                    valid = false;
                    break;
                }
                tempArray.push_back(num + potential_k);
                count[num]--;
                count[num + 2 * potential_k]--;
            }

            if (valid) {
                return tempArray;
            }
        }

        return {};
    }
};