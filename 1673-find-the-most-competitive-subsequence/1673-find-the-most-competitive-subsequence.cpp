class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int N=nums.size();
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            while(!ans.empty() && nums[i]<ans.back() && k-ans.size()<=N-i-1){
                ans.pop_back();
            }
            if (ans.size() < k) {
    ans.push_back(nums[i]);
}
        }
        return ans;
    }
};