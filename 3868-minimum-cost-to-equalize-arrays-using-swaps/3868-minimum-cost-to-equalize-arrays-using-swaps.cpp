class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int>mpp , mpp1 , mpp2;
        int n1 = nums1.size();
        int n2 = nums2.size();

        for(int i=0; i<n1; i++){
            mpp[nums1[i]]++;
            mpp1[nums1[i]]++;
        }

        for(int i=0; i<n2; i++){
            mpp[nums2[i]]++;
            mpp2[nums2[i]]++;
        }

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        if(nums1 == nums2){
            return 0;
        }

        for(auto& it:mpp){
            int num = it.second;
            if(num & 1) return -1;
        }

        int ans = 0;

        for(auto& it:mpp1){
            int val = it.first;
            int num = it.second;

            int total = mpp[val] / 2;

            if(num > total){
                ans += (num - total);
            }
        }

        return ans;
    }
};