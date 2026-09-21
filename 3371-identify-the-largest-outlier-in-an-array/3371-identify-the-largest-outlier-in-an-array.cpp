class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        int len = nums.size(), ans = INT_MIN, total = 0;
        vector<int> sumSubtractItself(len);
        unordered_map<int,int> freq;
        for(int i = 0; i < len; i++){
            total += nums[i];
            freq[nums[i]]++;
        } 
        for(int i = 0; i < len; i++){
            sumSubtractItself[i] = total - nums[i];
            if(sumSubtractItself[i] % 2 != 0)
                continue;
            int candidates = sumSubtractItself[i] / 2;
            if(freq.count(candidates) && candidates != nums[i])
                ans = max(ans, nums[i]);
            if(freq.count(candidates) && freq[candidates] > 1)
                ans = max(ans, nums[i]);
        }
        return ans;
    }
};