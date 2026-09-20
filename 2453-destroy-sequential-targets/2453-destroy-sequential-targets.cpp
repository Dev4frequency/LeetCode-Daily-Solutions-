class Solution {
public:
    int destroyTargets(vector<int>& nums, int space) {
        int n = nums.size();
        int c =0;
        map<int,int>map;
        for(int i=0;i<n;i++)
        {
            map[nums[i]%space]++;
            c = max(map[nums[i]%space],c);
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(map[nums[i]%space] == c)
            ans = min(nums[i],ans);
        }
        return ans;
    }
};