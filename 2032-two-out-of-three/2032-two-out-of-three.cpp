class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        set<int> s1(nums1.begin(),nums1.end());
        set<int> s2(nums2.begin(),nums2.end());
        set<int> s3(nums3.begin(),nums3.end());
        vector<int> arr;
        for(auto it:s1) arr.push_back(it);
        for(auto it:s2) arr.push_back(it);
        for(auto it:s3) arr.push_back(it);
        map<int,int> mpp;

        for(auto it:arr){
            mpp[it]++;
        }
        vector<int> arr2;
        for(auto it:mpp){
            if(it.second>=2) arr2.push_back(it.first);
        }
        return arr2;

    }
};