class Solution {
public:
    int findClosestNumber(vector<int>& nums) {

        int num=nums[0];

        for(int i=0;i<nums.size();i++){

            if(abs(nums[i])<abs(num)||
            abs(nums[i])==abs(num)&&nums[i]>num){

                num=nums[i];
                
            }         
        }
        return num;
    }
};