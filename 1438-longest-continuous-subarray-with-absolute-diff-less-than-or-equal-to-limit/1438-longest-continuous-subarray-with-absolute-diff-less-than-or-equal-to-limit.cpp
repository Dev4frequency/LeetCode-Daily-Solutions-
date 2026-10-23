class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int s=0,e=0;
        int maxi_size=0;
        priority_queue<pair<int,int>>mxp;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>mnp;
        while(e<nums.size()){
            mnp.push({nums[e],e});
            mxp.push({nums[e],e});
            while(mxp.top().first-mnp.top().first>limit){
                s=min(mnp.top().second,mxp.top().second)+1;
                while(mnp.top().second<s){
                    mnp.pop();
                }
                while(mxp.top().second<s){
                    mxp.pop();
                }
            }
            maxi_size=max(maxi_size,e-s+1);
            e++;
        }
        return maxi_size;
    }
};