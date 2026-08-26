class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=100004;
         vector<int> s(n);
         s[0]=s[1]=1;
         for(int i=2;i<=316;i++)
         {
            if(!s[i])
            {
                for(int j=i*i;j<n;j+=i)
                {
                    s[j]=1;
                }
            }
         }
         int ans=0;
         for(int i=0;i<nums.size();i++)
         {
            int j=nums[i];
            if(i&1)
            {
                while(!s[j++]) ans++;
            }
            else while(s[j++]) ans++;
         }
         return ans;
    }
};