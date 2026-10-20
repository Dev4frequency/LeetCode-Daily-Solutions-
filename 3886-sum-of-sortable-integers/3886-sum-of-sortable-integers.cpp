class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> div;
        for(int i=1;i<=n;i++){
            if(n%i==0) div.push_back(i);
        }
        long long ans=0;
        for(int d: div){
            vector<int> temp;
            vector<int> temp1;
            bool ok=true;
            for(int i=0;i<n;i+=d){
                int maxi=nums[i];
                int mini=nums[i];
                int inc=0,dec=0;
                for(int j=i;j<i+d-1;j++){
                    if (nums[j] > nums[j + 1]) inc++;
                    if (nums[j] < nums[j + 1]) dec++;
                    maxi = max(maxi, nums[j]);
                    mini=min(mini,nums[j]);
                }
                maxi=max(maxi,nums[i+d-1]);
                mini=min(mini,nums[i+d-1]);
                if(nums[i+d-1]>nums[i]) inc++;
                else if(nums[i+d-1]<nums[i]) dec++;
                if(inc<=1){
                     temp.push_back(maxi);
                     temp1.push_back(mini);
                }
                else{
                    ok=false;
                    break;
                }
            }
            if(ok){
                int f=1;
                for(int i=0;i<temp.size()-1;i++){
                    if(temp[i]>temp1[i+1]) f=0;
                }
                if(f==1) ans+=d;
            }
        }
        return ans;
    }
};