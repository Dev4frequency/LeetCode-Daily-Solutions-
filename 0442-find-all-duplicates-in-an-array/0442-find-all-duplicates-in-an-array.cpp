class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        sort(nums.begin(), nums.end());  
        vector<int> ans;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == nums[i - 1]) {
                if (ans.empty() || ans.back() != nums[i]) {
                    ans.push_back(nums[i]);
                }
            }
        }

        return ans;
    }
};