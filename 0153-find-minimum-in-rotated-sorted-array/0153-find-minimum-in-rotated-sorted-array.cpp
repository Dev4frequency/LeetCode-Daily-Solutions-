class Solution {
public:
    int findMin(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        while(nums[i]<nums[(n+i+1)%n]){
            i++;
        }
        return nums[(n+i+1)%n];
    }
};