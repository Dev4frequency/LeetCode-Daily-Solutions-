class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
       vector<int>ones;
       vector<int>twos;
       for(int i=0;i<nums.size();i++){
           if(nums[i]==1)
               ones.push_back(i);
           else if(nums[i]==2)
               twos.push_back(i);
       }
        int n=ones.size();
        int m=twos.size();
        int minv=23434;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(minv>abs(ones[i]-twos[j])){
                   minv=abs(ones[i]-twos[j]);
                }
            }
        }
        if(minv==23434)
        return -1;
        else
        return minv;
            
    }
};