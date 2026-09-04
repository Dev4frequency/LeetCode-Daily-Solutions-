class Solution {
public:
    int findMaxK(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if (nums[nums.size()-1] < 0 || nums.size() == 0 || nums[0] > 0) {
            return -1;
        }
        int index = 0;
        int curr_num = nums[nums.size()-1];
        while (curr_num > 0){
            for (int i = 0; i < nums.size()-1; i++){
                if (nums[i] == -curr_num) return curr_num;
                if (-curr_num < nums[i]) break;
            }
            if (index >= nums.size()) break;
            index++;
            curr_num = nums[nums.size()-1-index];
        }
        return -1;
    }
};