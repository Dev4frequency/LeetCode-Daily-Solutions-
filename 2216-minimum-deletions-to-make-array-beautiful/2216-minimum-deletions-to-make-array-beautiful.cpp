class Solution {
public:
    int minDeletion(vector<int>& nums) {
        int deletions = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if ((i - deletions) % 2 == 0 && nums[i] == nums[i + 1]) {
                deletions++; 
            }
        }
        if ((n - deletions) % 2 != 0) {
            deletions++;
        }
        return deletions;
    }
};