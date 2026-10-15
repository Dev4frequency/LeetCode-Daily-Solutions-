class Solution {
public:
    void findallsubsequence(vector<int>&nums,int n,vector<int>&curr,vector<vector<int>>&ans,int i,set<vector<int>>&st){
           if (curr.size() >= 2) {
            if (st.insert(curr).second)
                ans.push_back(curr);
        }
        for(int j=i;j<n;j++){
            if (!curr.empty() && nums[j] < curr.back())
                continue;
            curr.push_back(nums[j]);
            findallsubsequence(nums,n,curr,ans,j+1,st);
            curr.pop_back();
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        findallsubsequence(nums,n,curr,ans,0,st);
        return ans;
    }
};