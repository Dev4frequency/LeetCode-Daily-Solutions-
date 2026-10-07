class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& nums) {
        set<int>pre;
        vector<int>ans;
        set<int>suf;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++) pre.insert(nums[j]);
            for(int k=i+1;k<n;k++) suf.insert(nums[k]);
        int x=pre.size();
            int y=suf.size();
            ans.push_back(x-y);
              pre.clear();
            suf.clear();
        }
    return ans;
    }
};