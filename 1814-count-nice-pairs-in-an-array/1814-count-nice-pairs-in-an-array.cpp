class Solution {
public:
    int reverse(int n){
        int rev = 0;
        while(n>0){
            rev = rev * 10 + n %10;
            n /= 10;  
        }
        return rev;
    }
    
    int countNicePairs(vector<int>& nums) {
        unordered_map<int, int> mp;
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            int reversedNum = reverse(nums[i]);
            int diff = nums[i] - reversedNum;

            ans = (ans + mp[diff]) % 1000000007;
            mp[diff]++;
        }
        return ans;
    }
};