class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans=0;
        long long concat;
        short int i,j;
        int temp,digit;
        char count;
        for(i=0,j=nums.size()-1;i<j || ((nums.size()&1) && i<=j);i++,j--)
        {
            if(i==j)
            {
                ans=ans+nums[i];
            }
            else
            {
            concat=nums[i];
            temp=nums[j];
            count=0;
            digit=1;
            while(temp)
            {
                count++;
                digit=digit*10;
                temp=temp/10; 
            }
            concat=concat*digit + nums[j];

            ans=ans+concat;
            }
        }
        return ans;

    }
};