class Solution {
public:
    bool canChoose(vector<vector<int>>& groups, vector<int>& nums) {
        int idx = 0;
        for (auto& group : groups) {
            bool found = false;
            while (idx + group.size() <= nums.size()) {
                bool match = true;
                for (int i = 0; i < group.size(); ++i) {
                    if (nums[idx + i] != group[i]) {
                        match = false;
                        break;
                    }
                }
                if (match) {
                    found = true;
                    idx += group.size();
                    break;
                }
                ++idx;
            }
            if (!found) return false;
        }
        return true;
    }
};
