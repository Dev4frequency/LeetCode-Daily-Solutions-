class Solution {
public:
    unordered_set<int>s;
    long long splitArray(vector<int>& nums) {

       int n=nums.size();
       if(n==0) return 0;
       vector<bool>seive(n+5,true);
       seive[0]=false;
       seive[1]=false;

       for(int i=2;i*i<=n+5;i++)
       {
            if(seive[i])
            {
                for(int j=i*i;j<n+5;j+=i)
                {
                    seive[j]=false;
                }
            }
       }

        long s1=0,s2=0;

        for(int i=0;i<nums.size();i++)
        {
            if(seive[i])
            {
                s1+=nums[i];
            }
            else{
                s2+=nums[i];
            }
        }


        return abs(s1-s2);
       
    }
};