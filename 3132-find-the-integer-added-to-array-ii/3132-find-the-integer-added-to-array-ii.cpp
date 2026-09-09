class Solution {
public:
    bool possible(vector<int> &nums1, vector<int> &nums2, int k){
        map<int, int> mp;
        for(auto x : nums1){
            mp[(x + k)]++;
        }
        int count = 0;
        for(auto x : nums2){
            if(mp.find(x) == mp.end()) return false;
            else{
                mp[x]--;
                if(mp[x] == 0) mp.erase(x);
                count++;
            }
        }
        return count == nums2.size();
        
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {
        int ans = 1000;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        if(possible(nums1, nums2, nums2[0] - nums1[0])){
            ans = min(ans,nums2[0] - nums1[0] );
        }
        if(possible(nums1, nums2, nums2[0] - nums1[1])){
            ans = min(ans,nums2[0] - nums1[1] );
        }
        if(possible(nums1, nums2, nums2[0] - nums1[2])){
            ans = min(ans,nums2[0] - nums1[2] );
        }
        return ans;
    }
};