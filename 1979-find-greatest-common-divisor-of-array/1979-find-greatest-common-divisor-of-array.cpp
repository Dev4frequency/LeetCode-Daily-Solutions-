class Solution {
public:
    int gcd(int a, int b){
        int gcd;
        for(int i = 1;i<=a && i<=b; i++){
            if(a%i == 0 && b%i==0){
                gcd = i;
            }
        }
        return gcd;
    }
    int findGCD(vector<int>& nums) {
        int min = nums[0];
        int max = nums[0];
        for(int i = 0; i<nums.size()-1; i++){
            if(min>nums[i+1]){
                min = nums[i+1];
            }
            if(nums[i+1]>max){
                max = nums[i+1];
            }
        }
        return gcd(min,max);
       
    }
};
